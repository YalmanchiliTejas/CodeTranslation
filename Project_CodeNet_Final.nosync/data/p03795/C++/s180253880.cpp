#include<stdio.h>
int main()
{
  int n,x,y;
  scanf("%d",&n);
  x=800*n;
  y=(n/15)*200;
  printf("%d\n",x-y);
  return 0;
}