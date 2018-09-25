#include <stdlib.h>

#include "disemvowel.h"

bool isVowel(char letter) {

  char *vowels = (char*) calloc(11, sizeof(char));
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
  bool isContained = false;
  int i;
  for (i=0; i < 10; i++) {
 	 if(vowels[i] == letter){
	  isContained = true;
  	 }
  }
  free(vowels);
  return isContained;
}

int numNonVowels(char *word) {
	//https://www.quora.com/How-do-I-find-the-length-of-an-array-in-C
	int length = sizeof(word)/sizeof(char);
	//start at 1 because of null terminator
	int result = 1;
	int i;
	for (i=0; i < length; i++) {
		if(!isVowel(word[i])){
			result++;
		}
	}
	return result;
}

void  removeVowels(char *str, char *result) {
	int length = sizeof(str)/sizeof(char);
	int i;
	int j = 0;
	for (i = 0; i < length; i++) {
		if (!isVowel(str[i])){
			result[j] = str[i];
			j++;
		}
	}
       result[j +1] = '\0';
}

char *disemvowel(char *str) {

  // find size of resulting array
  int size = numNonVowels(str);

  char *result = (char*) calloc(size, sizeof(char));

  removeVowels(str, result);

  return result;
}

