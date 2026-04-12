#include <algorithm>
#include <cstdlib>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <queue>
typedef long long ll;

#include <set>

using namespace std;

const ll mod = 1000000007;
const int MAX = 1024;
ll fact[MAX];
ll rfact[MAX];
ll rt[MAX];

ll mpow(ll b, ll e) {
  ll r = 1;
  while (e) {
    if(e % 2 == 1) r = (r * b) % mod;
    e /= 2;
    b = (b * b) % mod;
  }
  return r;
}

int main(){
  const int n = getInt();
  const int a = getInt();
  const int b = getInt();
  const int c = getInt();
  const int d = getInt();

  fact[0] = 1; REP(i,MAX - 1) fact[i + 1] = (fact[i] * (i + 1)) % mod;
  REP(i,MAX) rfact[i] = mpow(fact[i], mod - 2);
  REP(i,MAX) rt[i] = mpow(i, mod - 2);

  vector<ll> dp(n + 1);
  dp[n] = 1;

  for(int i = a; i <= b; i++) {
    vector<ll> next(n + 1);

    for(int j = 0; j <= n; j++) {
      next[j] = (next[j] + dp[j]) % mod;

      if(c * i > j || dp[j] == 0) continue;

      ll div = mpow(rfact[i], c);
      for(int k = c; k <= d && k * i <= j; k++) {
        const ll m = (((fact[j] * rfact[j - k * i]) % mod * div) % mod) * rfact[k] % mod;
        next[j - k * i] = (next[j - k * i] + dp[j] * m) % mod;
        div = (div * rfact[i]) % mod;
      }
    }

    dp.swap(next);
  }

  printf("%lld\n", dp[0]);
  return 0;
}
