#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

  int r ,g ,b;
  int num;

  scanf("%d %d %d", &r, &g, &b);
  num = r*100+g*10+b;

  if(num%4 == 0) printf("YES\n");
  else printf("NO\n");

  return 0;
}