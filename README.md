# Send a 433mhz signal to a HomeGear projector screen from a 12v Projector trigger
This was designed and coded to work for [Homegear 110” HD Motorized 16:9 Projector Screen W/ Remote Control](http://amzn.to/2ppoBB0). Codes in ProjectorScreen433mhz.ino are directly read from the remote that comes with the Homegear screen. If you purchase a screen other than [this one](http://amzn.to/2ppoBB0), you can still read the codes as long as you can verify your screen operates on 433mhz. This guide will explain how to read 433mhz codes and set them in the code.

## Software Required
* Arduino IDE - https://www.arduino.cc/en/Main/Software (Thank you Arduino)
* CH340 Driver - http://bit.ly/2pMF4in (Thank you Elegoo) or use CH340 Driver.zip in this repo
* RC Swtich Arduino Library - https://github.com/sui77/rc-switch/ (Thank you sui77)

## Hardware Required: (Amazon Affiliate links below, use the links to support me)
* Arduino Nano Clone - http://amzn.to/2FWJVos (requires special driver, see CH340 Driver above)
* 433mhz kit - http://amzn.to/2FXDhhM (TX required RX if you need to read in new codes for your screen)
* 12v to 3v - http://amzn.to/2DFVkHp (Nano can only take 5v. 3v is enough to trigger pin HIGH)
* 12v Trigger wire - https://a.co/4kLpvYh (Must have 1/8" style 12v tirgger port on you projector)
* Misc wires and cables to complete install. (Mini B USB cable, Jumper wires, other wires)

### Install Arduino IDE
Head over to https://www.arduino.cc/en/Main/Software and install the Arduino IDE for your Operating System. Windows, MAC, Linux are all suported.

### Install CH340 Driver
Head over to http://bit.ly/2pMF4in or use CH340 Driver.zip from this repo.
Select the files for your Operating System to install the Driver. This will allow the Arduino IDE to flash the Arduino Nano Clone.

### Wire up 433mhz
Both the RX and TX will use pin Pin D10 for communication. Power and ground will come from the nano. Only one 433mhz module can be used at a time. Wire only the one you need, you cannot do both with this example. You will use only the 433mhz TX when in operation. The 433mhz RX is only if you need to read commands from another brand screen. Most screens probably use the same commands so only follow the Read Codes if you either know you need to read codes in, or the program is not working for you.

### Upload Arduino Code to Nano
Upload either "ProjectorScreen433mhz.ino" or "ReceiveDemo_Simple.ino" depending on if you are needing to read codes. If you dont need to read codes you can skip that section below. Use the Arduino IDE to accomplish this. Many other tutorials exist on how to uplaod code to Arduino. You will also utilize serial monitor in the Arduino IDE if reading codes. 

### Read Codes
Make sure you have loaded "ReceiveDemo_Simple.ino" Ensure you have purchased and are using the 433mhz RX. Load the code from "" on you board (nano). Open serial monitor to recieve messages. Press a button on your remote to capture the code and other details of the signal. Record those signals in "".

### Wire up 12v Trigger
Some projectors have the old style wire prong so you can wire direct. Others you may need to get an adpater from headphone style jack to bare wire you can wire into the 12v convertor then nano. All grounds need to be connected to eachother. 12v Power wire signal needs to be attached the input of the 12v convertor then the outpu of the 12v convertor to PIN D2 on a nano. DO NOT input 12v directly into the nano,, you will see and smell some nastyl white smoke.

### Test it out
Mkae sure you have loaded "ProjectorScreen433mhz.ino" 
You should set your extents before hand so no adjustments will be nedded each time you turn on/off the projector.
Start with you screen raised.
Turn your projector on. Your screen should start to lower. 
Turn your projecto off. Your screen should start to raise.

