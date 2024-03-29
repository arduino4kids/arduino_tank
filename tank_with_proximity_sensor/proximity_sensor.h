//include WProgram to get the constants from Arduino

#include "WProgram.h"

class ProximitySensor {
  public:
    int sensor_pin;
    
    ProximitySensor(int pin) {
      sensor_pin = pin;
    }
    
    long duration() {
      // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
      // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
      pinMode(sensor_pin, OUTPUT);
      digitalWrite(sensor_pin, LOW);
      delayMicroseconds(2);
      digitalWrite(sensor_pin, HIGH);
      delayMicroseconds(5);
      digitalWrite(sensor_pin, LOW);
    
      // The same pin is used to read the signal from the PING))): a HIGH
      // pulse whose duration is the time (in microseconds) from the sending
      // of the ping to the reception of its echo off of an object.
      pinMode(sensor_pin, INPUT);
      return(pulseIn(sensor_pin, HIGH));
    }
    
    
    long inches(){
      return(microsecondsToInches(duration()));
    }
    
    long cm(){
      return(microsecondsToCentimeters(duration()));
    }

    long microsecondsToInches(long microseconds)
      {
        // According to Parallax's datasheet for the PING))), there are
        // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
        // second).  This gives the distance travelled by the ping, outbound
        // and return, so we divide by 2 to get the distance of the obstacle.
        // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
        return microseconds / 74 / 2;
      }
      
    long microsecondsToCentimeters(long microseconds)
      {
        // The speed of sound is 340 m/s or 29 microseconds per centimeter.
        // The ping travels out and back, so to find the distance of the
        // object we take half of the distance travelled.
        return microseconds / 29 / 2;
      }
};

