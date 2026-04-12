#include <stdio.h>

int main() {
  int r,g,b = 0;
  int x = 0;
  scanf("%d""%d""%d",&r,&g,&b);
  x = (100*r)+(10*g)+b;
  if(x % 4 == 0) {
    printf("YES\n");
  }else {
    printf("NO\n");
  }
} 