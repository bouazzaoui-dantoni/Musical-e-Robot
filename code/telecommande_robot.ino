/** Source : http://www.codebender.cc **/

//Motor A
const int motorPin1  = 9;  // Pin 14 of L293
const int motorPin2  = 10;  // Pin 10 of L293
//Motor B
const int motorPin3  = 6; // Pin  7 of L293
const int motorPin4  = 5;  // Pin  2 of L293
//Motor C
const int motorPin5 = 3;
const int motorPin6 = 11;

//This will run only one time.


#include <SoftwareSerial.h>  //Software Serial Port  
#define RxD 8    //Pin 10 pour RX, PB2 sur votre board, a brancher sur le TX du HC-06
#define TxD 7    //Pin 11 pour TX, PB3 sur votre board, a brancher sur le RX du HC-06
SoftwareSerial BTSerie(RxD,TxD);  

void setup(){
    Serial.begin(9600);
    // Configuration du bluetooth  
  pinMode(RxD, INPUT);  
  pinMode(TxD, OUTPUT); 
  pinMode(13,OUTPUT); 
  BTSerie.begin(9600); 
    Serial.println("En attente de la commandes AT"); 
    delay(100);
  // Test des commandes AT  
  BTSerie.print("AT+VERSION");  //Demande le NÂ° de version 
  delay(1000);  
  
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(motorPin5, OUTPUT);
    pinMode(motorPin6, OUTPUT);
    
}



//Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4 & Motor C: motorpin5,motorpin6

void forward() {
  
    //The robot moves forward.   
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    analogWrite(motorPin5, 0);
    analogWrite(motorPin6, 0);
    
}


void right() {
  
    //The robot turns right.
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    analogWrite(motorPin5, 180);
    analogWrite(motorPin6, 0);
    
}

 void left() {
  
    //The robot turns left.
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    analogWrite(motorPin5, 0);
    analogWrite(motorPin6, 180);
    
}

void stop() {

    //The robot stops
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
    analogWrite(motorPin5, 0);
    analogWrite(motorPin6, 0);
}

void loop() {
  char recvChar;
  if (BTSerie.available()) {  
    recvChar = BTSerie.read(); //lecture
    if(recvChar=='U'){
      forward();  
    }
    else if(recvChar=='R'){
      right();
    }
    else if (recvChar=='L'){
      left();
    } 

    else if (recvChar=='s') {
      stop();
    }
  }
}