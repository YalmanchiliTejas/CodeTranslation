#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int d=min(x,y);
  int ans=0;
  if(a+b>2*c) ans+=2*c*d;
  else ans+=d*(a+b);
  if(y>=x){
    y-=d;
    ans+=min(b*y,y*2*c);
  }
  else{
    x-=d;
    ans+=min(a*x,x*2*c);
  }
  cout<<ans<<endl;
}
