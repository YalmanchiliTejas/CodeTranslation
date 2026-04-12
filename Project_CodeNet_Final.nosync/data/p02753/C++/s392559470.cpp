#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
char S[4];
  scanf("%s", &S);
  if (strcmp(S, "AAA") == 0 || strcmp(S, "BBB") == 0) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }
  return 0;
}