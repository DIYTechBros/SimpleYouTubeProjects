unsigned long time1;
unsigned long time2;
int input1 = 4;
int input2 = 5;
int buzzer = 10;
bool servo_run = false;
#include <Servo.h>
int servoPin = 3; 
Servo Servo1; 

void setup() {
  //Serial.begin(9600);
  Servo1.attach(servoPin); 
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(buzzer, OUTPUT);
  Servo1.write(160);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}
void loop() {
  if ( digitalRead(input1) == LOW ) {
    time1 = millis();
    //Serial.println("1");
  }
  if ( digitalRead(input2) == LOW ) {
    time2 = millis();
    //Serial.println("2");
  }

  if (time2 - time1 > 10 && time2 - time1 < 200 ) {
    //Serial.println("trigger"); //prints time since program started
    //Serial.println(String(time2-time1)); //prints time since program started
    time1 = 0;
    time2 = 0;
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    servo_run = true;
  }

  if(servo_run) {
    servo_run = false;
    Servo1.write(1);
    delay(1000); 
    Servo1.write(160);
    delay(2000);
  }

}
