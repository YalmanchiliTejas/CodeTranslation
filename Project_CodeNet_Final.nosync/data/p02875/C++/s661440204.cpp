// by newbiechd
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

// DELETE the debugging information!
#define debug(x) std::cerr << #x << " = " << (x) << std::endl

const int N_MAX = 10000003, mod = 998244353;
int fac[N_MAX], iFac[N_MAX], bin[N_MAX];
int power(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1)
      ret = 1ll * x * ret % mod;
    x = 1ll * x * x % mod, y >>= 1;
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  fac[0] = 1, bin[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = 1ll * i * fac[i - 1] % mod, bin[i] = 2 * bin[i - 1] % mod;
  iFac[n] = power(fac[n], mod - 2);
  for (int i = n; i > 0; --i)
    iFac[i - 1] = 1ll * i * iFac[i] % mod;
  int ans = 0;
  for (int i = 0; i < n / 2; ++i)
    ans = (1ll * iFac[i] * iFac[n - i] % mod * bin[i] + ans) % mod;
  ans = (power(3, n) - 2ll * fac[n] * ans % mod) % mod;
  printf("%d\n", (ans + mod) % mod);
  return 0;
}
