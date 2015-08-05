#include <Servo.h>

int motorTIPpin = 11; //
int servoSIGpin = 9;  //
int motionINpin = 5;  //

Servo servoSIG;

void setup()
{
pinMode(motorTIPpin, OUTPUT); // Set pin for output to control TIP120 Base pin
servoSIG.attach(servoSIGpin);
pinMode(motionINpin, INPUT);
Serial.begin(9600);
delay(45000); // Wait for 45 seconds to let IR sensor stablize
}

void loop()
{

  servoSIG.writeMicroseconds(1525);
  int motionValue = digitalRead(motionINpin);

  if  (motionValue == HIGH)
  {

    Serial.write("Motion Detected\n");
    analogWrite(motorTIPpin, 255);
    Serial.write("Sending moter ON sig\n");
    delay(500);

    servoSIG.writeMicroseconds(1425);
    Serial.write("Sending servo TURN sig\n");
    delay(2000);

    servoSIG.writeMicroseconds(1525);
    Serial.write("Sending servo OFF sig\n");
    delay(500);

    analogWrite(motorTIPpin, 0);
    Serial.write("Sending motor OFF sig\n");

  }

}
