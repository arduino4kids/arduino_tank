//This example will move the motors
//and will check for proximity
//if it hits proximity, it will light up the lights

#include "tank_motor.h"
#include "proximity_sensor.h"

TankMotor motor1(6);
TankMotor motor2(5);
ProximitySensor proximity_sensor(7);
int motor_speed;

void setup(){
}

void loop(){
  if(proximity_sensor.cm() < 5) {
    motor_speed = 0;
  }
  else {
    motor_speed = 100;
  }
  motor1.run(motor_speed);
  motor2.run(motor_speed);

}





