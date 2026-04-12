#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  printf("%d00", 8 * n - n / 15 * 2);
  return 0;
}