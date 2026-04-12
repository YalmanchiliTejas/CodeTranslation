#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 1 << 14 | 5, P = 998244353;

int Inc(int x, int y) {
  return x + y < P ? x + y : x + y - P;
}

int Dec(int x, int y) {
  return x < y ? x - y + P : x - y;
}

void Add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}

void Sub(int &x, int y) {
  x -= y;
  if (x < 0) x += P;
}

int qp(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % P) {
    if (k & 1) res = 1ll * res * a % P;
  }
  return res;
}

int inv[maxn], fac[maxn], ifac[maxn];

int binom(int n, int m) {
  return n < m ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;
}

void init() {
  fac[0] = ifac[0] = 1;
  inv[1] = fac[1] = ifac[1] = 1;
  rep(i, 2, maxn - 1) {
    inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
    fac[i] = 1ll * i * fac[i - 1] % P;
    ifac[i] = 1ll * inv[i] * ifac[i - 1] % P;
  }
}

const int G = 3, Gi = 332748118;
int N, lim, maxN, rev[maxn], W[2][maxn], A[maxn], B[maxn];

void getwn() {
  maxN = 1 << 14;
  int w = qp(G, (P - 1) / maxN), wi = qp(w, P - 2);
  W[0][0] = W[1][0] = 1;
  W[0][1] = w, W[1][1] = wi;
  rep(i, 2, maxN - 1) {
    W[0][i] = 1ll * W[0][i - 1] * w % P;
    W[1][i] = 1ll * W[1][i - 1] * wi % P;
  }
}

void NTT(int *A, int opt) {
  for (int i = 0; i < N; i++) {
    if (i < rev[i]) swap(A[i], A[rev[i]]);
  }
  int *omg = opt == 1 ? W[0] : W[1];
  for (int l = 1, bit = maxN >> 1; l < N; l <<= 1, bit >>= 1) {
    for (int i = 0; i < N; i += l << 1) {
      for (int j = 0, *p = omg; j < l; j++, p += bit) {
        int t = 1ll * *p * A[i + j + l] % P;
        A[i + j + l] = Dec(A[i + j], t), Add(A[i + j], t);
      }
    }
  }
}

void poly_mul(int *A, int *B) {
  NTT(A, 1), NTT(B, 1);
  rep(i, 0, N - 1) A[i] = 1ll * A[i] * B[i] % P;
  NTT(A, -1);
  int inv_n = qp(N, P - 2);
  rep(i, 0, N - 1) A[i] = 1ll * A[i] * inv_n % P;
}

int n, m, dp[2][maxn];

void solve() {
  init();
  getwn();
  cin >> n >> m;
  N = 1, lim = 0;
  while (N <= n + n) N <<= 1, lim++;
  rep(i, 0, N - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lim - 1));
  dp[0][0] = 1;
  int sel = 1;
  rep(T, 1, m) {
    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);
    rep(i, 0, n) {
      A[i] = 1ll * dp[sel ^ 1][i] * ifac[i] % P, B[i] = ifac[i + 2];
    }
    B[0] = 0;
    poly_mul(A, B);
    dp[sel][0] = 1;
    rep(i, 1, n) {
      dp[sel][i] = (1ll * (1 + i + i * (i - 1) / 2) * dp[sel ^ 1][i] + 1ll * fac[i + 2] * A[i]) % P;
    }
//    rep(i, 1, n) {
//      dp[sel][i] = 1ll * (1 + i + i * (i - 1) / 2) * dp[sel ^ 1][i] % P;
//      rep(j, 0, i - 1) Add(dp[sel][i], 1ll * binom(i + 2, j) * dp[sel ^ 1][j] % P);
//    }
    sel ^= 1;
  }
  int res = 0;
  rep(i, 0, n) res = (res + 1ll * binom(n, i) * dp[sel ^ 1][i]) % P;
  cout << res << endl;
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}