#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int L = 14, N = 1 << L, P = 998244353, R = 3;

int inv[N], fac[N], ifac[N], root[N], brev[N], f[N];
bool key[N];
char s[N];

int norm(int x) { return x >= P ? (x - P) : x; }

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % P;
    k >>= 1;
    x = x * (ll)x % P;
  }
  return ret;
}

void prepare(int n) {
  inv[1] = 1;
  for (int i = 2; i <= n; ++i)
    inv[i] = -(P / i) * (ll)inv[P % i] % P + P;
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = fac[i - 1] * (ll)i % P;
  ifac[0] = 1;
  for (int i = 1; i <= n; ++i)
    ifac[i] = ifac[i - 1] * (ll)inv[i] % P;
}

void preparefft(int lgn) {
  int n = 1 << lgn;
  for (int i = 0; i < n; ++i)
    brev[i] = (brev[i >> 1] >> 1) | ((i & 1) << (lgn - 1));
  int primitive = mpow(R, (P - 1) >> lgn);
  root[0] = 1;
  for (int i = 1; i < n; ++i)
    root[i] = root[i - 1] * (ll)primitive % P;
}

void ntt(int* a, int lgn, int sgn) {
  int n = 1 << lgn;
  for (int i = 0; i < n; ++i) {
    int rv = brev[i] >> (L - lgn);
    if (i < rv) swap(a[i], a[rv]);
  }
  for (int k = L - 1, t = 1; t < n; t <<= 1, --k) {
    for (int i = 0; i < n; i += t << 1) {
      int *p1 = a + i, *p2 = a + i + t;
      for (int j = 0; j < t; ++j) {
        int x = p2[j] * (ll)root[j << k] % P;
        p2[j] = norm(p1[j] + P - x);
        p1[j] = norm(p1[j] + x);
      }
    }
  }
  if (sgn == -1) {
    reverse(a + 1, a + n);
    int nv = mpow(n, P - 2);
    for (int i = 0; i < n; ++i)
      a[i] = a[i] * (ll)nv % P;
  }
}

void mul(int* a, int n, int* b, int m, int* c) {
  static int ta[N], tb[N], tc[N];
  int l = 0;
  while ((1 << l) <= (n + m)) ++l;
  memset(ta, 0, sizeof(int) << l);
  memset(tb, 0, sizeof(int) << l);
  memcpy(ta, a, sizeof(int) * (n + 1));
  memcpy(tb, b, sizeof(int) * (m + 1));
  ntt(ta, l, 1);
  ntt(tb, l, 1);
  for (int i = 0; i < (1 << l); ++i)
    tc[i] = ta[i] * (ll)tb[i] % P;
  ntt(tc, l, -1);
  memcpy(c, tc, sizeof(int) * (n + m + 1));
}

int dp[N], tmp[N], sv[N];

int binom(int n, int m) { return fac[n] * (ll)ifac[m] % P * ifac[n - m] % P; }

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  prepare(n);
  preparefft(L);
  dp[n] = 1;
  while (m--) {
    memcpy(sv, dp, sizeof(sv));
    for (int i = 0; i <= n; ++i)
      dp[i] = dp[i] * (ll)fac[i] % P;
    reverse(dp, dp + n + 1);
    mul(dp, n, ifac, n, tmp);
    for (int i = 0; i <= n; ++i)
      dp[i] = sv[i] * (1LL + i) % P;
    reverse(tmp, tmp + n + 1);
    for (int i = 0; i <= n; ++i) {
      tmp[i] = tmp[i] * (ll) ifac[i] % P;
      for (int j = 0; j <= 1; ++j)
        tmp[i] = (tmp[i] + (P - binom(i + j, j)) * (ll)sv[i + j]) % P;
      dp[i + 2] = norm(dp[i + 2] + tmp[i]);
    }
  }
  cout << (accumulate(dp, dp + n + 1, 0LL) % P);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}

