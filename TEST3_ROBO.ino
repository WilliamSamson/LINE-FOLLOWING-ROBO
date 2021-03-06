// Black Line Follower

int vSpeed = 110;        // MAX 255
int turn_speed = 230;    // MAX 255
int turn_delay = 10;

int IR1 = A0;    //Right sensor
int IR2 = A1;  //left Sensor
// motor one
int enA = 9;    //Right motor
int MotorAip1 = 7;
int MotorAip2 = 6;
// motor two
int enB = 3;    //Left motor
int MotorBip1 = 5;
int MotorBip2 = 4;

void setup()
{
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(MotorAip1, OUTPUT);
  pinMode(MotorAip2, OUTPUT);
  pinMode(MotorBip1, OUTPUT);
  pinMode(MotorBip2, OUTPUT);
}
void loop()
{
  //IR DETECTOR
  if (digitalRead(IR1) == HIGH && digitalRead(IR2) == HIGH) //IR will not glow on black line
  {
    //Stop both Motors
    digitalWrite(MotorAip1, LOW); digitalWrite(MotorAip2, LOW); digitalWrite(MotorBip1, LOW); digitalWrite(MotorBip2, LOW);
    analogWrite (enA, 0);
    analogWrite (enB, 0);
  }

  else if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW) //IR not on black line
  {
    //Move both the Motors
    digitalWrite(MotorAip1, HIGH); digitalWrite(MotorAip2, LOW); digitalWrite(MotorBip1, HIGH); digitalWrite(MotorBip2, LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
  }

  else if (digitalRead(IR1) == LOW && digitalRead(IR2) == HIGH)
  {
    //Tilt robot towards left by stopping the left wheel and moving the right one
    digitalWrite(MotorAip1, HIGH); digitalWrite(MotorAip2, LOW); digitalWrite(MotorBip1, LOW); digitalWrite(MotorBip2, HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 150);
    delay(turn_delay);
  }

  else if (digitalRead(IR1) == HIGH && digitalRead(IR2) == LOW)
  {
    //Tilt robot towards right by stopping the right wheel and moving the left one
    digitalWrite(MotorAip1, LOW); digitalWrite(MotorAip2, HIGH); digitalWrite(MotorBip1, HIGH); digitalWrite(MotorBip2, LOW);
    analogWrite (enA, 150);
    analogWrite (enB, 200);
    delay(turn_delay);
  }

  else
  {
    //Stop both the motors
    digitalWrite(MotorAip1, LOW); digitalWrite(MotorAip2, LOW); digitalWrite(MotorBip1, LOW); digitalWrite(MotorBip2, LOW);
    analogWrite (enA, 0);
    analogWrite (enB, 0);
  }
}
