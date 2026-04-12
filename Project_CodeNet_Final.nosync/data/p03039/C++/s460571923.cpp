#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
constexpr long long int INF = std::numeric_limits<long long int>::max();
constexpr long long int MAX = 3 * 100000;
constexpr long long int MOD = 1000000007;
#define int long long int

int fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

int COM(int n, int k) {
  if (n < k) {
    return 0;
  }
  if (n < 0 || k < 0) {
    return 0;
  }
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  COMinit();

  int ans = 0;
  for (int d = 1; d < N; d++) {
    ans = (ans + d * COM(N * M - 2, K - 2) * (N - d) * M * M) % MOD;
  }

  for (int d = 1; d < M; d++) {
    ans = (ans + d * COM(N * M - 2, K - 2) * (M - d) * N * N) % MOD;
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
