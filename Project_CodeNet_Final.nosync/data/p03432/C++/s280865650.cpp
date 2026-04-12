#include <bits/stdc++.h>
#define RI register int
typedef long long LL;

#define FILEIO(name) freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);

using namespace std;

int const MAXN = 2e5 + 5;
LL const mod = 998244353;
LL frac[MAXN], invfrac[MAXN], inv[MAXN];
LL f[MAXN], A[MAXN], B[MAXN];
int r[MAXN];

void Init(int Max) {
  frac[0] = invfrac[0] = 1;
  frac[1] = invfrac[1] = inv[1] = 1;
  for (RI i = 2; i <= Max; ++i) {
    frac[i] = frac[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    invfrac[i] = invfrac[i - 1] * inv[i] % mod;
  }
}

inline LL qpow(LL a, LL k) {
  LL re = 1; a %= mod;
  for (; k; k >>= 1, a = a * a % mod)
    if (k & 1) re = re * a % mod;
  return re;
}
inline LL C(int n, int m) {
  if (m > n) return 0;
  return frac[n] * invfrac[m] % mod * invfrac[n - m] % mod;
}

void NTT(LL *a, int len, int op) {
  for (RI i = 0; i < len; ++i)
    if (r[i] > i)
      swap(a[i], a[r[i]]);
  for (RI i = 2; i <= len; i <<= 1) {
    LL wn = qpow(3, (mod - 1) / i);
    wn = qpow(wn, op);
    for (RI j = 0; j < len; j += i) {
      LL w = 1;
      for (RI k = j; k < j + i / 2; ++k) {
        LL x = a[k], y = a[k + i / 2] * w % mod;
        a[k] = (x + y) % mod;
        a[k + i / 2] = (x - y + mod) % mod;
        w = w * wn % mod;
      }
    }
  }
}

int main() {

#ifdef LOCAL
  FILEIO("a");
#endif

  Init(1e4);
  int n, m; cin >> n >> m;
  
  int len = 1, cnt = 0;
  while (len <= n + n + 2) len <<= 1, ++cnt;
  for (RI i = 0; i < len; ++i)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
  LL invlen = qpow(len, mod - 2);

  for (RI i = 1; i <= n; ++i) B[i] = invfrac[i + 2];
  NTT(B, len, 1);

  f[0] = 1;
  for (RI i = 1; i <= m; ++i) {
    for (RI j = 0; j <= n; ++j) A[j] = f[j] * invfrac[j] % mod;
    for (RI j = n + 1; j < len; ++j) A[j] = 0;
    NTT(A, len, 1);
    for (RI j = 0; j < len; ++j) A[j] = A[j] * B[j] % mod;
    NTT(A, len, mod - 2);
    for (RI j = 0; j <= n; ++j)
      f[j] = (frac[j + 2] * A[j] % mod * invlen % mod + f[j] * (1ll + C(j + 1, 2)) % mod) % mod;
  }
  LL ans = 0;
  for (RI i = 0; i <= n; ++i)
    ans = (ans + f[i] * C(n, i) % mod) % mod;
  printf("%lld\n", ans);

  cerr << (double)(clock()) / CLOCKS_PER_SEC * 1000 << "ms" << endl;

  return 0;
}

// created by Daniel yuan