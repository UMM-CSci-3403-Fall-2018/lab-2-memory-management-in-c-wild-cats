#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "palindrome.h"

char *str_reverse(char const *str) {
  int len, i;
  char *result;

  len = strlen(str);
  result = (char*) calloc(len+1, sizeof(char));
  for (i=0; i<len; ++i) {
    result[i] = str[len-i-1];
  }
  result[len] = '\0';
  
  return result;
}

char *palindrome(char const *str) {
  char *rev;
  int i;
  bool result = true;
  char *answer;

  rev = str_reverse(str);
  i = 0;
  while (result && str[i]) {
    if (str[i] != rev[i]) {
      result = false;
    }
    ++i;
  }

  free(rev);

  if (result) {
    answer = (char*) calloc(4, sizeof(char));
    answer[0] = 'Y';
    answer[1] = 'e';
    answer[2] = 's';
    answer[3] = '\0';
  } else {
    answer = (char*) calloc(3, sizeof(char));
    answer[0] = 'N';
    answer[1] = 'o';
    answer[2] = '\0';
  }

  return answer;

}

/* 1 bytes in 1 blocks are definitely lost in loss record 1 of 50
* ==1659==    at 0x4C2FA50: calloc (vg_replace_malloc.c:711)
* ==1659==    by 0x402392: str_reverse(char const*) (palindrome.c:12)
* ==1659==    by 0x402402: palindrome(char const*) (palindrome.c:27)
* ==1659==    by 0x4013AE: is_palindrome(char const*) (palindrome_test.cpp:6)
* ==1659==    by 0x4015C9: Palindrome_HandlesEmptyString_Test::TestBody() (palindrome_test.cpp:14)
*/
