#include <Arduino.h>

#include <Servo8Bit.h>

Servo8Bit myservo;

uint8_t potpin = A1;
uint8_t servopin = 1; // PB1
uint8_t servo_rate = 20; // millis

uint8_t val;
uint8_t now;
uint8_t old_now;
uint8_t last_servo_out;

void setup() {
  myservo.attach(servopin);
}

void loop() {
  now = millis();
  if ((now >= last_servo_out + servo_rate) || (old_now > now)) // only send to servo when it is time or if millis wraps
  {
    // get analog and map to PWM mircos
    val = analogRead(potpin);
    val = map(val, 0, 1023, 800, 2200);

    // set servo
    myservo.writeMicroseconds(val);
    last_servo_out = now;
  }
  old_now = now;
}
