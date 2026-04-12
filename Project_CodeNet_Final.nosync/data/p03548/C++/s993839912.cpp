#include<stdio.h>
int main()
{
  int X,Y,Z,P;
  while(scanf("%d %d %d",&X,&Y,&Z)!=EOF)
  {
    P=(X-Z)/(Y+Z);
    printf("%d\n",P);
  }
  return 0;
}