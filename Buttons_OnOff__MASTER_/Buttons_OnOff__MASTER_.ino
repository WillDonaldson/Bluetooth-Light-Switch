#include <SoftwareSerial.h>

SoftwareSerial BTserial(1, 2); //TxD, RxD

const int OffPin=3;
const int OnPin=4;  

void setup() {
  BTserial.begin(38400);
  pinMode(OffPin, INPUT);
  pinMode(OnPin, INPUT);
}

void loop() {
  if(digitalRead(OffPin)==HIGH){        //User wants to turn off lights
    BTserial.write(10);                 //Send signal to move servo to off position
    delay(1500);
    BTserial.write(60);                 //After a delay return servo to neutral position, allowing user to still manually use the lightswitch

  }

  else if(digitalRead(OnPin)==HIGH){    //User wants to turn on lights
    BTserial.write(100);                //Send signal to move servo to on position
    delay(1500);
    BTserial.write(60);                  
  }
}
