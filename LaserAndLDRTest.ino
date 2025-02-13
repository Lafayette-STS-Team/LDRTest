int laserPin = 7;
int laserState = HIGH;

const int PhotoDiode_Detector = A1;
float PhotoDiode_Value = 0.0;

float voltage = 0.0;

unsigned long previousMillis = 0;
const long interval = 50; // ms

void setup() {  
  Serial.begin(9600);    
  millis();         
  pinMode(laserPin, OUTPUT);  // Define the digital output interface pin 13 
  
}

void loop() {
//  unsigned long currentMillis = millis();
//  if (currentMillis - previousMillis >= interval) {
//    previousMillis = currentMillis;
//
//    if (laserState == LOW){
//      laserState = HIGH;
//    }
//    else {
//      laserState = LOW;
//    }  
//  }
  digitalWrite(laserPin, laserState);
  
  PhotoDiode_Value = analogRead(PhotoDiode_Detector);
  voltage = PhotoDiode_Value*(5.0/1023.0);
  
  Serial.print(PhotoDiode_Value);
  Serial.print("\t");
  Serial.print(voltage);
  Serial.println();
}
