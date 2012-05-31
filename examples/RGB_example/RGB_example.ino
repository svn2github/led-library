#include <RGB.h>

RGB * lamp  =  new RGB( 2, true ); 

// Or create an Array of LEDs
// RGB * lamps[10]; 

void setup()
{
/** In case of an array, initialize it
  for (int i=0; i < 10; i++) {
      lamps[i] = new RGB( );
  }
**/
  lamp->intensityTo( 255, 1000 ); // Make sure the light is turned on so we can see what is happening
  lamp->saturationTo( 255, 1000 ); // make sure we can see Hue changes
}

void loop()
{
  if( !lamp->isAnimating()) // Returns true if the LED is in an animation
  {
    if (lamp->getHue() == 0) // Returns the current RGB Value of the LED
    {
      lamp->hueTo( 255, 2000 ); // Sets the desired RGB value and the time (in millis) it should take to get there
    }
    else {
      lamp->hueTo( 0, 2000 );
    }
  }
  /**
  You may also use these functions
  hsbTo( 255, 255, 255, 2000 ); // byte h, byte s, byte b, long duration
  rgbTo( 255, 255, 255, 2000 ); // byte r, byte g, byte b, long duration
  **/
  
  // Always call the update function; if autoWrite is on, the Arduino will write the current intensity to the set channel 
  lamp->update();
  
  /**
  // If autoWrite is OFF, manually set the desired value
  // In this case we write to arduino pins; but you can use this for instance to control DMX lighting
  analogWrite( lamp->getChannelRed(),   lamp->getRed() );
  analogWrite( lamp->getChannelGreen(), lamp->getGreen() );
  analogWrite( lamp->getChannelBlue(),  lamp->getBlue() );
  **/
  
  /**
  // You can request the current values (also during animations) if you like
  Serial.print("Hue: "          + String( lamp->getHue() , DEC ) + "\t");
  Serial.print("Saturation: "   + String( lamp->getSaturation() , DEC ) + "\t");
  Serial.println("Brightness: " + String( lamp->getIntensity() , DEC ));

  Serial.print("r: "   + String( lamp->getRed() , DEC ) + "\t");
  Serial.print("g: "   + String( lamp->getGreen() , DEC ) + "\t");
  Serial.println("b: " + String( lamp->getBlue() , DEC ));
  delay(40);
  **/
}