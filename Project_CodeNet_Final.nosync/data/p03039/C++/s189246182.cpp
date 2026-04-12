#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll frac[200005];

ll comb(ll a, ll b) {
  ll ue = frac[a];
  ll shita1=1, shita2=1;
  ll tmpshita1, tmpshita2;
  ll h=mod-2;
  ll two;
  while(h>0) {
    two = 1;
    tmpshita1 = frac[b];
    tmpshita2 = frac[a-b];
    while(2*two<h) {
      two *= 2;
      tmpshita1 *= tmpshita1;
      tmpshita2 *= tmpshita2;
      tmpshita1 %= mod;
      tmpshita2 %= mod;
    }
    h -= two;
    shita1 *= tmpshita1;
    shita2 *= tmpshita2;
    shita1 %= mod;
    shita2 %= mod;
  }
  return ue*shita1%mod*shita2%mod;
}

int main() {
  frac[0] = 1;
  for(ll i=1;i<200005;++i) {
    frac[i] = frac[i-1]*i%mod;
  }
  ll N, M, K;
  cin>>N>>M>>K;
  ll dist = 0;
  for(ll i=0;i<N;++i) {
    dist += (N-1-i)*(N-i)/2%mod*M%mod*M%mod;
    dist %= mod;
    dist += i*(i+1)/2%mod*M%mod*M%mod;
    dist %= mod;
  }
  for(ll j=0;j<M;++j) {
    dist += (M-1-j)*(M-j)/2%mod*N%mod*N%mod;
    dist %= mod;
    dist += j*(j+1)/2%mod*N%mod*N%mod;
    dist %= mod;
  }
  ll h = mod - 2;
  ll two;
  ll tmp;
  while(h>0) {
    two = 1;
    tmp = 2;
    while(2*two<h) {
      two *= 2;
      tmp *= tmp;
      tmp %= mod;
    }
    h -= two;
    dist *= tmp;
    dist %= mod;
  }
  cout<<dist*comb(N*M-2, K-2)%mod<<endl;
}

