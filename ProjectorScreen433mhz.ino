/*
  Small program to catch a 12v signal from a projector
  and lower a HomeGear Motorized Screen. 
  Values used were read from the HomeGear remote.
  Modify code to read the 433mhz signals and change
  accordingly for your screen commands.
  Arduino Nano was used.
  
  https://github.com/sui77/rc-switch/
  https://github.com/ndoty/
*/

#include <RCSwitch.h>

RCSwitch RF = RCSwitch();

const byte ledPin = 13; //Using Pin D13 to turn on and off LED
const byte mhzPin = 10; //Using Pin D10 to send 433mhz signals to screen
const byte interruptPin = 2; //Nano only works on pin D2 or D3 let's use D2
const long lowerMhz = 2981764; //HomeGear Remote sent this command to lower so let's use it in the code
const long raiseMhz = 2981761; //HomeGear Remote sent this command to raise so let's use it in the code
const byte bitLength = 24; //HomeGear Remote used a 24 bit length so let's use it in the code
const long pulseRate = 384; //HomeGear pulse rate was 384ms so let's use it in the code
byte state = 2; // Set to 2 intitialy so both raise or lower will work on boot

void setup() {
  RF.enableTransmit(mhzPin); //Using Pin #10 (D7) to send 433mhz signals to screen
  RF.setProtocol(1); //HomeGear Screen uses protocol 1 so set it

  pinMode(ledPin, OUTPUT); //Set pin mode
  pinMode(interruptPin, INPUT); //Set pin mode

  attachInterrupt(digitalPinToInterrupt(interruptPin), move, CHANGE); //Wait for signal change from projector

  delay(1000); //Give some time

  move(); //Set state right away to make sure it operates properly
}

void loop() {
}

void move() {
  delay(1000); //Give pin time to stablalize

  int status = digitalRead(interruptPin);

  delay(1000); //We Read it now wait a second before we act

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

