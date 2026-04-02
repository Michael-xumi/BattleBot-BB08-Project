// Battlebot BB008
// Team IT-1D
// Michael O. Boeteng Student ID.5598168
// Jenjira Huaisai Student ID.5681502
// ======================================
// Assignment Week 3.2 Traffic Lights & Button
// ======================================
// Light will be red until a button is pressed
// Then, turn green after 1 second,
// Then, stay green for 3 seconds,
// Then, turn yellow for 1 second
// Then back to red and stay red until the button is pressed again
// ======================================

// LED PINS
#define RED_LED 8
#define YELLOW_LED 9
#define GREEN_LED 10

// BUTTON
#define BUTTON_PIN 2 

// SET UP
void setup()
{
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    digitalWrite(RED_LED, LOW);      
    digitalWrite(YELLOW_LED, HIGH);  
    digitalWrite(GREEN_LED, HIGH);   
}

// LOOP
void loop()
{
    if (digitalRead(BUTTON_PIN) == LOW)
    {
        delay(50); // small debounce

        if (digitalRead(BUTTON_PIN) == LOW)
        {
            // GREEN ON
            digitalWrite(RED_LED, HIGH);    
            digitalWrite(GREEN_LED, LOW);   
            delay(3000);

            // YELLOW ON
            digitalWrite(GREEN_LED, HIGH);  
            digitalWrite(YELLOW_LED, LOW);  
            delay(1000);

            // RED ON
            digitalWrite(YELLOW_LED, HIGH); 
            digitalWrite(RED_LED, LOW);     
        }
    }
}