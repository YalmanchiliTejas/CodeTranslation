#include<cstdio>
using namespace std;
int x,y,z,ans;
int main()
{
  scanf("%d%d%d",&x,&y,&z);
  ans=x/(y+z);
  if (x%(y+z)<z) ans--;
  printf("%d\n",ans);
}
