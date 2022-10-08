  int m[8]={6,7,8,9,10,11,12,13};
void setup() {
  pinMode(5, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  for(int i=0; i<8; i++)
    pinMode(m[i], OUTPUT);
  Serial.begin(9600);
  

}
void line(){

  int val = analogRead(1);

  val=map(val,55,426,0,8);
  for(int i=0; i<val; i++)
    digitalWrite(m[i], HIGH);
  delay(3);
  for(int i=0; i<val; i++)
    digitalWrite(m[i], LOW);

}

void buzz(int frq, int d, int i){
  int n=0;
  for(i; i>n; i-=1){
    tone(5, frq, d);
    delay(500);
  }
}

void ledA(){
  
int val=analogRead(0);

val=map(val,0,1023,0,8);
  for(int i=0; i<val; i++)
    digitalWrite(m[i], HIGH);
  delay(3);
  for(int i=0; i<val; i++)
    digitalWrite(m[i], LOW);
}



void ledM() {
int val1=analogRead(3);
val1=map(val1,0,70,0,8);
  for(int i=0; i<val1; i++)
    digitalWrite(m[i], HIGH);
  delay(3);
  for(int i=0; i<val1; i++)
    digitalWrite(m[i], LOW);

}

void loop() {

if (digitalRead(2)==1){
  delay(900);
  while(digitalRead(2)==0){
    ledA();
  }
  buzz(4000, 100, 1);

  while(digitalRead(2)==0){
    ledM();
  }
  buzz(4000, 100, 2);
  while(digitalRead(2)==0){
    line();
  }
  buzz(4000, 100, 3);
}

}
