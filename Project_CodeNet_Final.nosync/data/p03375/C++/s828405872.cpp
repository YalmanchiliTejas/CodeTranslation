#include <bits/stdc++.h>
using namespace std;

int MOD, n, fac[3010], inv[3010], g[3010][3010], f[3010], pw[3010 * 3010];

int Kissme(int x, int y, int M) {
  int c = 1;
  while(y) {
    if(y & 1) c = (long long)c * x % M;
    x = (long long)x * x % M;
    y >>= 1;
  }
  return c;
}

int Dust(int x, int y) {
  return (long long)fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

void Ash(void) {
  fac[0] = 1;
  for(int i = 1; i <= n; i++)
    fac[i] = (long long)fac[i - 1] * i % MOD;
  inv[n] = Kissme(fac[n], MOD - 2, MOD);
  for(int i = n - 1; i >= 0; i--)
    inv[i] = (long long)inv[i + 1] * (i + 1) % MOD;
  pw[0] = 1;
  for(int i = 1; i <= n * n; i++)
    pw[i] = pw[i - 1] * 2 % MOD;
}

int main(void) {
  scanf("%d%d", &n, &MOD);
  Ash();
  g[0][0] = f[0] = 1;
  for(int i = 1, op; i <= n; i++) {
    for(int j = 0; j <= i; j++)
      g[i][j] = ((long long)(j + 1) * g[i - 1][j] + g[i - 1][j - 1]) % MOD;
    for(int j = 0; j <= i; j++)
      f[i] = (f[i] + (long long)g[i][j] * pw[(n - i) * j]) % MOD;
  }
  for(int i = 0; i <= n; i++)
    f[i] = (long long)f[i] * Kissme(2, Kissme(2, n - i, MOD - 1), MOD) % MOD;
  int ans = 0;
  for(int i = 0, op = 1; i <= n; i++, op = -op)
    ans = (ans + (long long)op * Dust(n, i) * f[i] % MOD + MOD) % MOD;
  printf("%d\n", ans);
  return 0;
}

