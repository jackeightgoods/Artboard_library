 
 /*
<><><><><><><><><><><><><><><><><><><>
--------------------------------------
             ART-BOARD
     Prototyping board for atist
    
by daniele murgia © 2019-20 MIT License
      sgtmurgia@gmail.com
--------------------------------------
<><><><><><><><><><><><><><><><><><><>

*/

//Mux control pins
int s0 = 25;
int s1 = 26;
int s2 = 27;
int s3 =28;
//Mux in "SIG" pin
int SIG_pin = 23;
 int led=13;
 
void setup(){
  
    //MUX
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 
  pinMode(SIG_pin, INPUT);

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);


  pinMode(led, OUTPUT);
  }

void loop(){
 

 for(int a=0; a<15;a++){
  //Serial debug
   
   Serial.print(":Y0 ");
  Serial.println(readMux(0));
 Serial.print(":Y1 ");
  Serial.println((readMux(1)));
 Serial.print(":Y2 ");
  Serial.println((readMux(2)));
 Serial.print(":Y3 ");
  Serial.println((readMux(3)));
 Serial.print(":Y4 ");
  Serial.println((readMux(4)));
 Serial.print(":Y5 ");
  Serial.println((readMux(5)));
   Serial.print(":Y6 ");
  Serial.println((readMux(6)));
   Serial.print(":Y7 ");
  Serial.println((readMux(7)));
     Serial.print(":Y8 ");
  Serial.println((readMux(8)));
     Serial.print(":Y9 ");
     Serial.println((readMux(9)));
    Serial.print(":Y10 ");
 Serial.println ((readMux(10)));
     Serial.print(":Y11 ");
 Serial.println ((readMux(11)));
   Serial.print(":Y12 ");
 Serial.println ((readMux(12)));
   Serial.print(":Y13 ");
 Serial.println ((readMux(13)));
   Serial.print(":Y14 ");
 Serial.println ((readMux(14)));
   Serial.print(":Y15 ");
 Serial.println ((readMux(15)));

 
  delay(400);
  }

  }

  
int readMux(int channel){
  int controlPin[] = {s0, s1, s2, s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }
 int val_2 = (analogRead(SIG_pin));
   //return the value
  return val_2;
}