#include <stdio.h>
int main (void){
  int a,b,c,x,y,i,min;
  scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
  min = a * x + b * y;
  if (x >= y){
    i = c * 2 * y + (x - y) * a;
    if (i < min)
      min = i;
    if (c * 2 * x < min)
      min = c * 2 * x;
  }
  else {
    i = c * 2 * x + (y - x) * b;
    if (i < min)
      min = i;
    if (c * 2 * y < min)
      min = c * 2 * y;
  }
  printf("%d\n",min);
  return (0);
}
    
