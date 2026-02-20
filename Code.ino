
const int buttonF1 = 2;
const int buttonF2 = 3;
const int buttonF3 = 4;
const int motorEnable = 9;
const int motorIn1 = 10;
const int motorIn2 = 11;

int currentFloor = 1;
const int timePerFloor = 2000; 

void setup() {
 
  pinMode(buttonF1, INPUT_PULLUP);
  pinMode(buttonF2, INPUT_PULLUP);
  pinMode(buttonF3, INPUT_PULLUP);
  pinMode(motorEnable, OUTPUT);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  digitalWrite(motorEnable, HIGH);
  
  Serial.begin(9600);
  Serial.println("Elevator System Ready.");
  Serial.println("Currently at Floor 1");
}

void loop() {
  int targetFloor = 0;
  
  if (digitalRead(buttonF1) == LOW) {
    targetFloor = 1;
  }
  
  else if (digitalRead(buttonF2) == LOW) {
    targetFloor = 2;
  } 
  
  else if (digitalRead(buttonF3) == LOW) {
    targetFloor = 3;
  }
  
  if (targetFloor != 0 && targetFloor != currentFloor) {
    moveElevator(targetFloor);
  }
}

void moveElevator(int targetFloor) {
  
  int floorsToMove = targetFloor - currentFloor;
  int moveTime = abs(floorsToMove) * timePerFloor;
  Serial.print("Moving to Floor ");
  Serial.println(targetFloor);
  
  if (floorsToMove > 0) {
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
    Serial.println("Direction: Mela(UP)");
  } 
  
  else {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, HIGH);
    Serial.println("Direction: Keela(DOWN)");
  }

  delay(moveTime); 
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
  Serial.println("Vandhuttom(reached)");
  currentFloor = targetFloor;
}
