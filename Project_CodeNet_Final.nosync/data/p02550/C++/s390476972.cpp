#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vc=vector<char>;
using vvc=vector<vc>;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  ll N,X;
  int M;
  cin >> N >> X >> M;
  
  vl check(M);
  ll ans=0;
  ll l=0,r=0;
  for(ll i=1;i<N+1;i++) {
    if(check[X]) {
      l=check[X];
      r=i;
      break;
    }
    else {
      check[X]=i;
      ans+=X;
      (X*=X)%=M;
    }
  }
  if(l==0) cout << ans << endl;
  else {
    ll K=(N-l+1)/(r-l),R=(N-l+1)%(r-l);
    ll A=0,B=0;
    for(ll i=0;i<r-l;i++) {
      A+=X;
      if(i==R-1) B=A;
      (X*=X)%=M;
    }
    cout << ans+A*(K-1)+B << endl;
  }
}