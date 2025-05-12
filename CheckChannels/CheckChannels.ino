#define CH1_PIN 2 // Use the digital input pin you connected CH1 to
#define CH2_PIN 3 // Use the digital input pin you connected CH2 to
#define CH3_PIN 4
#define CH4_PIN 5
#define CH5_PIN 6
#define CH6_PIN 7
// Define more pins for additional channels if needed

void setup() {
  pinMode(CH1_PIN, INPUT);
  pinMode(CH2_PIN, INPUT);
  pinMode(CH3_PIN, INPUT);
  pinMode(CH4_PIN, INPUT);
  pinMode(CH5_PIN, INPUT);
  pinMode(CH6_PIN, INPUT);
  // Set other channel pins as INPUT if needed
  Serial.begin(9600);
}

void loop() {
  // Read PWM values from the receiver
  int ch1Value = pulseIn(CH1_PIN, HIGH);
  int ch2Value = pulseIn(CH2_PIN, HIGH);
  int ch3Value = pulseIn(CH3_PIN, HIGH);
  int ch4Value = pulseIn(CH4_PIN, HIGH);
  int ch5Value = pulseIn(CH5_PIN, HIGH);
  int ch6Value = pulseIn(CH6_PIN, HIGH);
  // Read values from other channels if needed

  // Print the PWM values to Serial Monitor
  Serial.print("CH1: ");
  Serial.print(ch1Value);
  Serial.print(" CH2: ");
  Serial.print(ch2Value);
  Serial.print(" CH3: ");
  Serial.print(ch3Value);
  Serial.print(" CH4: ");
  Serial.print(ch4Value);
  Serial.print(" CH5: ");
  Serial.print(ch5Value);
  Serial.print(" CH6: ");
  Serial.println(ch6Value);
  // Print values from other channels if needed

  // Add your code here to process the PWM values as per your requirements

  delay(500); // Add a small delay to avoid flooding the Serial Monitor
}
