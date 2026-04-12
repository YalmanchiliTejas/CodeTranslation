#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

ll MOD;

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

ll power(ll x, ll e, ll M) {
  ll v = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) {
      v = v * x % M;
    }
    x = x * x % M;
  }
  return v;
}

ll inverse(ll x) { return power(x, MOD - 2); }

vector<ll> fact, factInv;
void initFact(int N) {
  fact.resize(N + 1);
  factInv.resize(N + 1);
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = fact[i - 1] * i % MOD;
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
    return fact[n] * factInv[k] % MOD * factInv[n - k] % MOD;
  }
}

ll multiChoose(int n, int k) {
  if (n == 0 && k == 0) {
    return 1;
  } else {
    return choose(n + k - 1, k);
  }
}
}  // namespace mod

int main() {
  int N;
  while (cin >> N >> MOD) {
    mod::initFact(N + 10);
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
    dp[0][0] = 1;
    for (int n = 1; n <= N; n++) {
      dp[n][0] = 1;
      for (int k = 1; k <= n; k++) {
        dp[n][k] =
            (dp[n - 1][k] + dp[n - 1][k - 1] + dp[n - 1][k] * k % MOD) % MOD;
      }
    }
    ll res = 0;
    for (int k = 0; k <= N; k++) {
      ll sum = 0;
      for (int i = 0; i <= k; i++) {
        ll y = dp[k][i] * mod::power(2, (N - k) * i) % MOD;
        sum = (sum + y) % MOD;
      }
      ll y = sum * mod::power(2, mod::power(2, N - k, MOD - 1)) % MOD *
             mod::choose(N, k) % MOD;
      if (k % 2 == 0) {
        res = (res + y) % MOD;
      } else {
        res = (res - y + MOD) % MOD;
      }
    }
    cout << res << endl;
  }
  return 0;
}
