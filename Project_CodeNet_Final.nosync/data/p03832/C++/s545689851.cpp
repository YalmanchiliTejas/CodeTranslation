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
#include <unordered_map>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << "[" << pa.first << ", " << pa.second << "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  os << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
  os << "}";
  return os;
}

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << std::endl

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

//非再帰累乗(mod付き)
ll pow_mod(ll a, ll b, ll mod=-1) {
  if ((a == 0)||(mod!=-1&&a%mod==0)) {
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

  ll n,a,b,c,d;
  std::cin>>n>>a>>b>>c>>d;

  std::vector<ll> facto(1010,1),factoinv(1010,1);
  rep(i,1,1010)facto[i]=(facto[i-1]*i)%MOD;
  rep(i,0,1010)factoinv[i]=pow_mod(facto[i],MOD-2,MOD);

  std::vector<std::vector<ll>> dp(b+2,std::vector<ll>(n+1,0));

  dp[a-1][0]=1;

  rep(i,a,b+1){
    rep(j,0,n+1){
      ll sum=dp[i-1][j];
      ll mul=pow_mod(facto[i],c,MOD);
      mul=pow_mod(mul,MOD-2,MOD);
      mul=(mul*facto[n-j+i*c])%MOD;
      mul=(mul*factoinv[n-j])%MOD;
      mul=(mul*factoinv[c])%MOD;
      rep(k,c,std::min(j/i+1,d+1)){
        sum=(sum+(dp[i-1][j-k*i]*mul)%MOD)%MOD;
        if(k+1<std::min(j/i+1,d+1)){
          mul=(mul*facto[n-j+i*k+i])%MOD;
          mul=(mul*factoinv[n-j+i*k])%MOD;
          mul=(mul*factoinv[i])%MOD;
          mul=(mul*facto[k])%MOD;
          mul=(mul*factoinv[k+1])%MOD;
        }
      }
      dp[i][j]=sum;
    }
  }

  std::cout<<dp[b][n];

  return 0;
}




