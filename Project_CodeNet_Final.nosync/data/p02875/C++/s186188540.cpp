#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int powMod(int x, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mul(res, x);
    }
    p >>= 1;
    x = mul(x, x);
  }
  return res;
}

const int maxn = (int) 1e7 + 5;
int p2[maxn];
int f[maxn], inv[maxn], finv[maxn];

void precalc() {
  p2[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p2[i] = mul(p2[i - 1], 2);
  }
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
}

int c(int n, int k) {
  return mul(f[n], mul(finv[k], finv[n - k]));
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  int res = powMod(3, n);
  for (int a = n / 2 + 1; a <= n; a++) {
    add(res, mod - mul(c(n, a), p2[n - a + 1]));
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
