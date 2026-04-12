#include <bits/stdc++.h>

const int N = 3010;

int n, P, pow2[N * N], S2[N][N], fac[N], inv[N], ans;

inline int fpow(int x, int y, int P = ::P) {
  int ret = 1;
  for ( ; y; y >>= 1, x = 1ll * x * x % P)
    if (y & 1) ret = 1ll * ret * x % P;
  return ret;
}

int main() {
  std::cin >> n >> P;
  pow2[0] = 1;
  for (int i = 1; i <= n * n; ++i)
    pow2[i] = 1ll * pow2[i - 1] * 2 % P;
  S2[0][0] = 1;
  for (int i = 1; i <= n + 1; ++i)
    for (int j = 1; j <= i; ++j)
      S2[i][j] = (S2[i - 1][j - 1] + 1ll * S2[i - 1][j] * j) % P;
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = 1ll * fac[i - 1] * i % P;
  inv[n] = fpow(fac[n], P - 2);
  for (int i = n; i; --i)
    inv[i - 1] = 1ll * inv[i] * i % P;
  ans = fpow(2, fpow(2, n, P - 1));
  for (int i = 1; i <= n; ++i) {
    int f = 0;
    for (int j = 0; j <= i; ++j)
      f = (f + 1ll * S2[i + 1][j + 1] * pow2[(n - i) * j]) % P;
    f = 1ll * f * fpow(2, fpow(2, n - i, P - 1)) % P;
    f = 1ll * f * fac[n] % P * inv[i] % P * inv[n - i] % P;
    if (i & 1)
      ans = (ans - f + P) % P;
    else
      ans = (ans + f) % P;
  }
  std::cout << ans << std::endl;
  return 0;
}
