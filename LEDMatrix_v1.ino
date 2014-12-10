#include <MaxMatrix.h>

// nastavenie pinov, ku ktorym je pripojeny integrovany obvod MAX7219
#define PIN_DIN 8
#define PIN_CS	9
#define PIN_CLK	10
// pocet displejov pripojenych k IO MAX7219
#define LED_MATRIX_COUNT 1
// hodnota jasu/svietivosti
#define LED_MATRIX_INTENSITY 1

// vytvorenie instancie MaxMatrix
MaxMatrix maxMatrix(PIN_DIN, PIN_CS, PIN_CLK, /* Pocet zapojenych displejov */LED_MATRIX_COUNT);

void setup()
{
	// inicializacia kniznice MaxMatrix
	maxMatrix.init();
	maxMatrix.setIntensity(LED_MATRIX_INTENSITY);	//nastavenie intenzity
}

void loop()
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			maxMatrix.setDot(/* stlpec => */i, /* riadok => */j, /* hodnota => */HIGH); /* rozsvietenie konkretnej LEDky */
			delay(200);
		}
		delay(200);
	}
	maxMatrix.clear(); 	// vypnutie svetkych LED
}
