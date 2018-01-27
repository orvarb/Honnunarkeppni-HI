//skilgreinum encoder breytur fyrir hjól
/*int encoderLFW = 2;
float rpsLFW;
float rpmLFW;
volatile int pulsesLFW;
unsigned long timeoldLFW;
float sLFW;*/

//----------------

//Skilgreinum motor controler breytur fyrir hjól
int lfwPWM = 7;
int lfwplus = 6;
int lfwminus = 5;
//----------------
int rfwPWM = 4;
int rfwplus = 3;
int rfwminus = 2;
//----------------
int lbwPWM = 13;
int lbwplus = 12;
int lbwminus = 11;
//----------------
int rbwPWM = 8;
int rbwplus = 9;
int rbwminus = 10;

int count;


void setup() {
  Serial.begin(9600);
  //skilgreinum pinna fyrir right front wheel
  pinMode(rfwplus, OUTPUT);    // 3
  pinMode(rfwminus, OUTPUT);  // 2
  pinMode(rfwPWM, OUTPUT);    // 4
  //Skilgreinum pinna fyrir left front wheel
  pinMode(lfwplus, OUTPUT);   // 6
  pinMode(lfwminus, OUTPUT);  // 5
  pinMode(lfwPWM, OUTPUT);    // 7
  //Skilgreinum pinna fyrir left front wheel
  pinMode(lbwplus, OUTPUT);   // 12
  pinMode(lbwminus, OUTPUT);  // 11
  pinMode(lbwPWM, OUTPUT);    // 13
  //Skilgreinum pinna fyrir left front wheel
  pinMode(rbwplus, OUTPUT);   // 9
  pinMode(rbwminus, OUTPUT);  // 10
  pinMode(rbwPWM, OUTPUT);    // 8
  
  
  //skilgreinum encoder left front wheel
  /*pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),counter,RISING);
  pulsesLFW = 0;*/
}

/*void counter() {
  pulsesLFW = pulsesLFW++;
}*/

void loop() {
  driveStraight(3000);
  stopMotors(500);
  driveLeft(3000);
  stopMotors(500);
  driveBackwards(3000);
  stopMotors(500);
  driveRight(3000);
  stopMotors(500);
  
  /*if(pulsesLFW>100){
   detachInterrupt(digitalPinToInterrupt(encoderLFW));
  Serial.println("TYPPI");
  attachInterrupt(digitalPinToInterrupt(encoderLFW));
    }*/
  }

void driveStraight(int seconds) { 
  digitalWrite(lfwplus, HIGH);  // 6
  digitalWrite(lfwminus, LOW);  // 5
  analogWrite(lfwPWM, 150);   // 7
  digitalWrite(rfwplus, HIGH);  // 3
  digitalWrite(rfwminus, LOW);  // 2
  analogWrite(rfwPWM, 180);   // 4
  digitalWrite(rbwplus, LOW); // 9
  digitalWrite(rbwminus, HIGH);   // 10
  analogWrite(rbwPWM, 150);   // 8
  digitalWrite(lbwplus, LOW); // 12
  digitalWrite(lbwminus, HIGH); // 11
  analogWrite(lbwPWM, 200);   // 13
  delay(seconds);
}

void driveBackwards(int seconds) {
  digitalWrite(lfwplus, LOW);  // 6
  digitalWrite(lfwminus, HIGH);  // 5
  analogWrite(lfwPWM, 150);   // 7
  digitalWrite(rfwplus, LOW);  // 3
  digitalWrite(rfwminus, HIGH);  // 2
  analogWrite(rfwPWM, 180);   // 4
  digitalWrite(rbwplus, HIGH); // 9
  digitalWrite(rbwminus, LOW);   // 10
  analogWrite(rbwPWM, 150);   // 8
  digitalWrite(lbwplus, HIGH); // 12
  digitalWrite(lbwminus, LOW); // 11
  analogWrite(lbwPWM, 200);   // 13
  delay(seconds);
}

void driveLeft(int seconds) {
  digitalWrite(lfwplus, LOW);  // 6
  digitalWrite(lfwminus, HIGH);  // 5
  analogWrite(lfwPWM, 150);   // 7
  digitalWrite(rfwplus, HIGH);  // 3
  digitalWrite(rfwminus, LOW);  // 2
  analogWrite(rfwPWM, 180);   // 4
  digitalWrite(rbwplus, HIGH); // 9
  digitalWrite(rbwminus, LOW);   // 10
  analogWrite(rbwPWM, 150);   // 8
  digitalWrite(lbwplus, LOW); // 12
  digitalWrite(lbwminus, HIGH); // 11
  analogWrite(lbwPWM, 200);   // 13
  delay(seconds);
}

void driveRight(int seconds) {
  digitalWrite(lfwplus, HIGH);  // 6
  digitalWrite(lfwminus, LOW);  // 5
  analogWrite(lfwPWM, 150);   // 7
  digitalWrite(rfwplus, LOW);  // 3
  digitalWrite(rfwminus, HIGH);  // 2
  analogWrite(rfwPWM, 180);   // 4
  digitalWrite(rbwplus, LOW); // 9
  digitalWrite(rbwminus, HIGH);   // 10
  analogWrite(rbwPWM, 150);   // 8
  digitalWrite(lbwplus, HIGH); // 12
  digitalWrite(lbwminus, LOW); // 11
  analogWrite(lbwPWM, 200);   // 13
  delay(seconds);
}

void stopMotors(int seconds) {
  digitalWrite(lfwplus, HIGH);  // 6
  digitalWrite(lfwminus, LOW);  // 5
  analogWrite(lfwPWM, 0);   // 7
  digitalWrite(rfwplus, HIGH);  // 3
  digitalWrite(rfwminus, LOW);  // 2
  analogWrite(rfwPWM, 0);   // 4
  digitalWrite(rbwplus, LOW); // 9
  digitalWrite(rbwminus, HIGH);   // 10
  analogWrite(rbwPWM, 0);   // 8
  digitalWrite(lbwplus, LOW); // 12
  digitalWrite(lbwminus, HIGH); // 11
  analogWrite(lbwPWM, 0);   // 13
  delay(seconds);
}

