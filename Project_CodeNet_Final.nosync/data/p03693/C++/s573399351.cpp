#include <stdio.h>

int main() {
  int r, g, b, result;
  scanf("%d%d%d", &r, &g, &b);

  result = (r*100 + g*10 + b)%4;
    	
  if (result == 0) {
    printf("YES\n");
  }else {
    printf("NO\n");
  }
  return 0;
}