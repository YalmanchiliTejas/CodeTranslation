#include <stdio.h>
int main(void)
{
  int r,g,b,sum;
  scanf("%d%d%d",&r,&g,&b);
  sum=r*100+g*10+b;
  if(sum%4==0)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}
