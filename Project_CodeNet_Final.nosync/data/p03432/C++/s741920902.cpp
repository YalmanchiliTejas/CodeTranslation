#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 8000, MaxM = 200;
const int MaxV = (1 << 14);
const int Mod = 998244353, Prt = 3;

int N, M, V;
int Fac[MaxN + 5], InvFac[MaxN + 5];
int Rev[MaxV + 5];
int W[MaxV + 5][2];
int F[MaxM + 5][MaxN + 5];
int Tmp[MaxV + 5], G[MaxV + 5];

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int mul(int x, int y) { return 1LL * x * y % Mod; }
inline int pw(int x, int y) { int z = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) z = mul(z, x); return z; }
inline int inv(int x) { return pw(x, Mod - 2); }
inline int sep(int x, int y) { return mul(x, inv(y)); }
inline void inc(int &x, int y = 1) { x = add(x, y); }
inline void dec(int &x, int y = 1) { x = sub(x, y); }
inline int binom(int n, int m) { return mul(Fac[n], mul(InvFac[m], InvFac[n - m])); }

void init() {
  scanf("%d %d", &N, &M);
  Fac[0] = 1;
  for (int i = 1; i <= N + 2; ++i) Fac[i] = mul(Fac[i - 1], i);
  InvFac[N + 2] = inv(Fac[N + 2]);
  for (int i = N + 2; i >= 1; --i) InvFac[i - 1] = mul(InvFac[i], i);
  for (V = 1; V < N + N + 5; V <<= 1);
  for (int i = 1; i < V; ++i) {
    Rev[i] = (Rev[i >> 1] >> 1);
    if (i & 1) Rev[i] |= (V >> 1);
  }
  for (int i = 1; i < V; i <<= 1) {
    W[i][0] = pw(Prt, (Mod - 1) / (i << 1));
    W[i][1] = pw(inv(Prt), (Mod - 1) / (i << 1));
  }
}

inline void ntt(int *a, int n, int f) {
  for (int i = 1; i < n; ++i)
    if (i < Rev[i]) std::swap(a[i], a[Rev[i]]);
  for (int i = 1; i < n; i <<= 1) {
    int w = W[i][f];
    for (int j = 0; j < n; j += (i << 1)) {
      int x = 1;
      for (int k = 0; k < i; ++k, x = mul(x, w)) {
        int ls = a[j + k], rs = a[i + j + k];
        a[j + k] = add(ls, mul(rs, x));
        a[i + j + k] = sub(ls, mul(rs, x));
      }
    }
  }
  if (f == 1) {
    int invn = inv(n);
    for (int i = 0; i < n; ++i) a[i] = mul(a[i], invn);
  }
}

void solve() {
  F[0][0] = 1;
  for (int i = 1; i <= N; ++i) G[i] = InvFac[i + 2];
  ntt(G, V, 0);
  for (int i = 1; i <= M; ++i) {
    memset(Tmp, 0, V << 2);
    for (int j = 0; j <= N; ++j) Tmp[j] = mul(F[i - 1][j], InvFac[j]);
    ntt(Tmp, V, 0);
    for (int j = 0; j < V; ++j) Tmp[j] = mul(Tmp[j], G[j]);
    ntt(Tmp, V, 1);
    for (int j = 0; j <= N; ++j) F[i][j] = mul(Tmp[j], Fac[j + 2]);
    for (int j = 0; j <= N; ++j) inc(F[i][j], mul(F[i - 1][j], (1LL * j * (j + 1) / 2 + 1) % Mod));
  }
  int ans = 0;
  for (int i = 0; i <= N; ++i) inc(ans, mul(F[M][i], binom(N, i)));
  printf("%d\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}