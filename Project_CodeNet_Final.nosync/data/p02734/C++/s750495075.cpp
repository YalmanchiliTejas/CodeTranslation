#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using namespace std;

const ll mod = 998244353;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

ll N, S;
ll A[3010];
mint dp[3010][3010][3];

int main()
{
  scanf( "%lld%lld", &N, &S );
  
  rep( i, N )
    scanf( "%lld", A+i );

  dp[0][0][0] = 1;

  rep( i, N ) rep( j, S+1 )
  {
    dp[i+1][j][0] += dp[i][j][0];
    dp[i+1][j][1] += dp[i][j][0]+dp[i][j][1];
    dp[i+1][j][2] += dp[i][j][0]+dp[i][j][1]+dp[i][j][2];

    if( j+A[i] <= S )
    {
      dp[i+1][j+A[i]][1] += dp[i][j][0]+dp[i][j][1];
      dp[i+1][j+A[i]][2] += dp[i][j][0]+dp[i][j][1];
    }
  }

  printf( "%lld\n", dp[N][S][2].x );

  return 0;
}