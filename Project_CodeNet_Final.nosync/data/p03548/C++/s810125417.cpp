#include <stdio.h>
int main(void)
{
  int x,y,z,ans=0;
  scanf("%d%d%d",&x,&y,&z);
  ans=x/(y+z);
  if(x%(y+z)<z)
  {
    ans--;
  }
  printf("%d\n",ans);
  return 0;
}
