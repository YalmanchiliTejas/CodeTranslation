#include <stdio.h>
int main(void)
{
  char c;
  scanf("%c",&c);
  switch(c)
  {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':printf("vowel\n"); break;
    default : printf("consonant\n"); break;
  }
  return 0;
}
