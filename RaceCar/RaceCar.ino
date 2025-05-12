int t1 = 2; //turn car
int t2 = 3;
int en4 = 5;  // pin with ~ symbol
int ch4 = 6;  // pin with ~ symbol

int m1 = 7; //move car
int m2 = 8;
int en2 = 10;  // pin with ~ symbol
int ch2 = 11;  // pin with ~ symbol

void setup()  
{
  pinMode(ch4, INPUT);
  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(en4, OUTPUT);

  pinMode(ch2, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(en2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int pwm4 = 0;
  int turn = pulseIn(ch4, HIGH);

  int pwm2=0;
  int move=pulseIn(ch2, HIGH);

  Serial.print("turn: ");
  Serial.print(turn);
  Serial.print(" move: ");
  Serial.println(move);

  
  if(move==0)
  {
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      analogWrite(en2, 0);
      digitalWrite(t1, LOW);
      digitalWrite(t2, LOW);
      analogWrite(en4, 0);
  }
  
  else if(move > 1500)
  {
      pwm2 = map(move, 1500, 2000, 0, 255); 
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      analogWrite(en2, pwm2);
      digitalWrite(t1, LOW);
      digitalWrite(t2, HIGH);
      analogWrite(en4, pwm2);
  }
  
  else if(move > 990 && move < 1390)
  {
      pwm2 = map(move, 1390, 990, 0, 255); 
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      analogWrite(en2, pwm2);
      digitalWrite(t1, HIGH);
      digitalWrite(t2, LOW);
      analogWrite(en4, pwm2);
  }

  //  if(turn==0)
  // {
  //   digitalWrite(t1, LOW);
  //   digitalWrite(t2, LOW);
  //   analogWrite(en4, 0);
  // }
  
  else if(turn>1500)    // Right turn 
  {
    pwm4=map(turn, 1500, 2000, 0, 255);
    digitalWrite(t1, LOW);
    digitalWrite(t2, HIGH);
    analogWrite(en4, pwm4);
    digitalWrite(m1,HIGH);
    digitalWrite(m2, LOW);
    analogWrite(en2, ((pwm4)*(5))/13);
  }

  else if(turn > 990 && turn < 1390)  // Left turn
  {
    pwm4=map(turn, 1390, 990, 0, 255);
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    analogWrite(en2, pwm4);
    digitalWrite(t1, LOW);
    digitalWrite(t2, HIGH);
    analogWrite(en4, ((pwm4) *(5))/26);
  }
  
  else
  {
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      analogWrite(en2, 0);
      digitalWrite(t1, LOW);
      digitalWrite(t2, LOW);
      analogWrite(en4, 0);
  }
  
   delay(500);
}