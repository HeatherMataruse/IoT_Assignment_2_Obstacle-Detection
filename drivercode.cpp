//author Heather Mataruse
// this code shows the stimulation of a smart blind cane
//IoT_Assignment_2_Obstacle Detection

//this code controls the stimulation of a smart blind cane

// here I am seting the variables of the differents pins
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

//here are extra variables for the time the led light will blick
// and the distance that the buzzer will make a sound to if the 
//distance is less than 60cm
long duration;
int distance;
int safetyDistance; 


void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}


void loop() {
  
digitalWrite(trigPin, LOW);
 // Wait for 1000 millisecond(s)
delayMicroseconds(2); 
  
digitalWrite(trigPin, HIGH);
 // Wait for 1000 millisecond(s)
delayMicroseconds(1000);
digitalWrite(trigPin, LOW);
  
duration = pulseIn(echoPin, HIGH);
  
distance= duration*0.034/2;
  
safetyDistance = distance;
 //This function detects whether the object is below or above 60cm
  // and the buzzer turns on if the distance is <60
  //and the led light blicks after every second
if (safetyDistance <60){ 
  tone(buzzer,1000);
  digitalWrite(ledPin, HIGH); 
  delay(1000); 
  digitalWrite(ledPin, LOW);
  delay(1000); 
}
  //from here the busser or the led light is not on because the distance
  //is >60cm
else{ 
  noTone(buzzer);
  	digitalWrite(ledPin, LOW); 
  Serial.print("You are in a safe distance ");
}
//here I am just printing out the distance just in case
  //but the distnce will already be shown when the stimulation starts
Serial.print("The distance is: "); 
Serial.println(distance); 
}
  
