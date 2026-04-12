#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
long N, M;
  
  scanf("%ld %ld", &N, &M);
  if (N == M) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}