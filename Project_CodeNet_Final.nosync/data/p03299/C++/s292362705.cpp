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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int mod = (int) 1e9 + 7;

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

const int maxn = 105;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  a[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  a[n + 1] = 1;
  n += 2;
  return true;
}

int cnt[maxn][maxn];
int dp[maxn];

void solve() {
  for (int i = 0; i + 1 < n; i++) {
    cnt[i][i] = 1;
  }
  for (int len = 1; len < n - 1; len++) {
    for (int i = 0; i + len + 1 < n; i++) {
      int j = i + len;
      int k = i + 1;
      for (int l = i + 2; l <= j; l++) {
        if (a[l] < a[k]) {
          k = l;
        }
      }
      if (a[k] <= min(a[i], a[i + 1]) || a[k] <= min(a[j], a[j + 1])) {
        cnt[i][j] = mul(cnt[i][k - 1], cnt[k][j]);
      } else {
        cnt[i][j] = mul(powMod(2, a[k] - max(min(a[i], a[i + 1]), min(a[j], a[j + 1]))), mul(cnt[i][k - 1], cnt[k][j]));
      }
    }
  }
  memset(dp, 0, sizeof(dp));
  dp[0] = 2;
  for (int i = 0; i + 1 < n; i++) {
    auto cur = dp[i];
    for (int j = i + 1; j + 1 < n; j++) {
      add(dp[j], mul(cur, cnt[i][j]));
    }
  }
  printf("%d\n", dp[n - 2]);
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
