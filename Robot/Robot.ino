//skilgreinum encoder breytur fyrir hjól
/*int encoderLFW = 2;
float rpsLFW;
float rpmLFW;
volatile int pulsesLFW;
unsigned long timeoldLFW;
float sLFW;*/

//----------------

//Skilgreinum motor controler breytur fyrir hjól
int lfwPWM = 8;
int lfwplus = 10;
int lfwminus = 9;
//----------------
int rfwPWM = 13;
int rfwplus = 11;
int rfwminus = 12;
//----------------
int lbwPWM = 2;
int lbwplus = 3;
int lbwminus = 4;
//----------------
int rbwPWM = 7;
int rbwplus = 6;
int rbwminus = 5;

// Takki sem byrjar loop-una
int button = 1;

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
  // Skilgreina pinna fyir takka sem byrjar kóðann
  pinMode(button, INPUT_PULLUP);
  
  //skilgreinum encoder left front wheel
  /*pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),counter,RISING);
  pulsesLFW = 0;*/
}

/*void counter() {
  pulsesLFW = pulsesLFW++;
}*/

void loop() {

  if (digitalRead(button) == LOW) {
    delay(1000);
    driveStraight(1350);
    stopMotors(500); 
    driveRight(3500);
    stopMotors(500);
    driveStraight(7700);
    stopMotors(500); 
    driveLeft(3100);
    stopMotors(500);
    driveStraight(2400);
    stopMotors(1500);
    driveStraight(1200);
    stopMotors(1500);
    driveLeft(900);
    stopMotors(1500);
    adjust(100);
    stopMotors(500);
    GUN(10000);
    stopMotors(500);
  }
  
  /*if(pulsesLFW>100){
   detachInterrupt(digitalPinToInterrupt(encoderLFW));
  Serial.println("TYPPI");
  attachInterrupt(digitalPinToInterrupt(encoderLFW));
    }*/
  }

void driveStraight(int seconds) { 
  digitalWrite(lfwplus, HIGH);  // 6
  digitalWrite(lfwminus, LOW);  // 5
  analogWrite(lfwPWM, 175);   // 7
  digitalWrite(rfwplus, HIGH);  // 3
  digitalWrite(rfwminus, LOW);  // 2
  analogWrite(rfwPWM, 212);   // 4
  digitalWrite(rbwplus, HIGH); // 9
  digitalWrite(rbwminus, LOW);   // 10
  analogWrite(rbwPWM, 180);   // 8
  digitalWrite(lbwplus, HIGH); // 12
  digitalWrite(lbwminus, LOW); // 11
  analogWrite(lbwPWM, 180);   // 13
  delay(seconds);
}

void driveBackwards(int seconds) {
  digitalWrite(lfwplus, LOW);  // 6
  digitalWrite(lfwminus, HIGH);  // 5
  analogWrite(lfwPWM, 175);   // 7
  digitalWrite(rfwplus, LOW);  // 3
  digitalWrite(rfwminus, HIGH);  // 2
  analogWrite(rfwPWM, 212);   // 4
  digitalWrite(rbwplus, LOW); // 9
  digitalWrite(rbwminus, HIGH);   // 10
  analogWrite(rbwPWM, 180);   // 8
  digitalWrite(lbwplus, LOW); // 12
  digitalWrite(lbwminus, HIGH); // 11
  analogWrite(lbwPWM, 180);   // 13
  delay(seconds);
}

void driveRight(int seconds) {
  digitalWrite(lfwplus, HIGH);  // 6
  digitalWrite(lfwminus, LOW);  // 5
  analogWrite(lfwPWM, 175);   // 7
  digitalWrite(rfwplus, LOW);  // 3
  digitalWrite(rfwminus, HIGH);  // 2
  analogWrite(rfwPWM, 215);   // 4
  digitalWrite(rbwplus, HIGH); // 9
  digitalWrite(rbwminus, LOW);   // 10
  analogWrite(rbwPWM, 180);   // 8
  digitalWrite(lbwplus, LOW); // 12
  digitalWrite(lbwminus, HIGH); // 11
  analogWrite(lbwPWM, 180);   // 13
  delay(seconds);
}

void driveLeft(int seconds) {
  digitalWrite(lfwplus, LOW);  // 6
  digitalWrite(lfwminus, HIGH);  // 5
  analogWrite(lfwPWM, 175);   // 7
  digitalWrite(rfwplus, HIGH);  // 3
  digitalWrite(rfwminus, LOW);  // 2
  analogWrite(rfwPWM, 212);   // 4
  digitalWrite(rbwplus, LOW); // 9
  digitalWrite(rbwminus, HIGH);   // 10
  analogWrite(rbwPWM, 180);   // 8
  digitalWrite(lbwplus, HIGH); // 12
  digitalWrite(lbwminus, LOW); // 11
  analogWrite(lbwPWM, 180);   // 13
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

void GUN(int seconds) { 
  digitalWrite(lfwplus, HIGH);  // 6
  digitalWrite(lfwminus, LOW);  // 5
  analogWrite(lfwPWM, 215);   // 7
  digitalWrite(rfwplus, HIGH);  // 3
  digitalWrite(rfwminus, LOW);  // 2
  analogWrite(rfwPWM, 252);   // 4
  digitalWrite(rbwplus, HIGH); // 9
  digitalWrite(rbwminus, LOW);   // 10
  analogWrite(rbwPWM, 220);   // 8
  digitalWrite(lbwplus, HIGH); // 12
  digitalWrite(lbwminus, LOW); // 11
  analogWrite(lbwPWM, 220);   // 13
  delay(seconds);
}

void adjust(int seconds) { 
  digitalWrite(lfwplus, HIGH);  // 6
  digitalWrite(lfwminus, LOW);  // 5
  analogWrite(lfwPWM, 175);   // 7
  digitalWrite(rfwplus, LOW);  // 3
  digitalWrite(rfwminus, HIGH);  // 2
  analogWrite(rfwPWM, 212);   // 4
  digitalWrite(rbwplus, LOW); // 9
  digitalWrite(rbwminus, HIGH);   // 10
  analogWrite(rbwPWM, 180);   // 8
  digitalWrite(lbwplus, HIGH); // 12
  digitalWrite(lbwminus, LOW); // 11
  analogWrite(lbwPWM, 180);   // 13
  delay(seconds);
}

