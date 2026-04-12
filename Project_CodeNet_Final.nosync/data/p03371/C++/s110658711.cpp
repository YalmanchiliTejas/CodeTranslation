#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rng(i,a,b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define repd(i, n) for(ll i = (ll)(n)-1;i>=0;--i)
#define rngd(i,b,a) for(ll i = (ll)(b);i>=a;--i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((ll)(x).size())

int main() {
  int ans=0;
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ans=a*x+b*y;
  int m=max(x,y);
  rep(i,2*m+1){
    int x1=(x-i/2>=0)?x-i/2:0;
    int y1=(y-i/2>=0)?y-i/2:0;
    ans=min(ans,a*x1+b*y1+c*(int)i);
    ++i;
  }
  cout<<ans<<endl;
  return 0;
}