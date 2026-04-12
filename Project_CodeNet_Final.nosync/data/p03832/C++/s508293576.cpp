#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

namespace mod {
  ll power(ll x, ll e) {
    ll v = 1;
    for (; e > 0; e >>= 1) {
      if (e & 1) {
        v = v * x % MOD;
      }
      x = x * x % MOD;
    }
    return v;
  }

  ll inverse(ll x) {
    return power(x, MOD - 2);
  }

  vector<ll> fact, factInv;
  void initFact(int N) {
    fact.resize(N + 1); factInv.resize(N + 1); 
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
      fact[i] = fact[i-1] * i % MOD; 
    }
    factInv[N] = inverse(fact[N]);
    for (int i = N - 1; i >= 0; i--) {
      factInv[i] = factInv[i + 1] * (i + 1) % MOD;
    }
  }

  ll choose(int n, int k) {
    if (k > n) {
      return 0;
    } else {
      return fact[n] * factInv[k] % MOD * factInv[n-k] % MOD;
    }
  }

  ll multiChoose(int n, int k) {
    if (n == 0 && k == 0) {
      return 1;
    } else {
      return choose(n + k - 1, k);
    }
  }
}

int main() {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  mod::initFact(N);
  vector<vector<ll>> dp(B + 1, vector<ll>(N + 1, 0));
  dp[A-1][N] = 1;
  for (int k = A; k <= B; k++) {
    for (int n = 0; n <= N; n++) {
      (dp[k][n] += dp[k-1][n]) %= MOD;
      ll y = 1;
      for (int m = 1; m <= D && k * m <= n; m++) {
        y = y * mod::choose(k * m, k) % MOD;
        if (m >= C) {
          ll coef = mod::choose(n, k * m) * y % MOD * mod::factInv[m] % MOD;
          (dp[k][n-k*m] += dp[k-1][n] * coef % MOD) %= MOD;
        }
      }
    }
  }
  cout << dp[B][0] << endl;
  return 0;
}
