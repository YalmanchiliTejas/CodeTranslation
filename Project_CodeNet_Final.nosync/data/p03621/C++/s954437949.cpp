#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long i64;
const int MAX_N = 1 << 16, MOD = 998244353;

i64 fac[MAX_N], ifac[MAX_N], inv[MAX_N];

i64 fpm(i64 x, i64 y) {
  i64 res = 1;
  while (y) {
    if (y & 1) res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}

inline void rader(i64 *y, int len) {
  for (int i = 1, j = len >> 1; i < len - 1; ++i) {
    if (i < j) swap(y[i], y[j]);
    int k = len >> 1;
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    if (j < k) j += k;
  }
}

inline void DFT(i64 *y, int len, int op) {
  rader(y, len);
  for (int h = 2; h <= len; h <<= 1) {
    i64 wn = fpm(3, (MOD - 1) + op * (MOD - 1) / h);
    int l = h >> 1;
    for (int j = 0; j < len; j += h) {
      i64 w = 1;
      for (int k = j; k < j + l; ++k) {
	i64 u = y[k], v = y[k + l] * w % MOD;
	y[k] = (u + v) % MOD, y[k + l] = (u - v) % MOD;
	w = w * wn % MOD;
      }
    }
  }
  if (op == -1) {
    i64 INV = fpm(len, MOD - 2);
    for (int i = 0; i < len; ++i)
      y[i] = y[i] * INV % MOD;
  }
}

i64 binom(int n, int m) {
  if (n < m) return 0;
  return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

char A[MAX_N], B[MAX_N];
int M, E;

i64 F[MAX_N], G[MAX_N];

void work(int l, int mid, int r) {
  static i64 X[MAX_N], Y[MAX_N];
  int len = 1;
  while (len < mid + r - 2 * l) len <<= 1;
  for (int i = 0; i < len; ++i) X[i] = Y[i] = 0;
  for (int i = l; i <= mid; ++i) X[i - l] = F[i] * ifac[i] % MOD;
  for (int i = 0; i < r - l; ++i) Y[i] = 1;

  DFT(X, len, 1), DFT(Y, len, 1);
  for (int i = 0; i < len; ++i) X[i] = X[i] * Y[i] % MOD;
  DFT(X, len, -1);

  for (int i = mid + 1; i <= r; ++i) F[i] = (F[i] + X[i - l - 1]) % MOD;
}

void solve(int L, int R) {
  if (L == R) {
    if (L >= 1) F[L] = F[L] * fac[L - 1] % MOD;
    return;
  }
  int mid = (L + R) >> 1;
  solve(L, mid);
  work(L, mid, R);
  solve(mid + 1, R);
}

void work2(int x) {
  int len = 1;
  while (len <= M * 2) len <<= 1;
  static i64 X[MAX_N], Y[MAX_N];
  for (int i = 0; i <= M; ++i) X[i] = ifac[i + 1];
  while (x) {
    if (x & 1) {
      for (int i = 0; i < len; ++i) Y[i] = X[i];
      DFT(G, len, 1), DFT(Y, len, 1);
      for (int i = 0; i < len; ++i) G[i] = G[i] * Y[i] % MOD;
      DFT(G, len, -1);
      for (int i = M + 1; i < len; ++i) G[i] = 0;
    }
    x >>= 1;
    DFT(X, len, 1);
    for (int i = 0; i < len; ++i) X[i] = X[i] * X[i] % MOD;
    DFT(X, len, -1);
    for (int i = M + 1; i < len; ++i) X[i] = 0;
  }
  for (int i = 0; i <= M; ++i) G[i] = G[i] * fac[i] % MOD;
}
  
int main() {
  //freopen("input.in", "r", stdin);
  int N;
  scanf("%s%s", A, B), N = strlen(A);
  
  for (int i = 0; i < N; ++i)
    if (A[i] == '1' && B[i] == '1') M++;
    else if (A[i] != B[i]) E++;
  fac[0] = ifac[0] = inv[1] = 1;
  for (int i = 1; i < MAX_N; ++i) fac[i] = fac[i - 1] * i % MOD;
  for (int i = 2; i < MAX_N; ++i) inv[i] = -(MOD / i) * inv[MOD % i] % MOD;
  for (int i = 1; i < MAX_N; ++i) ifac[i] = ifac[i - 1] * inv[i] % MOD;

  F[0] = 1, E >>= 1, G[0] = 1;
  //solve(0, M);
  work2(E);
  // for (int i = 1; i <= M; ++i) {
  //   for (int j = 1; j <= i; ++j)
  //      F[i] = (F[i] + F[i - j] * ifac[i - j] % MOD) % MOD;
  //   F[i] = F[i] * fac[i - 1] % MOD;
  // }
  // for (int i = 1; i <= E; ++i) {
  //   for (int j = 0; j <= M; ++j) F[j] = G[j], G[j] = 0;
  //   for (int j = 0; j <= M; ++j)
  //     for (int k = 0; k <= j; ++k)
  // 	G[j] = (G[j] + F[j - k] * ifac[k + 1] % MOD) % MOD;
  //   for (int j = 0; j <= M; ++j)
  //     printf("%lld ", (G[j] + MOD) % MOD);
  //   puts("");
  // }
  // for (int j = 0; j <= M; ++j) G[j] = G[j] * fac[j] % MOD;
  
  i64 res = 0;
  for (int i = 0; i <= M; ++i) 
    res = (res + fac[M + E] * binom(M, i) % MOD * fac[i] % MOD * G[M - i] % MOD) % MOD;
  res = res * fac[E] % MOD;
  printf("%lld\n", (res + MOD) % MOD);
  return 0;
}
