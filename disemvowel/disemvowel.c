#include <stdlib.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
	


  return (char*) "";
}

bool isVowel(char *letter) {
  char *vowels = calloc(11, sizeof(char));
  vowels[0] = 'a';
  vowels[1] = 'e';
  vowels[2] = 'i';
  vowels[3] = 'o';
  vowels[4] = 'u';
  vowels[5] = 'A';
  vowels[6] = 'E';
  vowels[7] = 'I';
  vowels[8] = 'O';
  vowels[9] = 'U';
  vowels[10] = '\0';

  // referenced: https://stackoverflow.com/questions/15094834/check-if-a-value-exist-in-a-array
  int i;
  for (i=0; i < 10; i++) {
 	 if(vowels[i] == letter){
 	  free(vowels);
	  return true;
  }
  }
  free(vowels);
  return false;
}
