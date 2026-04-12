#include <stdio.h>

int main(void) {
  int r, g, b;
  scanf("%d%d%d", &r, &g, &b);
  if(!((g * 10 + b) % 4)) printf("YES");
  else printf("NO");
  return 0;
}
