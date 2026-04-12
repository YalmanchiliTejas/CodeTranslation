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
  ll ue=frac[a], sh1=1, sh2=1;
  ll tmp1, tmp2;
  ll h=mod-2;
  ll two;
  while(h>0) {
    two = 1;
    tmp1 = frac[a-b];
    tmp2 = frac[b];
    while(2*two<h) {
      two *= 2;
      tmp1 *= tmp1;
      tmp1 %= mod;
      tmp2 *= tmp2;
      tmp2 %= mod;
    }
    h -= two;
    sh1 *= tmp1;
    sh1 %= mod;
    sh2 *= tmp2;
    sh2 %= mod;
  }
  return ue*sh1%mod*sh2%mod;
}

int main() {
  frac[0] = 1;
  for(ll i=1;i<200005;++i) frac[i] = frac[i-1]*i%mod;
  ll N, M, K;
  cin>>N>>M>>K;
  ll ans = 0;
  for(ll i=0;i<N;++i) {
    ans += i*(i+1)/2%mod*M%mod*M%mod;
    ans %= mod;
    ans += (N-(i+1))*(N-(i+1)+1)/2%mod*M%mod*M%mod;
    ans %= mod;
  }
  for(ll i=0;i<M;++i) {
    ans += i*(i+1)/2%mod*N%mod*N%mod;
    ans %= mod;
    ans += (M-(i+1))*(M-(i+1)+1)/2%mod*N%mod*N%mod;
    ans %= mod;
  }
  ll two, h=mod-2;
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
    ans *= tmp;
    ans %= mod;
  }
  cout<<ans*comb(N*M-2, K-2)%mod<<endl;
}

