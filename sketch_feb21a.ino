int analogPin = A5;
int count=0;
long count_sec;
int LED1 = 13 ;
int memon = 0 ;
int memoff = 0 ;

void setup() {
  pinMode (LED1,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  
int val = analogRead(analogPin); 
  //Serial.println(val);
 
  
  if (Serial.available() > 0 ){
    char key = Serial.read();
    if (key ==  '1'){
      digitalWrite(LED1,HIGH);
    }
    else {digitalWrite(LED1,LOW);}
  }
   if (val >= 500 &&  memon == 0 ){
    delay(500);
    Serial.print("1");
    memon = 1;
    memoff = 0;
   
  }
   if (val < 500 && memoff == 0){
    delay(500);
    Serial.print("0");
     memon = 0;
     memoff = 1;
  }
}
