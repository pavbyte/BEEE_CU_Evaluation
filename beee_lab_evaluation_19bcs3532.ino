int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;
void setup()
{
  pinMode(4, INPUT);
  Serial.begin(9600);

  pinMode(13, OUTPUT);
}

void loop()
{
  // read the pushbutton input pin
  buttonState = digitalRead(4);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH, then the button
      // went from off to on
      digitalWrite(13,HIGH);
      delay(20);
      digitalWrite(13,LOW);
      buttonPushCounter += 1;
      Serial.println("ball hit the goal post");
      Serial.print("total point: ");
      Serial.println(buttonPushCounter);
    }
    // delay a little bit to avoid debouncing
    delay(50); // Wait for 50 millisecond(s)
  }
}
