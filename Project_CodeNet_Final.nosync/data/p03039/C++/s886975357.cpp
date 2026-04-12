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
  ll sh1 ,sh2;
  ll h = mod-2;
  ll two;
  while(h>0) {
    two = 1;
    sh1 = frac[b];
    sh2 = frac[a-b];
    while(2*two<h) {
      two *= 2;
      sh1 *= sh1;
      sh2 *= sh2;
      sh1 %= mod;
      sh2 %= mod;
    }
    h -= two;
    ue *= sh1;
    ue %= mod;
    ue *= sh2;
    ue %= mod;
  }
  return ue;
}

int main() {
  frac[0] = 1;
  for(ll i=1;i<200005;++i) frac[i] = frac[i-1]*i%mod;
  ll N, M, K;
  cin>>N>>M>>K;
  ll dist = 0;
  for(ll i=0;i<N;++i) {
    dist += i*(i+1)/2%mod*M%mod*M%mod;
    dist += (N-1-i)*(N-i)/2%mod*M%mod*M%mod;
    dist %= mod;
  }
  for(ll i=0;i<M;++i) {
    dist += i*(i+1)/2%mod*N%mod*N%mod;
    dist += (M-1-i)*(M-i)/2%mod*N%mod*N%mod;
    dist %= mod;
  }
  ll h = mod - 2;
  ll two;
  ll tmp;
  while(h>0) {
    tmp = 2;
    two = 1;
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

