#include <SoftwareSerial.h>
#include <SoftwareServo.h> 

SoftwareSerial BTserial(1, 2);   //TxD, RxD
SoftwareServo servo;
int pos=0;

void setup() {
  BTserial.begin(38400);
  servo.attach(0);
}

void loop() {
  if (BTserial.available() > 0) { // Checks whether data is comming from the serial port
    pos=BTserial.read(); // Reads the data from the serial port
    for(int i=0; i<200; i+=1){ 
      servo.write(pos);
      delay(1);
      SoftwareServo::refresh();
    }
  }
}
