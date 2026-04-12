#include <bits/stdc++.h>
using namespace std;

int main() {
  long int a,b,c,d,x,y,ans;
  cin>>a>>b>>c>>x>>y;
  if(x>=y)d=a;
  else d=b;
  
  if((a+b)/2<c)ans=a*x+b*y;
  else if(d/2<c) ans=2*c*min(x,y)+d*abs(x-y);
  else ans=2*c*max(x,y);
  
  cout<<ans<<endl;
}
