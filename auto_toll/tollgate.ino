//ultrasonic sensor

#define echopin 7
#define trigerpin 6

#define m11 2
#define m12 3

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigerpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("ultrasonic sensor");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigerpin, LOW);
  delayMicroseconds(10);

  digitalWrite(trigerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerpin, LOW);

  duration = pulseIn(echopin, HIGH);

  distance = duration * 0.034/2;
  
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if( distance < 10 ){
    digitalWrite(m11, LOW);
    digitalWrite(m12, HIGH);
    delay(3000);

    digitalWrite(m11, HIGH);
    digitalWrite(m12, LOW);
    delay(3000);
    Serial.print("+++++pressing+++++"); 
  }
  else{
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
  }
}
