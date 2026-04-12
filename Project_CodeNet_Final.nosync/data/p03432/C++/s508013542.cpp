#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 16385;
const int M = 15;
const int G = 3;
const int mod = 998244353;

namespace Polynomial {
  int D, L, I[M], W[M], R[N];

  inline int Qow(int x, int y) {
    int r = 1;
    for (; y; y >>= 1, x = 1LL * x * x % mod) {
      if (y & 1) {
        r = 1LL * r * x % mod;
      }
    }
    return r;
  }

  inline int Inv(int x) {
    return Qow(x, mod - 2);
  }

  inline void Ini(int l) {
    for (D = 1, L = 0; D < l; D <<= 1, ++L);
    for (int i = 1; i < D; ++i) {
      R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
    }
    W[0] = Qow(G, mod - 1 >> L), I[0] = Inv(W[0]);
    for (int i = 1; i < L; ++i) {
      W[i] = 1LL * W[i - 1] * W[i - 1] % mod;
      I[i] = 1LL * I[i - 1] * I[i - 1] % mod;
    }
  }

  inline void DFT(int *X, int *W) {
    for (int i = 0; i < D; ++i) {
      if (i < R[i]) {
        swap(X[i], X[R[i]]);
      }
    }
    for (int i = 1, l = L - 1; i < D; i <<= 1, --l) {
      for (int j = 0; j < D; j += i << 1) {
        for (int k = 0, w = 1, u, v; k < i; ++k, w = 1LL * w * W[l] % mod) {
          u = X[j + k], v = 1LL * w * X[j + k + i] % mod;
          X[j + k] = (u + v) % mod, X[j + k + i] = (u - v + mod) % mod;
        }
      }
    }
  }
}

using namespace Polynomial;

int n, m, ans, f[N], g[N], h[N], fac[N], inv[N];

inline int C(int x, int y) {
  if (x < 0 || y < 0 || x < y) {
    return 0;
  }
  return 1LL * fac[x] * inv[y] % mod * inv[x - y] % mod;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), f[0] = fac[0] = fac[1] = inv[0] = inv[1] = 1;
  for (int i = 2; i <= n + 2; ++i) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
    inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
  }
  for (int i = 2; i <= n + 2; ++i) {
    inv[i] = 1LL * inv[i - 1] * inv[i] % mod;
  }
  Ini(n + 1 << 1);
  int v = Inv(D);
  for (int i = 1; i <= n; ++i) {
    g[i] = inv[i + 2];
  }
  DFT(g, W);
  for (int j = 1; j <= m; ++j) {
    for (int i = 0; i < D; ++i) {
      h[i] = i <= n ? 1LL * f[i] * inv[i] % mod : 0;
    }
    DFT(h, W);
    for (int i = 0; i < D; ++i) {
      h[i] = 1LL * h[i] * g[i] % mod;
    }
    DFT(h, I);
    for (int i = 0; i <= n; ++i) {
      f[i] = (1LL * h[i] * v % mod * fac[i + 2] + 1LL * f[i] * (C(i + 1, 2) + 1)) % mod;
    }
  }
  for (int i = 0; i <= n; ++i) {
    ans = (1LL * f[i] * C(n, i) + ans) % mod;
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}
