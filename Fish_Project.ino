#include <Wire.h>
#include <AFMotor.h>
AF_DCMotor myMotor(1);
AF_DCMotor myOtherMotor(2);
int SoundInPin = A0;


void setup() {
  Serial.begin(9600);
  myMotor.setSpeed(0); //mouth motor
  myMotor.run(FORWARD);
  myMotor.run(RELEASE);
     pinMode(SoundInPin, INPUT);
  myOtherMotor.setSpeed(0); //tail motor
  myOtherMotor.run(FORWARD);
  myOtherMotor.run(RELEASE);
     pinMode(SoundInPin, INPUT);  
}


void loop() {
  int i;
  int sensorValue = analogRead(SoundInPin);
  sensorValue = map(sensorValue,0,512,0,180);
  int MoveDelayValue = map(sensorValue,0,255,0,sensorValue);
    Serial.print(sensorValue);
  if (sensorValue > 5) {
   delay(1);
   myMotor.run(FORWARD);
  for (i=140; i<255; i++) {
    myMotor.setSpeed(i); 
    delay(2);
  }

  for (i=200; i!=0; i--) {
    myMotor.setSpeed(i);  
    }
  delay(10);
  myMotor.run(RELEASE);
  myOtherMotor.run(RELEASE);
  }
}
