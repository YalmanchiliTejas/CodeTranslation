#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=(b-1);i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

long long modpow(long long a, long long b) {
  long long r = 1LL;

  while (b) {
    if (b & 1LL)r *= a;
    if (r >= MOD)r %= MOD;
    a *= a;
    if (a >= MOD)a %= MOD;
    b >>= 1LL;
  }
  return r;
}

#define N_MAX 2001

long long fact[N_MAX];
long long rfact[N_MAX];

long long nCr(long long n, long long r) {
  long long ret = 1LL;
  ret *= fact[n];
  ret %= MOD;
  ret *= rfact[r];
  ret %= MOD;
  ret *= rfact[n - r];
  ret %= MOD;
  return ret;
}

long long nPr(long long n, long long r) {
  long long ret = 1LL;
  ret *= fact[n];
  ret %= MOD;
  ret *= rfact[n - r];
  ret %= MOD;
  return ret;
}

ll dp[1010][1010];

int main() {
  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  clr(fact, 0);
  fact[0] = 1;
  rep(i, 1, N_MAX) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }
  clr(rfact, 0);
  rfact[0] = 1;
  rep(i, 1, N_MAX) {
    rfact[i] = rfact[i - 1] * modpow(i, MOD - 2);
    rfact[i] %= MOD;
  }
  clr(dp,0);
  dp[0][0] = 1;
  rep(i,1,n+1){
    rep(j,0,n+1){
      dp[i][j] += dp[i-1][j];
      dp[i][j] %= MOD;
      if(i<a||b<i)continue;
      rep(k,1,n+1){
        if(k<c||d<k)continue;
        if(n-j<i*k)break;
        if(j+i*k>1005)break;
        dp[i][j+i*k] += (((dp[i-1][j]*nPr(n-j,i*k)%MOD)*modpow(rfact[i],k)%MOD)*rfact[k]%MOD);
        dp[i][j+i*k] %= MOD;
      }
    }
  }
  cout << dp[b][n] << endl;
  return 0;
}



