#include <bits/stdc++.h>

typedef long long ll;
const int MAX_N = 200000;
const ll MOD = (ll)1e+9 + 7;

int main() {
  int N, M, K;
  std::cin >> N >> M >> K;

  ll cmb = 1, sub = (ll) N * M - 2;
  for(int i = 0; i < K - 2; ++i) {
    cmb *= sub; cmb %= MOD;
    --sub;
  }

  static std::vector<ll> inv(K - 1);
  inv[1] = 1;
  for(int i = 2; i <= K - 2; ++i) {
    inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
  }
  for(int i = K - 2; i > 0; --i) {
    cmb *= inv[i];
    cmb %= MOD;
  }

  ll ans = 0;
  for(int d = 1; d < N; ++d) {
    ll sub = (ll) d;
    sub *= (ll) (N - d) * (((ll) M * M) % MOD);
    sub %= MOD;
    ans += sub;
  }
  for(int d = 1; d < M; ++d) {
    ll sub = (ll) d;
    sub *= (ll) (M - d) * (((ll) N * N) % MOD);
    sub %= MOD;
    ans += sub;
  }
  ans %= MOD;
  ans *= cmb;
  ans %= MOD;

  std::cout << ans << std::endl;
}