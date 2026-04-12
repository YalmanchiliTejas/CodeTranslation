#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll fact[2001], ifact[2001];
ll dp[2001][2001];
ll sum[2001];

ll modulo_inverse(ll n) {
  ll t = MOD - 2, p = 1, q = n;
  while(t > 0) {
    if(t % 2) p = (p * q) % MOD;
    q = (q * q) % MOD;
    t /= 2;
  }
  return p % MOD;
}

int main(void) {
  fact[0] = 1;
  REP(i, 1, 2001) fact[i] = (fact[i - 1] * i) % MOD;
  REP(i, 0, 2001) ifact[i] = modulo_inverse(fact[i]);

  while(1) {
    ll N, D, X;
    cin >> N >> D >> X;

    if(N == 0 && D == 0 && X == 0) break;

    REP(i, 0, N + 1) REP(j, 0, N + 1) dp[i][j] = 0;
    dp[0][0] = 1;

    REP(i, 0, N) {
      sum[0] = 0;
      REP(j, 0, N) sum[j + 1] = (sum[j] + dp[i][j]) % MOD;
      REP(j, 0, N + 1) dp[i + 1][j] = (sum[j] - sum[max(j - X + 1, 0LL)] + MOD) % MOD;
    }

    ll ans = 0;
    REP(i, 1, min(N, D) + 1) {
      ll comb = 1;
      for(ll j = D; j > D - i; j--) comb = (comb * (j % MOD)) % MOD;
      comb = (comb * ifact[i]) % MOD;
      ll x = (comb * dp[i][N]) % MOD;
      ans = (ans + x) % MOD;
    }
    cout << ans << endl;
  }
}

