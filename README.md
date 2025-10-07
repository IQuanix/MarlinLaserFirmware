# MarlinLaserFirmware
This is a repo to add the functionality of adding a laser-module to a 3d printer like an ender 5 pro.
Preview:
![IMG_2787](https://github.com/user-attachments/assets/935193f0-8d9e-4f60-877e-1b4b811ffd9b)

## The problem
So the problem I had with converting my printer to a laser engraver/cutter was that most diode lasers you can get for a printer use a pwm-input signal.
The most popular method is getting a driver board for your laser and connecting it to one of the fan-headers on your printer.
This driver uses the TTL-signal of the fan-header and converts it to a pwm-signal.\
Doesn't sound that complicated until you realize that the fan is controlled by a signal from 0-24V, the pwm-signal of the laser only takes 5V max, but the supply voltage of the laser uses 12V with max 2A :c.\
Because I was getting tired of searching for workarounds I started modifying the marlin-firmware of my printer and setup this repo.\
Here the header on the diode-laser with VCC=12V, Signal=5V pwm and ground:
<img width="2029" height="2029" alt="IMG_2786" src="https://github.com/user-attachments/assets/8f9859fe-3b7e-4780-a260-7e78bb83c1fc" />

Another Problem with the fan-header-method is the extremly low pwm frequenzy you can get out of the fan header, even when changing the firmware.\
So the next best solution I found is using the BL_TOUCH-header on my silent-board V422.\
The changes will already be saved in the raw firmware files for any ender 5 (pro). If you have a different printer you need to find the correct config in the files and copy the changes from mine and compile it (some tutorials on youtube).

## The fix
To use the laser just connect wires between the BL_TOUCH-header and the laser cable.\
|BL_TOUCH-pins --> laser-pins|\
**IN** (actually pwm-output for the servo) --> **PWM**\
**G** (just ground, _use one or the other_) --> **GND**\
Example of connecting the wires to the header:
<img width="1435" height="988" alt="IMG_2785" src="https://github.com/user-attachments/assets/c8e1c822-3de8-42c7-924a-10b3fd454ad3" />

Now you need to connect a 12V power supply to the lasers 12V and **connect both grounds to each other** so you have 3 grounds connected (GND-12V <-- GND-Laser <-- GND-BL_TOUCH).\
Note: _Currently I'm using a external power supply, but I might search for a 12V 2A pin on the printers psu or use a buck-converter in the future_.

## How to modify the firmware for your printer
In case you don't have an ender 5 (pro) with a V422 board like me, but still got a similar mainboard you can try and modify the firmware yourself.\
After watching a few tutorials on how to configure a firmware everything should be straight forward.\
You just have to copy your printers config into the marlin folder like usually and modify the given parameters of the newest version I published.\
_this parameter-set is found in the V2 readme_
You can find ready to use firmware files in each version (_.bin_).\
Once you have the compiled firmware you need to put them on a sd-card. (best to use one bin file nothing else)\
Then insert the sd card into the printer and power it on. Let it update and wait till you see the normal info screen.\
The firmware is now flashed :D.


## Warning
This is my first time playing this much with a printers firmware. If the firmware works on my printer it will prob. work on yours, but always be carefull when using the laser and **ALWAYS** wear saftey-glasses.\
Some people online reported their laser turning on for a breif moment after modifying the firware to using the fan-header. I couldn't replicate this with the BL_Touch method, but still only power the laser on when you don't have a risk of burning your eyes out.
