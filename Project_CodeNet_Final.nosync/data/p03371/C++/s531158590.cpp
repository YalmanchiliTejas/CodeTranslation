#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y,z,ans;
  cin>>a>>b>>c>>x>>y;
  z=min(x,y);
  ans=min(a+b,2*c)*z;
  x-=z;
  y-=z;
  if(x>0) ans+=min(a,2*c)*x;
  else if(y>0) ans+=min(b,2*c)*y;
  cout<<ans<<endl;
}