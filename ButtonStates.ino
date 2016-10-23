
// This app will publish an event from Particle Electron board when a button is pressed.
// It will identify the appropriate button.

int button1 = D0; // Button 1 is connected here.
int button2 = D1; // Button 2 is connected here.
int boardLed = D7; // This is the LED that is already on your device.

int val_button1 = 0;
int val_button2 = 0;

void setup() {
 
  pinMode(button1,INPUT_PULLDOWN); // set as input
  pinMode(button2,INPUT_PULLDOWN);  // set as input
  pinMode(boardLed,OUTPUT); // Our on-board LED is output 

}

void loop() {
 
   val_button1 = digitalRead(button1); 

         if (val_button1 == HIGH) {
             // Publish to Particle cloud
            Spark.publish("PRESSED","CHECK_IN",60,PRIVATE);
            // And flash the on-board LED on and off.
            digitalWrite(boardLed,HIGH);
            delay(1000);
            digitalWrite(boardLed,LOW);
            val_button1 = LOW;
        
         }
         
     val_button2 = digitalRead(button2); 

         if (val_button2 == HIGH) {
             // Publish to Particle cloud
            Spark.publish("PRESSED","CHECK_OUT",60,PRIVATE);
            // And flash the on-board LED on and off.
            digitalWrite(boardLed,HIGH);
            delay(1000);
            digitalWrite(boardLed,LOW);
            val_button2 = LOW;
        
         }
         
    
  }
