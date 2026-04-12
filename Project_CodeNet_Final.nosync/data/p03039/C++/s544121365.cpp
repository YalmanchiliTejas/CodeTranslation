#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug "<< i << std::endl

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

//非再帰累乗(mod付き)
ll pow_mod(ll a, ll b, ll mod=-1) {
  if ((a == 0)||(mod==-1&&a%mod==0)) {
    return 0;
  }

  ll x = 1;

  while (b > 0) {
    if (b & 1) {
      x = (mod!=-1)?(x * a) % mod:x*a;
    }
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,m,k,ans=0;
  std::cin>>n>>m>>k;

  std::vector<ll> facto(n*m);

  facto[0]=1;
  rep(i,1,n*m)facto[i]=(facto[i-1]*i)%MOD;

  rep(i,1,n)ans=(ans+(n-i)*m*m*i)%MOD;
  rep(i,1,m)ans=(ans+(m-i)*n*n*i)%MOD;

  ans=(ans*facto[n*m-2])%MOD;
  ans=(ans*pow_mod(facto[n*m-k],MOD-2,MOD))%MOD;
  ans=(ans*pow_mod(facto[k-2],MOD-2,MOD))%MOD;

  std::cout<<ans;

  return 0;
}
