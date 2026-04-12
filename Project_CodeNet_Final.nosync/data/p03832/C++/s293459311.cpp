#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 1000000007;
ll N, A, B, C, D;
ll dp[1010][1010];
ll inv[1010];
ll fac[1010], invFac[1010];

void init() {
  fac[0] = fac[1] = 1;
  invFac[0] = invFac[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < 1010; i++) {
    inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    fac[i] = i * fac[i-1] % MOD;
    invFac[i] = inv[i] * invFac[i-1] % MOD;
  }
}

ll modPow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n) {
    if (n & 1) (res *= x) %= MOD;
    (x *= x) %= MOD;
    n >>= 1;
  }
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  init();
  cin >> N >> A >> B >> C >> D;
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      dp[i][j] = dp[i-1][j];
      if (A <= i && i <= B) {
        for (int k = C; k <= D && j-i*k >= 0; k++) {
          ll tmp = dp[i-1][j-i*k];
          (tmp *= fac[N-j+i*k]) %= MOD;
          (tmp *= invFac[N-j]) %= MOD;
          (tmp *= modPow(modPow(fac[i], k, MOD), MOD-2, MOD)) %= MOD;
          (tmp *= invFac[k]) %= MOD;
          (dp[i][j] += tmp) %= MOD;
        }
      }
    }
  }
  cout << dp[N][N] << endl;

  return 0;
}