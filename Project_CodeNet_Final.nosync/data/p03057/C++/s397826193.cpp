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

const int maxn = (int) 2e5 + 5;
int n, m;
string s;
char tmp[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

int dp1[maxn][2];
int dp[maxn];
int toadd[maxn];

void solve() {
  if (s[0] == 'B') {
    for (int i = 0; i < m; i++) {
      if (s[i] == 'B') {
        s[i] = 'R';
      } else {
        s[i] = 'B';
      }
    }
  }
  int d = inf;
  for (int j = 0; j < m;) {
    if (s[j] == 'B') {
      j++;
      continue;
    }
    int i = j;
    while (j < m && s[j] == 'R') {
      j++;
    }
    if (j == m) {
      continue;
    }
    int len = j - i;
    if (!(len & 1)) {
      if (i) {
        continue;
      }
      len++;
    }
    d = min(d, len);
  }
  if (d >= inf) {
    int res = 0;
    dp1[1][0] = 1;
    dp1[1][1] = 0;
    for (int i = 2; i <= n; i++) {
      {
        auto &cur = dp1[i][0];
        cur = dp1[i - 1][0];
        add(cur, dp1[i - 1][1]);
      }
      {
        auto &cur = dp1[i][1];
        cur = dp1[i - 1][0];
      }
    }
    add(res, dp1[n][0]);
    add(res, dp1[n][1]);
    dp1[1][0] = 0;
    dp1[1][1] = 1;
    for (int i = 2; i <= n; i++) {
      {
        auto &cur = dp1[i][0];
        cur = dp1[i - 1][0];
        add(cur, dp1[i - 1][1]);
      }
      {
        auto &cur = dp1[i][1];
        cur = dp1[i - 1][0];
      }
    }
    add(res, dp1[n][0]);
    printf("%d\n", res);
    return;
  }
  if (n & 1) {
    printf("0\n");
    return;
  }
  for (int i = 0; i <= n; i++) {
    toadd[i] = 0;
    dp[i] = 0;
  }
  dp[0] = 1;
  int curadd = 0;
  for (int i = 0; i < n; i += 2) {
    add(curadd, toadd[i]);
    auto &cur = dp[i];
    add(cur, curadd);
    if (!cur) {
      continue;
    }
    int l = i + 2, r = i + d + 3;
    if (l >= n) {
      continue;
    }
    add(toadd[l], cur);
    if (r < n) {
      add(toadd[r], mod - cur);
    }
  }
  int res = 0;
  for (int i = max(0, n - d - 1); i < n; i += 2) {
    auto cur = dp[i];
    if (!cur) {
      continue;
    }
    int len = n - i;
    add(res, mul(cur, len));
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
