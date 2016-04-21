/*
 Fading
 
 This example shows how to fade a standard 100W 240VAC lightbulb using the MPDMv4 Driver 
 and the analogWrite() function.

 The circuit:
 VCNT attached from digital pin 3 to ground. 
 On the putput pin use also a 100-200u electrolitic cap for PWM smoothing.
 
 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe
 modified 14 Apr 2016
 by TJ for the MPDMv4 - AC MAINS Power Dimmer Driver
 more details at:  
 http://www.esp8266-projects.com/2016/04/mpdmv4-mains-dimmerswitch.html
 
 This example code is in the public domain.
 http://arduino.cc/en/Tutorial/Fading
 
 This example code is in the public domain.
 
 */


int VCNT = 3;    // MPDMv4 Voltage Control Pin (VCNT) connected to Arduino PIN3

void setup()  { 
  // initialize the VCNT pin as an output:
  pinMode(VCNT, OUTPUT);  
} 

void loop()  { 
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 190; fadeValue +=5) { 
    // sets the value (range from 0 to 190): MPDMv4 Calibrated range
    analogWrite(VCNT, fadeValue);         
    // wait for 100 milliseconds to see the dimming effect    
    delay(100);                            
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 190 ; fadeValue >= 0; fadeValue -=5) { 
    // sets the value (range from 0 to 190): MPDMv4 Calibrated range
    analogWrite(VCNT, fadeValue);         
    // wait for 100 milliseconds to see the dimming effect    
    delay(100);                            
  } 
}


