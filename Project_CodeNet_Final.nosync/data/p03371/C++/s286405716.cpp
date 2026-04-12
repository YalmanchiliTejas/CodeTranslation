#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,x,y,p,ans,q,r;
  cin>>a>>b>>c>>x>>y;
  p=max(x,y);
  p=p*2*c;
  if(x<y){
    q=2*c*x+(y-x)*b;
  }
  else{
    q=2*c*y+(x-y)*a;
  }
  r=a*x+b*y;
  ans=min(p,q);
  ans=min(ans,r);
  cout<<ans;
}