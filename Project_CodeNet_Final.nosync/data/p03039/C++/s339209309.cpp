#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

constexpr long long MOD = 1000000007;
constexpr long long MAX = 200000 + 1;
#define FORR(i, a, b) for (int i = (b)-1; i >= (a); --i)
using ll = long long;

ll fact[MAX], fact_inv[MAX];

ll power(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

ll comb(ll n, ll r) {
  return (fact[n] * fact_inv[r]) % MOD * fact_inv[n - r] % MOD;
}

int main() {
  long long N, M, K;
  std::cin >> N >> M >> K;
  long long y = (M * M * (M + 1)) / 2 - (M * (M + 1) * (2 * M + 1)) / 6;
  y %= MOD;
  y *= N * N;
  y %= MOD;
  long long x = (N * N * (N + 1)) / 2 - (N * (N + 1) * (2 * N + 1)) / 6;
  x %= MOD;
  x *= M * M;
  x %= MOD;
  long long I = (x + y) % MOD;
  long long n = N * M + 1;

  fact[0] = 1;
  for (int i = 0; i < n; ++i)
    fact[i + 1] = fact[i] * (i + 1) % MOD;
  fact_inv[n] = power(fact[n], MOD - 2);

  for (int i = n - 1; 0 <= i; --i)
    fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD;

  std::cout << (I * comb(N * M - 2, K - 2)) % MOD << std::endl;

  return 0;
}
