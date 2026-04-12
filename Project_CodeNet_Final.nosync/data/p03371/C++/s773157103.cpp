#include <cstdio>
#include <algorithm>

int a,b,c,x,y;
long long ans;

int main()
{
  scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
  if(2*c>=a+b)
    {
      ans=1ll*a*x+1ll*b*y;
    }
  else
    {
      int minnum=std::min(x,y);
      x-=minnum;
      y-=minnum;
      ans=1ll*minnum*2*c;
      if(x>y)
	{
	  std::swap(x,y);
	  std::swap(a,b);
	}
      ans+=std::min(1ll*2*y*c,1ll*y*b);
    }
  printf("%lld\n",ans);
  return 0;
}
