#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1e9 + 7;


LL inv(LL a) {
  LL ans = 1;
  for (LL cur = a, p = MOD - 2; p; cur = cur * cur % MOD, p >>= 1) 
    if (p&1) ans = cur * ans % MOD;
  return ans;
}






int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  LL N, M, K;
  cin >> N >> M >> K;
  LL average = 0;
  for (auto n : {M, N}) {
    auto m = (n == M ? N : M);
    LL partial = 0;
    for (LL a = 0; a < n; ++a) {
      (partial += a * (a + 1) / 2 + (n - a) * (n - a - 1) / 2) %= MOD;
    }
    partial = partial * m % MOD;
    partial = partial * inv(N * M - 1) % MOD * inv(n);
    average = (average + partial) % MOD;
  }
  LL C = 1;
  for (LL u = N * M, l = K; l; --u, --l) {
    C = C * u % MOD * inv(l) % MOD;
  }
  cout << C * average % MOD * (K - 1) % MOD * K % MOD * inv(2) % MOD << '\n';
}
