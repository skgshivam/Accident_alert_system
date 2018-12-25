# Smart Accident Alert System
&nbsp;
> ## Introduction

Due to increasing number of vehicles on roads, accidents are also increasing, and consequently there have been sharp increase in mortalities caused due to road traffic injury.

Smart Accident Alert System tries to curb accidents. It is accident detection and messaging system using GPS, vibration sensor and GSM module, in which the vibration sensor is used as an input to the system and corresponding response is analyzed by Arduino. If an accident occurs then SMS is send to registered mobile number so that immediate help can be provided.

&nbsp;
> ## Novelty of the System

* Driver will be intimated about ‘accident prone zone’ based on the vehicle's coordinates. Hence , the driver will become cautious while driving. 

* An extra module - Camera - is included for further enhancement of the Accident Alert System, which will take picture of the driver in regular intervals and send them to a server via wi-fi. This will help in jugding the behaviour of the driver while driving.

&nbsp;
> ## Components Required

* Arduino Uno
* GSM Module (SIM900A)
* GPS Module (SIM28ML)
* Vibration Sensor
* 16x2 LCD
* Connecting Wires
* 10 K-POT
* Breadboard or PCB
* Arducam
* Wi-fi module(ESP8266)

&nbsp;
> ## Functional Diagram

![alt text](https://github.com/Vineet-Sharma29/Accident_alert_system/blob/master/Docs/Functional-Diagram.PNG)


&nbsp;
> ## Connection Diagram for Arducam

![alt text](https://github.com/Vineet-Sharma29/Accident_alert_system/blob/master/Docs/Connection-Diagram.png)


&nbsp;
> ## How To Use This Repo

Run following commands

* `git clone https://github.com/Vineet-Sharma29/Accident_alert_system.git`
* `cd Accident_alert_system`
* Repo is organsied into two folder
  * __Docs__ - Contain documents regarding project which were refrenced while making the system.
  * __Code__ - Contain running code for the system.
* `cd Code`
* Run `GSM-GPS.ino`. This file is used to run GPS, GSM and Vibration Sensor module.
* Run `Camera.ino` and then open `ReadSerialPortWin.exe` in order to capture image from Arducam.


