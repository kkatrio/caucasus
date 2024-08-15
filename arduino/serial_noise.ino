String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int pinDpiezo = 8;
int pinDSiren = 9; // TODO
bool alarmRaised = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
   
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(20);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);


    if (inputString == "on\n") {
       Serial.println(inputString);
       digitalWrite(LED_BUILTIN, HIGH);
       alarmRaised = true;
    }
    else if (inputString == "off\n") {
      Serial.println(inputString);
      digitalWrite(LED_BUILTIN, LOW);
      alarmRaised = false;
    }
   
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

  if (alarmRaised){
    tone(pinDpiezo, 700, 100);
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
