#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  ll ans=1e9;
  for(int i=0;i<=max(x,y);i++){
    ll cnt=c*i*2+max(0,a*(x-i))+max(0,b*(y-i));
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}