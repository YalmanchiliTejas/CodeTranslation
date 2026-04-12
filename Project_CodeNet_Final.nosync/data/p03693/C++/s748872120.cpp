#include <stdio.h>

int main(void) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%s\n", (a*100 + b*10 + c) % 4 == 0 ? "YES" : "NO");

  return 0;
}
