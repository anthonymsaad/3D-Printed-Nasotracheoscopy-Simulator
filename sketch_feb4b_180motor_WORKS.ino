#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  int currentPosition = 0;  // Starting position of the servo
  int targetPosition = 180; // Target position

  // Move servo gradually from 0 to 180
  moveServo(currentPosition, targetPosition, 10);  // Adjust speed with delay value

  delay(800); // Wait at the maximum position

  // Move servo gradually from 180 back to 0
  moveServo(targetPosition, currentPosition, 10);  // Adjust speed with delay value

  delay(3000); // Wait before starting the next cycle
}

// Function to gradually move the servo to a target position at controlled speed
void moveServo(int start, int end, int delayTime) {
  if (start < end) {
    // Incrementally move up
    for (int pos = start; pos <= end; pos++) {
      myservo.write(pos);
      delay(delayTime);  // Control speed of movement
    }
  } else {
    // Incrementally move down
    for (int pos = start; pos >= end; pos--) {
      myservo.write(pos);
      delay(delayTime);  // Control speed of movement
    }
  }
}
