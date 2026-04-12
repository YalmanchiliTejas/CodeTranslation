#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

int64_t dpow(int64_t a, int64_t b, int64_t MOD) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    return dpow(a * a % MOD, b / 2, MOD);
  } else {
    return dpow(a, b - 1, MOD) * a % MOD;
  }
}

int main() {
  int64_t N, M;
  cin >> N >> M;

  vector<vector<int64_t>> stirling(N + 1 + 1, vector<int64_t>(N + 1 + 1, 0));
  stirling[0][0] = 1;
  rep(i, N + 1) rep(j, i + 1) {
    stirling[i + 1][j + 1] = stirling[i][j] + (j + 1) * stirling[i][j + 1] % M;
    stirling[i + 1][j + 1] %= M;
  }
  vector<int64_t> fact(N + 1, 1);
  rep(i, N) { fact[i + 1] = fact[i] * (i + 1) % M; }

  int64_t result = 0;
  irep(i, N) {
    int64_t comb = fact[N] * dpow(fact[i] * fact[N - i] % M, M - 2, M) % M;
    int64_t f = 0;

    int64_t p2 = dpow(2, N - i, M);
    int64_t t = 1;
    for (int j = 0; j <= i; j++) {
      f += stirling[i + 1][j + 1] * t % M;
      f %= M;

      t *= p2;
      t %= M;
    }
    f *= dpow(2, dpow(2, N - i, M - 1), M);
    f %= M;

    int64_t term = dpow(-1, i, M) * comb % M * f % M;
    result += term;
    result %= M;
  }
  result = (result + M) % M;
  cout << result << endl;

  return 0;
}