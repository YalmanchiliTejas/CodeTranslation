#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c,x,y,ans,m,M;
  cin>>a>>b>>c>>x>>y;
  m=min(x,y);
  M=max(x,y);
  cin>>a>>b>>c>>x>>y;
  ans=a*x+b*y;
  ans=min(ans,2*c*m+(x-m)*a+(y-m)*b);
  ans=min(ans,2*c*M);
  cout<<ans;
}