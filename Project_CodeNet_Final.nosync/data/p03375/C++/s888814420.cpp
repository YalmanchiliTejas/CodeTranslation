#include <bits/stdc++.h>
#define RI register int
typedef long long LL;
#define int LL

#define FILEIO(name) freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);

using namespace std;

char buf[1000000], *p1 = buf, *p2 = buf;
inline char gc() {
  if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin);
  return p1 == p2 ? EOF : *(p1++);
}
template <class T> inline void read(T &n) {
  n = 0; RI ch = gc(), f;
  while ((ch < '0' && ch > '9') && (ch != '-')) ch = gc();
  f = (ch == '-' ? ch = gc(), -1 : 1);
  while (ch >= '0' && ch <= '9') n = n * 10 + (ch ^ 48), ch = gc();
  n *= f;
}

int const MAXN = 3005;
int n, mod;
int f[MAXN][MAXN], frac[MAXN], invfrac[MAXN];

inline int qpow(int a, int k, int mod) {
  int re = 1;
  for (; k; k >>= 1, a = a * a % mod)
    if (k & 1) re = re * a % mod;
  return re;
}
inline int C(int n, int m) { return frac[n] * invfrac[m] % mod * invfrac[n - m] % mod; }

void Init(int Max) {
  f[0][0] = 1;
  for (RI i = 1; i <= Max + 1; ++i) {
    f[i][0] = 0;
    for (RI j = 1; j <= i; ++j)
      f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1]) % mod;
  }
  frac[0] = 1;
  for (RI i = 1; i <= Max; ++i) frac[i] = frac[i - 1] * i % mod;
  invfrac[Max] = qpow(frac[Max], mod - 2, mod);
  for (RI i = Max; i; --i) invfrac[i - 1] = invfrac[i] * i % mod;
}

signed main() {

#ifdef LOCAL
  FILEIO("a");
#endif

  read(n), read(mod);
  Init(n);
  int ans = 0;
  for (RI i = 0; i <= n; ++i) {
    int sum = 0;
    int Two = qpow(2, qpow(2, n - i, mod - 1), mod);
    int TTwo = 1, Twoo = qpow(2, n - i, mod);
    for (RI j = 0; j <= i; ++j, TTwo = TTwo * Twoo % mod)
      sum = (sum + f[i + 1][j + 1] * Two % mod * TTwo % mod) % mod;
    ans = (ans + qpow(mod - 1, i, mod) * C(n, i) % mod * sum % mod) % mod;
  }
  printf("%lld\n", ans);

  cerr << (double)(clock()) / CLOCKS_PER_SEC * 1000 << "ms" << endl;

  return 0;
}

// created by Daniel yuan