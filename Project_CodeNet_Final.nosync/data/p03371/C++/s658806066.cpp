#include<stdio.h>

int main()
{
  long a,b,c,x,y;
  
  scanf("%ld%ld%ld%ld%ld",&a,&b,&c,&x,&y);
  
  long long ans=0;
  if(a+b<=2*c)
  {
    ans=a*x+b*y;
  }
  else
  {
    int max=(x>y)?x:y;
    int min=(max==x)?y:x;
    int rest=(max==x)?a:b;
    
    int tmp1=c*2*max;
    int tmp2=c*2*min+rest*(max-min);
    
    if(tmp1<tmp2)
    {
      ans=tmp1;
    }
    else
    {
      ans=tmp2;
    }
  }
  
  printf("%lld\n",ans);
  return 0;
}