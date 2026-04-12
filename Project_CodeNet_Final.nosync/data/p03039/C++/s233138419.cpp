#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// #include "prettyprint.hpp"

int inv(int a, long long MOD) {
  return a == 1 ? 1 : (long long)(MOD - MOD / a) * inv(MOD % a, MOD) % MOD;
}

long mod = 1000000007;
int main() {
  long long N, M, K;
  cin >> N >> M >> K;

  long long k_2 = 1;
  for (int i = 1; i <= K - 2; i++) {
    k_2 *= i;
    k_2 %= mod;
  }

  int k_2_inv = inv(k_2, mod);

  long long nm_2_k_2 = k_2_inv;
  long long nm_2 = N * M - 2;

  for (int i = 0; i < K - 2; i++) {
    nm_2_k_2 *= nm_2 - i;
    nm_2_k_2 %= mod;
  }

  // cout << nm_2_k_2 << endl;
  long long ans = 0;
  for (int d = 0; d < N; d++) {
    ans += d * (N - d) * M * M;
  }

  for (int d = 0; d < M; d++) {
    ans += d * (M - d) * N * N;
  }

  ans %= mod;
  ans *= nm_2_k_2;
  ans %= mod;
  ans += mod;
  ans %= mod;

  cout << ans << endl;
  return 0;
}