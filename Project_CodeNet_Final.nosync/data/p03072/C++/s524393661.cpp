#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i;
  int N;
  int H[100];
  int num;
  int max;

  scanf("%d", &N);
  // printf("%d\n", N);
  for (i = 0; i < N; i++) {
    scanf("%d", H + i);
    // printf("%d\n", H[i]);
  }

  num = 1;
  max = H[0];
  for (i = 0; i < N - 1; i++) {
    if (max <= H[i + 1]) {
      num += 1;
      max = H[i + 1];
    } else {
      // break;
    }
  }

  printf("%d\n", num);
  fflush(stdout);
  return 0;
}
