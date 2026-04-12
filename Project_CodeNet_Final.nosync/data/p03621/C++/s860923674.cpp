// by newbiechd
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

// Delete the debugging information!
#define debug(x) std::cerr << #x << " = " << (x) << std::endl

template <typename T1, typename T2>
T1 min(const T1 &lhs, const T2 &rhs) {
  return lhs < rhs ? lhs : rhs;
}
template <typename T1, typename T2>
T1 max(const T1 &lhs, const T2 &rhs) {
  return lhs < rhs ? rhs : lhs;
}

const int N_MAX = 262147, mod = 998244353;
int inv[N_MAX];
int power(int x, int y) {
  int o = 1;
  while (y) {
    if (y & 1)
      o = 1ll * o * x % mod;
    x = 1ll * x * x % mod, y >>= 1;
  }
  return o;
}

typedef std::vector<int> Poly;
void operator+=(Poly &f, const Poly &g) {
  f.resize(max(f.size(), g.size()));
  for (unsigned i = 0; i < g.size(); ++i)
    f[i] = (f[i] + g[i]) % mod;
}
void operator-=(Poly &f, const Poly &g) {
  f.resize(max(f.size(), g.size()));
  for (unsigned i = 0; i < g.size(); ++i)
    f[i] = (f[i] - g[i]) % mod;
}
void operator*=(Poly &f, const int &x) {
  for (unsigned i = 0; i < f.size(); ++i)
    f[i] = 1ll * x * f[i] % mod;
}
Poly operator*(Poly f, const int &x) {
  f *= x;
  return f;
}

int rev[N_MAX];
unsigned unitRoot[N_MAX];
int getLen(const int &n) {
  return 1 << (32 - __builtin_clz(n));
}
int prepare(const int &n) {
  const int len = getLen(n);
  for (int i = 1; i < len; ++i)
    rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
  return len;
}

void FFT(Poly &f, const int &len) {
  static unsigned long long tmp[N_MAX];
  for (int i = 0; i < len; ++i)
    tmp[rev[i]] = f[i] + ((f[i] >> 31) & mod);
  for (int i = 1; i < len; i <<= 1)
    for (int j = 0; j < len; j += i << 1)
      for (int k = 0; k < i; ++k) {
        unsigned x = tmp[i | j | k] * unitRoot[i | k] % mod;
        tmp[i | j | k] = tmp[j | k] + mod - x, tmp[j | k] += x;
      }
  for (int i = 0; i < len; ++i)
    f[i] = tmp[i] % mod;
}

void operator*=(Poly &f, Poly &g) {
  const int n = f.size(), m = g.size(), k = n + m - 1, len = prepare(k);
  f.resize(len), FFT(f, len), g.resize(len), FFT(g, len);
  for (int i = 0; i < len; ++i)
    f[i] = 1ll * f[i] * g[i] % mod;
  FFT(f, len), std::reverse(&f[1], &f[len]), f.resize(k), f *= inv[len];
}

void inverse(const Poly &f, Poly &g, const int &n) {
  if (n == 1) {
    g.resize(1), g[0] = power(f[0], mod - 2);
    return ;
  }
  inverse(f, g, (n + 1) >> 1);
  static Poly tmp;
  const int len = prepare((n << 1) - 1);
  tmp.resize(len), memcpy(&tmp[0], &f[0], sizeof(f[0]) * n), FFT(tmp, len);
  g.resize(len), FFT(g, len);
  for (int i = 0; i < len; ++i)
    g[i] = (-1ll * g[i] * tmp[i] % mod + 2) * g[i] % mod;
  FFT(g, len), std::reverse(&g[1], &g[len]), g.resize(n), g *= inv[len];
}

Poly derivate(const Poly &f) {
  Poly g(f.size() - 1);
  for (unsigned i = 1; i < f.size(); ++i)
    g[i - 1] = 1ll * i * f[i] % mod;
  return g;
}

Poly integrate(const Poly &f) {
  Poly g(f.size() + 1);
  for (unsigned i = 1; i <= f.size(); ++i)
    g[i] = 1ll * inv[i] * f[i - 1] % mod;
  return g;
}

Poly logarithm(const Poly &f) {
  static Poly g, tmp;
  inverse(f, g, f.size()), g *= (tmp = derivate(f)), g.resize(f.size() - 1);
  return integrate(g);
}

void exponentiate(const Poly &f, Poly &g, const int &n) {
  if (n == 1) {
    g.resize(1), g[0] = 1;
    return ;
  }
  exponentiate(f, g, (n + 1) >> 1);
  static Poly tmp;
  tmp.resize(n), memcpy(&tmp[0], &f[0], sizeof(f[0]) * n);
  g.resize(n), tmp -= logarithm(g), ++tmp[0];
  g.resize((n + 1) >> 1), g *= tmp, g.resize(n);
}

void PolyPower(const Poly &f, Poly &g, int k) {
  exponentiate(logarithm(f) * k, g, f.size());
}

char a[N_MAX], b[N_MAX];
int fac[N_MAX], iFac[N_MAX];

int main() {
  
  scanf("%s%s", a + 1, b + 1);
  const int n = strlen(a + 1), len = getLen(n << 1);
  inv[1] = 1;
  for (int i = 2; i <= len; ++i)
    inv[i] = -1ll * (mod / i) * inv[mod % i] % mod;
  for (int i = 1; i < len; i <<= 1) {
    const unsigned temp = power(3, (mod - 1) / (i << 1));
    unitRoot[i] = 1;
    for (int j = 1; j < i; ++j)
      unitRoot[i | j] = 1ull * unitRoot[(i | j) - 1] * temp % mod;
  }
  
  int c = 0, r = 0;
  for (int i = 1; i <= n; ++i)
    c += a[i] == '1' && b[i] == '1', r += a[i] > b[i];
  fac[0] = 1;
  for (int i = 1; i <= n + 1; ++i)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  iFac[n + 1] = power(fac[n + 1], mod - 2);
  for (int i = n + 1; i; --i)
    iFac[i - 1] = 1ll * iFac[i] * i % mod;
  Poly f(c + 1), g;
  for (int i = 0; i <= c; ++i)
    f[i] = iFac[i + 1];
  PolyPower(f, g, r);
  int ans = 0;
  for (int i = 0; i <= c; ++i)
    ans = (g[i] + ans) % mod;
  ans = 1ll * ans * fac[c] % mod * fac[r] % mod * fac[c + r] % mod;
  printf("%d\n", (ans + mod) % mod);
  return 0;
}
