#define m11 3 //right motor
#define m12 2
#define m21 4 //left motor
#define m22 5

#define left_sensor 7
#define right_sensor 6

int left_ir,right_ir;

void setup() {
  // put your setup code here, to run once:
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
  pinMode(left_sensor,INPUT);
  pinMode(right_sensor,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
  
  left_ir = digitalRead(left_sensor);
  right_ir = digitalRead(right_sensor);

  Serial.print("left: ");Serial.println(left_ir);
  Serial.print("right: ");Serial.println(right_ir);
  
  if( right_ir == 0 && left_ir == 1 ){
    Serial.println("+++++turning left+++++");
    
    digitalWrite(m11, HIGH);
    digitalWrite(m12, LOW);
    delay(200);
    
    digitalWrite(m21, LOW);
    digitalWrite(m22, LOW);
    delay(200);
  }
  else if( right_ir == 1 && left_ir == 0 ){
    Serial.println("+++++turning right+++++");
    
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
    delay(200);
    
    digitalWrite(m21, LOW);
    digitalWrite(m22, HIGH);
    delay(200);
  }
  if( right_ir == 1 && left_ir == 1 ){
    Serial.println("+++++stop+++++");
    
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
    delay(200);
    
    digitalWrite(m21, LOW);
    digitalWrite(m22, LOW);
    delay(200);
  }
  if( right_ir == 0 && left_ir == 0 ){
    Serial.println("+++++forward+++++");
    
    digitalWrite(m11, HIGH);
    digitalWrite(m12, LOW);
    delay(200);
    
    digitalWrite(m21, LOW);
    digitalWrite(m22, HIGH);
    delay(200);
  } 
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
  
  delay(1000);
}
