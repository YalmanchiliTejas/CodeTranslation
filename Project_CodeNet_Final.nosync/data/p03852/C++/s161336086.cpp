#include <stdio.h>

int main(void) {

  char x;

  scanf("%c", &x);

  if (x == 'a' || x == 'i' || x == 'e' || x == 'o' || x == 'u')
    printf("vowel\n");
  else
    printf("consonant\n");

  return 0;
}
