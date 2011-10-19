
//include WProgram to get the constants from Arduino

#include "WProgram.h"

class TankMotor {
  public:
    int motor_pin;
    
    TankMotor(int pin) {
      motor_pin = pin;
    }
    
    void run(int motor_speed) {
      analogWrite(motor_pin, motor_speed);
    }
    
    
};

