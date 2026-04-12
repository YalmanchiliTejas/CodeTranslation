#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

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
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e3 + 5, mod = (int) 1e9 + 7;
int n, a, b, c, d;

int read() {
  if (scanf("%d%d%d%d%d", &n, &a, &b, &c, &d) < 5) {
    return false;
  }
  return true;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  int res = gcd(x, mod).first;
  if (res < 0) {
    res += mod;
  }
  return res;
}

int f[maxn];
int finv[maxn][maxn];
int dp[maxn][maxn];

void solve() {
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = mul(f[i - 1], i);
  }
  for (int i = 0; i <= n; i++) {
    finv[i][0] = 1;
    finv[i][1] = inv(f[i]);
    for (int j = 2; j <= n; j++) {
      finv[i][j] = mul(finv[i][j - 1], finv[i][1]);
    }
  }
  memset(dp, 0, sizeof(dp));
  dp[n][n] = 1;
  for (int i = n; i > 0; i--) {
    for (int j = 0; j <= n; j++) {
      if (!dp[i][j]) {
        continue;
      }
      add(dp[i - 1][j], dp[i][j]);
      if (a <= i && i <= b) {
        for (int k = c; k <= d; k++) {
          if (k * i <= j) {
            add(dp[i - 1][j - k * i], mul(dp[i][j], mul(mul(f[j], finv[j - k * i][1]), mul(finv[i][k], finv[k][1]))));
          }
        }
      }
    }
  }
  printf("%d\n", dp[0][0]);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
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
