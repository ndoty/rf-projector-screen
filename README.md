# Send a 433mhz signal to a HomeGear projector screen from a 12v Projector trigger
This was designed and coded to work for [Homegear 110” HD Motorized 16:9 Projector Screen W/ Remote Control](http://amzn.to/2ppoBB0). Codes in ProjectorScreen433mkz.ino are directly read from the remote that comes with the Homegear screen. If you purchase a screen other than [this one](http://amzn.to/2ppoBB0), you can still read the codes as long as you can verify your screen operates on 433mhz. This guide will explain how to read 433mhz codes and set them in the code.


## Software Required
* Arduino IDE - https://www.arduino.cc/en/Main/Software (Thank you Arduino)
* CH340 Driver - http://bit.ly/2pMF4in (Thank you Elegoo) or use CH340 Driver.zip in this repo
* RC Swtich Arduino Library - https://github.com/sui77/rc-switch/ (Thank you sui77)

## Hardware Required: (Amazon Affiliate links below, use the links to support me)
* Arduino Nano Clone - http://amzn.to/2FWJVos (requires special driver, see CH340 Driver above)
* 433mhz kit - http://amzn.to/2FXDhhM (TX required RX if you need to read in new codes for your screen)
* 12v to 3v - http://amzn.to/2DFVkHp (Nano can only take 5v. 3v is enough to trigger pin HIGH)
* Misc wires and cables to complete install. (Mini B USB cable, 12v Trigger Wire from projector)


### Install Arduino IDE
Head over to https://www.arduino.cc/en/Main/Software and install the Arduino IDE for your Operating System. Windows, MAC, Linux are all suported.

### Install CH340 Driver
Head over to http://bit.ly/2pMF4in or use CH340 Driver.zip from this repo.
Select the files for your Operating System to install the Driver. This will allow the Arduino IDE to flash the Arduino Nano Clone above.
### Read Codes
### Upload Arduino Code to Nano
### Wire up 433mhz
### Wire up 12v Trigger
### Test it out

