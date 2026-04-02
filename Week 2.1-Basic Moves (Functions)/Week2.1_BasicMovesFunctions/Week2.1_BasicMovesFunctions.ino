// Battlebot BB008
// Team IT-1D
// Michael O. Boeteng Student ID.5598168
// Jenjira Huaisai Student ID.5681502
// ======================================
// Assignment Week 3.2 Basic Moves (Functions)
// ======================================
// Make the robot move 1m forward in a straight line,
// Then, backward 1m in a straight line,
// Then, make a left turn of 90 degrees (no rotation) 
// Then, make a right turn of 90 degrees (no rotation) 
// ======================================

// PIN DEFINITIONS
#define MOTOR_LEFT_BACKWARD 3   
#define MOTOR_LEFT_FORWARD  5   
#define MOTOR_RIGHT_BACKWARD 6  
#define MOTOR_RIGHT_FORWARD  9  

// SPEED 
#define LEFT_SPEED 250
#define RIGHT_SPEED 235     
#define ARC_LEFT_SPEED 100   
#define ARC_RIGHT_SPEED 100

// TIMING
#define DISTANCE_TIME 5000       
#define ARC_TURN_TIME 1000   


// SETUP
void setup() {
  pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
  pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);

  digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
  digitalWrite(MOTOR_LEFT_FORWARD, LOW);
  digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
  digitalWrite(MOTOR_RIGHT_FORWARD, LOW);

  stopMotors();
  delay(2000); 
}

// LOOP
void loop() {
  moveForward();        
  moveBackward();      
  turnLeftArc90();      
  turnRightArc90();     

// FUNCTIONS
void stopMotors() {
  analogWrite(MOTOR_LEFT_BACKWARD, 0);
  analogWrite(MOTOR_LEFT_FORWARD, 0);
  analogWrite(MOTOR_RIGHT_BACKWARD, 0);
  analogWrite(MOTOR_RIGHT_FORWARD, 0);
}

void moveForward() {
  analogWrite(MOTOR_LEFT_BACKWARD, 0);
  analogWrite(MOTOR_LEFT_FORWARD, LEFT_SPEED);
  analogWrite(MOTOR_RIGHT_BACKWARD, 0);
  analogWrite(MOTOR_RIGHT_FORWARD, RIGHT_SPEED);

  delay(DISTANCE_TIME);
  stopMotors();
  delay(500);
}

void moveBackward() {
  analogWrite(MOTOR_LEFT_BACKWARD, LEFT_SPEED);
  analogWrite(MOTOR_LEFT_FORWARD, 0);
  analogWrite(MOTOR_RIGHT_BACKWARD, RIGHT_SPEED);
  analogWrite(MOTOR_RIGHT_FORWARD, 0);

  delay(DISTANCE_TIME);
  stopMotors();
  delay(500);
}

void turnLeftArc90() {
  analogWrite(MOTOR_LEFT_BACKWARD, 0);
  analogWrite(MOTOR_LEFT_FORWARD, ARC_LEFT_SPEED);  
  analogWrite(MOTOR_RIGHT_BACKWARD, 0);
  analogWrite(MOTOR_RIGHT_FORWARD, RIGHT_SPEED);

  delay(ARC_TURN_TIME);
  stopMotors();
  delay(500);
}

void turnRightArc90() {
  analogWrite(MOTOR_LEFT_BACKWARD, 0);
  analogWrite(MOTOR_LEFT_FORWARD, LEFT_SPEED);      
  analogWrite(MOTOR_RIGHT_BACKWARD, 0);
  analogWrite(MOTOR_RIGHT_FORWARD, ARC_RIGHT_SPEED); 

  delay(ARC_TURN_TIME);
  stopMotors();
  delay(500);
}