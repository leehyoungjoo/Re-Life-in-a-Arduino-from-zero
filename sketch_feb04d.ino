#include <Servo.h>
int angle = 75;
int servoPin = 10;

Servo servo;

int trigPin = 12;
int echoPin = 13;
int rightSensor = 6;
int leftSensor = 7;
int duration = pulseIn(echoPin,HIGH);
int distance =(340*duration) / 20000;  


void setup(){
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  servo.attach(10);
}

void loop(){  
  int rightData = digitalRead(6);
  int leftData = digitalRead(7);
  
  float duration;
  float distance;

  digitalWrite(4,LOW);
  analogWrite(5,255);
  


  if (rightData == 1 && leftData == 1){
    servo.write(72);// 숫자가 커질수록 오른쪽으로 가고 숫자가 작아질수록 왼쪽으로 간다.(서보모터)
  }
  else if(rightData == 0 && leftData == 1){
    servo.write(0);
    delay(875);
    digitalWrite(4,LOW);
    analogWrite(5,255);
  }
  else if(rightData == 1 && leftData == 0){
    servo.write(144);
    digitalWrite(4,LOW);
    analogWrite(5,255);
    delay(875);
  }
}

