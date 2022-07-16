# Leak detector safety shutdown for Arduino 💧
**Leak safety shutdown** is a software and recommended circuitry to use with a micro-controller to switch off connected devices when liquid is detected and alert users with a flashing light.
Leak-detector.ino works with a contact or non-contact liquid sensor (such as XKC-Y25-T12V) and a standard relay which can be closed or open when a leak is detected. 


## Disclaimer
⚠️ **Electronics and water can be very dangerous.
On top of the standard safety measure when working with electrical in risky situations I highly recommended protecting your circuit inside waterproof graded containers. Be careful**


## Installation
Simply download the .ino file onto your computer and upload it on your Arduino using the Arduino IDE.

Once the software is loaded, you can connect the micro-controller to your liquid sensor, a relay and your devices using the Arduino digital pins.

#### Standard circuit:
![leak-detector-diagram](https://user-images.githubusercontent.com/38887185/179363295-06bccaf0-3bdc-4bf3-b91f-a454255f9fca.jpg)

This example circuit contains a peristaltic pump that can sometimes leak due friction on the silicone tubing after several hours of non stop usage. 

If liquid is detected by the sensor located underneath the pump the LED strip flashes rapidly to alert users and the pump  supply is immediately stopped to prevent any further leakage. 

## Options
#### Connected devices
Make sure to declare your connected device(s) as well as defining their allocated pin at the top of the script:
```c++
int liquidsensor_pin= 4;
int pump1_pin= 5;
int ledPin= 6; 
```

#### Flashing light
You can also modulate the flashing speed by changing `interval` (in millisec)
```c++
long interval = 100; // will flash very quickly
// or
long interval = 300; // will flash much slower
```




