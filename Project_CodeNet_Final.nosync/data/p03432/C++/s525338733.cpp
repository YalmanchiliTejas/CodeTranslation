#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))

typedef unsigned long long lu;
typedef vector<int> Poly;

const int mod = 998244353, gen = 3;

inline int Add(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
inline int Sub(int x) { return x < 0 ? x + mod : x; }
inline void Sub(int &x, int y) { x = Sub(x - y); }
inline int Mul(int x, int y) { return (lu)x * y % mod; }
inline int Mul(int x, int y, int z) { return (lu)x * y % mod * z % mod; }

int Pow(int x, int y) {
  int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) z = Mul(z, x);
    x = Mul(x, x);
  }
  return z;
}

int Inv(int x) { return Pow(x, mod - 2); }

// ----------------------------------------

namespace fft {
  const int maxn = 1 << 21;

  Poly Convo(const Poly &a, const Poly &b, int len_1, int len_2);
  Poly AuxInv(const Poly &a, const Poly &b);
  Poly operator * (const Poly &a, const Poly &b);
}

using fft::Convo;
using fft::AuxInv;
using fft::operator *;

namespace fft {
  void Dft(int *a, int n) {
    static int rev[maxn];
    rev[0] = 0;
    for (int i = 1; i < n; ++i) {
      rev[i] = i & 1 ? rev[i - 1] | n >> 1 : rev[i >> 1] >> 1;
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    }

    static int root[maxn], nr = 1;
    while (nr < n) {
      nr <<= 1;
      int *r = root + (nr >> 1), w = Pow(gen, (mod - 1) / nr);
      r[0] = 1;
      for (int i = 1; i < (nr >> 1); ++i) {
        r[i] = Mul(r[i - 1], w);
      }
    }

    for (int m = 1; m < n; m <<= 1) {
      for (int i = 0; i < n; i += (m << 1)) {
        int *l = a + i, *r = l + m, *w = root + m;
        for (int k = 0; k < m; ++k) {
          int t = Mul(*r, *w);
          *r = Sub(*l - t);
          Add(*l, t);
          ++l; ++r; ++w;
        }
      }
    }
  }

  void Idft(int *a, int n) {
    reverse(a + 1, a + n);
    Dft(a, n);
    int inv = Pow(n, mod - 2);
    for (int i = 0; i < n; ++i) a[i] = Mul(a[i], inv);
  }

  int at[maxn], bt[maxn];

  Poly Convo(const Poly &a, const Poly &b, int n1, int n2) {
    int nt = 1;
    while (nt < n1) nt <<= 1;
    FILL(at, nt, 0);
    FILL(bt, nt, 0);
    copy(a.begin(), a.end(), at);
    copy(b.begin(), b.end(), bt);
    Dft(at, nt);
    Dft(bt, nt);
    for (int i = 0; i < nt; ++i) at[i] = Mul(at[i], bt[i]);
    Idft(at, nt);
    return Poly(at, at + n2);
  }

  Poly AuxInv(const Poly &a, const Poly &b) {
    int n = a.size(), n1 = n * 3 / 2, nt = 1;
    while (nt < n1) nt <<= 1;
    FILL(at, nt, 0);
    FILL(bt, nt, 0);
    copy(a.begin(), a.end(), at);
    copy(b.begin(), b.end(), bt);
    Dft(at, nt);
    Dft(bt, nt);
    for (int i = 0; i < nt; ++i) at[i] = Mul(Sub(2 - Mul(at[i], bt[i])), bt[i]);
    Idft(at, nt);
    copy(b.begin(), b.end(), at);
    return Poly(at, at + n);
  }

  Poly operator * (const Poly &a, const Poly &b) {
    if (a.empty() || b.empty()) return Poly();
    return fft::Convo(a, b, a.size() + b.size(), min(a.size(), b.size()));
  }
}

// ----------------------------------------

int n, m;
const int maxn = 8000 + 2;

int fact[maxn + 1], ifact[maxn + 1];

void InitFact(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = Mul(fact[i - 1], i);
  }
  ifact[n] = Inv(fact[n]);
  for (int i = n; i >= 1; --i) {
    ifact[i - 1] = Mul(ifact[i], i);
  }
}

int Binom(int n, int m) {
  return Mul(fact[n], ifact[m], ifact[n - m]);
}

Poly Tran(Poly f) {
  Poly a = f;
  for (int i = 0; i <= n; ++i) {
    a[i] = Mul(a[i], ifact[i]);
  }
  Poly b(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    b[i] = ifact[i + 2];
  }
  Poly c = a * b;
  c.resize(n + 1);
  for (int i = 0; i <= n; ++i) {
    c[i] = Mul(c[i], fact[i + 2]);
  }
  for (int i = 0; i <= n; ++i) {
    Add(c[i], f[i]);
    Add(c[i], Mul((lu)i * (i + 1) / 2 % mod, f[i]));
  }
  return c;
}

int main(void) {
  scanf("%d%d", &n, &m);
  InitFact(n + 2);
  Poly f(n + 1, 0);
  f[0] = 1;
  for (int i = 0; i < m; ++i) {
    f = Tran(f);
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    Add(ans, Mul(Binom(n, i), f[i]));
  }
  printf("%d\n", ans);
  return 0;
}
