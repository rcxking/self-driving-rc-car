/*
 * steering_servo.ino
 * 
 * Test program to steer the wheels via the Serial Console.
 * 
 * Bryant Pong
 * 1/29/18
 */

#include <Servo.h>

Servo servo;

// Servo Pin (**MUST BE PWM**) 
const int SERVO_PORT = 9;

// Servo Positions:
const int SERVO_CENTER   = 90; // Front Wheels Facing Forward
const int MIN_SERVO_POS  = 0;  // Minimum Servo Heading
const int MAX_SERVO_POS  = 180; // Maximum Servo Heading

void setup() {

  // Initialize Serial Console:
  Serial.begin( 115200 );
  
  // put your setup code here, to run once:
  servo.attach( SERVO_PORT );

  // Center servo
  servo.write( SERVO_CENTER );
}

void loop() {
  // Ask user for angle to write to Servo:
  while( Serial.available() == 0 );
  int heading = Serial.parseInt();
  
  // Servo headings are 0 - 180.  Perform range checks:
  if( ( heading >= MIN_SERVO_POS ) && ( heading <= MAX_SERVO_POS ) )
  {
    servo.write( heading );
  }
}
