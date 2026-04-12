#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  int ans=1e9;
  rep(i,2*max(x,y)){
    int cnt=2*i*c+max(x-i,0)*a+max(y-i,0)*b;
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}