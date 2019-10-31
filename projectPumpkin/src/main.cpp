#include <Arduino.h>

int trigPin = 11; //trigger
int echoPin = 12; //echo
int count = 5;
int count2 = 5;

int leftEye = 6; // left leftEye
int rightEye = 5; //rightEye
int thootForNow = 8;
long duration, cm;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(leftEye, OUTPUT);
  pinMode(rightEye, OUTPUT);
  pinMode(thootForNow, OUTPUT);

}

void loop() {
  //the sensor is triggered by HIGH pulse of 10 or more microseconds.
  //give a short LOW pulse before to ensure clean HIGH pulse.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Read the signal from the sensor: a HIGH pulse whose
  //duration is the time (in microseconds) from the sending
  //of the ping to the reception of its echo off an object.

  duration = pulseIn(echoPin, HIGH); // counts time to go LOW on echoPin

//convert the time into a distance

cm = (duration/2) / 29.1; //Divide by 29.1 or multiply by 0.0343-> 343 meter per second

  if(cm < 400){
    for (size_t i = 0; i < count2; i++) {

        digitalWrite(leftEye, HIGH);
        delay((cm)/2);
        digitalWrite(leftEye, LOW);
        digitalWrite(thootForNow, HIGH);
        delay((2*cm)/2);
        digitalWrite(thootForNow, LOW);
        digitalWrite(rightEye, HIGH);
        delay((cm)/2);
        digitalWrite(leftEye, LOW);
        delay((cm)/2);
        digitalWrite(rightEye, LOW);
  }
    for (int i = 0; i < count; i++) {
      /* code */
      digitalWrite(rightEye, HIGH);
      digitalWrite(thootForNow, HIGH);
      delay((cm)/2);
      digitalWrite(thootForNow, LOW);
      digitalWrite(rightEye, LOW);
      delay((2*cm)/2);
      digitalWrite(thootForNow, HIGH);

    }
  }
  else{
    digitalWrite(leftEye, LOW);
    digitalWrite(rightEye, LOW);
  }


  Serial.print(cm);
  Serial.println(" cm");
  delay(250);

}
