#include <Arduino.h>

// #include <Servo.h>

// Servo myservo;

#include <Servo8Bit.h>

Servo8Bit myservo;

uint8_t potpin = A1;
uint8_t servo_rate = 20; // millis

uint8_t val;
uint8_t now;
uint8_t old_now;
uint8_t last_servo_out;

int blah = 37483;


void setup() {
  myservo.attach(1); // attach to PB1
}

void loop() {
  now = millis();
  if ((now >= last_servo_out + servo_rate) || (old_now > now)) // only send to servo when it is time
  {
    blah++;
    analogWrite(0, blah);
    // get analog and map to PWM mircos
    val = analogRead(potpin);
    val = map(val, 0, 1023, 0, 180);

    // set servo
    // myservo.writeMicroseconds(val);
    myservo.write(val);
    last_servo_out = now;
  }
  old_now = now;
}
