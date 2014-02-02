#include <MaxMatrix.h>

//PINS setup
#define PIN_DIN 8
#define PIN_CS	9
#define PIN_CLK	10
#define LED_MATRIX_COUNT 1
#define LED_MATRIX_INTENSITY 1

MaxMatrix maxMatrix(PIN_DIN, PIN_CS, PIN_CLK, LED_MATRIX_COUNT);

void setup()
{
	maxMatrix.init();
	maxMatrix.setIntensity(LED_MATRIX_INTENSITY);
}

void loop()
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{			
			maxMatrix.setDot(i, j, HIGH);
			delay(200);
		}
		delay(200);		
	}
	maxMatrix.clear();
}
