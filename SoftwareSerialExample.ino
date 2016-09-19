
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
int motion=2;
int led=13;
int motion_count=0;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  pinMode(motion,INPUT);
  pinMode(led,OUTPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
 // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

}

void loop() { // run over and over
digitalWrite(led,LOW);
delay(1000);
int sensor = digitalRead(motion);
if(sensor == HIGH){
   motion_count++;
   digitalWrite(led,HIGH);
   delay(100);
   digitalWrite(led,LOW);
   delay(100);
   }
    mySerial.println(motion_count);
    delay(500);
    if(motion_count==100)
    motion_count=0;
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

