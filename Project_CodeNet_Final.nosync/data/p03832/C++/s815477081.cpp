#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

ll pow(ll a, ll b, ll mod) {
  ll ret = 1;
  ll tmp = a;
  while (b) {
    if (b % 2) {
      ret = ret * tmp % mod;
    }
    tmp = tmp * tmp % mod;
    b /= 2;
  }
  return ret;
}

ll inverse(ll a, ll mod) {
  return pow(a, mod - 2, mod);
}

const ll MOD = 1000000007;

int main() {
  ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  vvi dp(N + 1, vi(N + 1));

  vvi P(N + 1, vi(N + 1));
  for (ll i = 0; i <= N; i++) {
    ll k = 1;
    for (ll j = 0; j <= N; j++) {
      P[i][j] = k;
      k = k * (i - j) % MOD;
    }
  }

  for (ll i = 0; i <= N; i++) dp[A - 1][0] = 1;
  for (ll i = A; i <= B; i++) {
    for (ll j = 0; j <= N; j++) {
      for (ll k = 0; j - k * i >= 0; k++) {
        if (k == 0 || (C <= k && k <= D)) {
          dp[i][j] += dp[i - 1][j - k * i] * P[N - j + k * i][k * i] % MOD * inverse(pow(P[i][i], k, MOD), MOD) % MOD * inverse(P[k][k], MOD) % MOD;
          dp[i][j] %= MOD;
        }
      }
    }
  }
  cout << dp[B][N] << endl;
}
