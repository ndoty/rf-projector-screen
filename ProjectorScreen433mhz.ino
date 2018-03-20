/*
  Small program to catch a 12v signal from a projector
  and raise or lower a HomeGear Motorized Screen. 
  Values used were read from the HomeGear remote.
  Modify code to read the 433mhz signals and change
  accordingly for your screen commands.
  Arduino Nano was used.
  
  Special thanks to sui77 for the RC Switch library
  https://github.com/sui77/rc-switch/
  
  This Repo
  https://github.com/ndoty/
*/

#include <RCSwitch.h>

RCSwitch RF = RCSwitch();

// Configurable
const long lowerMhz = 2981764; //HomeGear Remote sent this command to lower so let's use it in the code
const long raiseMhz = 2981761; //HomeGear Remote sent this command to raise so let's use it in the code
const byte bitLength = 24; //HomeGear Remote used a 24 bit length so let's use it in the code
const long pulseRate = 384; //HomeGear pulse rate was 384ms so let's use it in the code
const byte protocal = 1; //HomeGear protocol is 1 so let's use it in the code

// Don't Modify unless you know what you are doing
const byte ledPin = 13; //Using Pin D13 to turn on and off LED
const byte mhzPin = 10; //Using Pin D10 to send 433mhz signals to screen
const byte interruptPin = 2; //Nano only works on pin D2 or D3 let's use D2
byte state = 2; // Set to 2 intitialy so both raise or lower will work on boot

void setup() {
  RF.enableTransmit(mhzPin); //Set RF transmit pin (D10)
  RF.setProtocol(protocol); //Hset RF protocal

  pinMode(ledPin, OUTPUT); //Set pin mode to power for LED
  pinMode(interruptPin, INPUT); //Set pin mode to input for interrupt pin

  attachInterrupt(digitalPinToInterrupt(interruptPin), move, CHANGE); //Wait for signal change from projector

  delay(500); //Give some time

  move(); //Set state right away to make sure it operates properly
}

void loop() {
}

void move() {
  delay(500); //Give pin time to stablalize

  int status = digitalRead(interruptPin);

  delay(500); //We Read it now wait a second before we act

  switch (status) {
    case LOW: //No Signal
      raiseScreen(); //Raise
      break;
    case HIGH: //12v Trigger Signal
      lowerScreen(); //Lower
      break;
  }
}

void raiseScreen() {
  if (state != 0 ) { //Only run this once if we are already up. Nano runs functions multiple times for some reason
    digitalWrite(ledPin, HIGH); //Visual LED for signal
    RF.send(raiseMhz, bitLength); //Send Command
    delay(1);
    RF.send(raiseMhz, bitLength); //Send again
    delay(1);
    RF.send(raiseMhz, bitLength); //Send again
    digitalWrite(ledPin, LOW); //Turn off Visual LED for Signal
  }
  state = 0; //Set flag for up
}

void lowerScreen() {
  if (state != 1) {  //Only run this once if we are already down. Nano runs functions multiple times for some reason
    digitalWrite(ledPin, HIGH); //Visual LED for signal
    RF.send(lowerMhz, bitLength); //Send Command
    delay(pulseRate);
    RF.send(lowerMhz, bitLength); //Send again
    delay(pulseRate);
    RF.send(lowerMhz, bitLength); //Send again
    digitalWrite(ledPin, LOW); //Turn off Visual LED for Signal
  }
  state = 1; //set flag for down
}

