/*
* IRremote Library - Copyright 2009 Ken Shirriff
* created by Rui Santos, http://randomnerdtutorials.wordpress.com
* Control LED's with a remote control
* 2013
*/

#include <IRremote.h>

int IR_Recv = 3;   //IR Receiver Pin 3

IRrecv irrecv(IR_Recv);
decode_results results;

//variables to make the LED blink when selected

void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
}

void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}
