#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);

const int mod = (int) 1e9 + 7;

void add(int &x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int x, int y) {
  return (long long) x * y % mod;
}

int myPower(int x, int pw) {
  int res = 1;
  for (; pw; pw >>= 1) {
    if (pw & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
  }
  return res;
}

const int maxn = (int) 1e3 + 10;

int ifact[maxn], inv[maxn];

void precalc() {
  ifact[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    inv[i] = myPower(i, mod - 2);
    ifact[i] = mult(ifact[i - 1], inv[i]);
  }
}


int n, a, b, c, d;

int read() {
  if (scanf("%d%d%d%d%d", &n, &a, &b, &c, &d) < 5) {
    return 0;
  }
  return 1;
}

int dp[maxn];

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int k = a; k <= b; ++k) {
    for (int x = n; x >= 0; --x) {
      int cur = dp[x];
      if (!cur) {
        continue;
      }
      for (int cnt = 0; cnt <= d; ++cnt) {
        if (!cur) {
          break;
        }
        int nx = x + cnt * k;
        if (nx > n) {
          break;
        }
        //eprintf("x = %d, k = %d, cnt = %d, cur = %d\n", x, k, cnt, cur);
        if (cnt >= c) {
          add(dp[nx], cur);
        }
        cur = mult(cur, ifact[k]);
        cur = mult(cur, inv[cnt + 1]);
      }
    }
  }
  int res = dp[n];
  for (int i = 1; i <= n; ++i) {
    res = mult(res, i);
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef LOCAL
  freopen(TASK ".out", "w", stdout);
  assert(freopen(TASK ".in", "r", stdin));
#endif

  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
