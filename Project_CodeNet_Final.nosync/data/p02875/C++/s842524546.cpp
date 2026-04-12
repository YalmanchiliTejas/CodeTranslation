#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int N; cin>>N;

  constexpr long MOD = 998244353;
  constexpr int MAX = 1e7;
  vector<long> fact(MAX+1);
  fact[0] = 1;
  for (long i = 1; i <= MAX; i++) {
    fact[i] = fact[i-1]*i%MOD;
  }
  auto mod_pow = [](long x, long y) {
    long t = 1;
    long u = x;
    while (y) {
      if (y & 1) {
        t *= u;
        t %= MOD;
      }
      u *= u;
      u %= MOD;
      y >>=1;
    }
    return t;
  };
  auto mod_inv = [&](long x) {
    return mod_pow(x, MOD-2);
  };
  vector<long> ifact(MAX+1);
  ifact[MAX] = mod_inv(fact[MAX]);
  for (long i = MAX-1; i >= 0; i--) {
    ifact[i] = ifact[i+1] * (i+1) % MOD;
  }
  auto comb = [&](long x, long y) {
    return fact[x] * ifact[y] % MOD * ifact[x-y] % MOD;
  };

  auto U = mod_pow(3, N);

  long ans = U;
  for (int i = N; i > N/2; i--) {
    auto pat = comb(N, i) * mod_pow(2, N-i) % MOD;
    ans = ans + MOD - pat + MOD - pat;
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
