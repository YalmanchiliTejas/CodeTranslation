#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>

using namespace std;
typedef long long int64;

int64 MOD = 1000000007LL;

int64 Comb(int64 n, int64 k) {
  vector<int64> fac(n + 1);
  vector<int64> finv(n + 1);
  vector<int64> inv(n + 1);
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i ) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
  int64 ans = fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
  return ans;
}

int main() {
  int64 N, M, K;
  cin >> N >> M >> K;

  int64 total = 0;
  for (int d = 1; d <= N - 1; ++d) {
    total += d * (N - d) * M % MOD * M % MOD;
    total %= MOD;
  }
  for (int d = 1; d <= M - 1; ++d) {
    total += d * (M - d) * N % MOD * N % MOD;
    total %= MOD;
  }
  total *= Comb(N * M - 2, K - 2);
  total %= MOD;

  cout << total << endl;
  return 0;
}
