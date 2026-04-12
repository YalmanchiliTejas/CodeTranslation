#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c;
  int x,y;
  cin>>a>>b>>c>>x>>y;
  long long ans=0;
  int count=0;
  ans=(x*a)+(y*b);
  int d=((2*c)-(a+b));
  if(d<0)
  {
    ans+=(d*min(x,y));
    if(x<y && (2*c)<b)ans+=((2*c*(y-x))-((y-x)*b));
    else if(y>x && (2*c)<a)ans+=((2*c*(x-y))-((x-y)*b));
  }
  cout<<ans<<endl;
  return 0;
}