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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int dp[maxn];
int rdp[maxn];

void dfs(int v, int p) {
  dp[v] = false;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
    if (!dp[u]) {
      dp[v] = true;
    }
  }
}

bool res;

void dfs1(int v, int p, int up) {
  int cnt = !up;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    if (!dp[u]) {
      cnt++;
    }
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    if (cnt - (!dp[u])) {
      rdp[u] = true;
    } else {
      rdp[u] = false;
    }
    dfs1(u, v, rdp[u]);
  }
  if (sz(g[v]) == 1) {
    int cur;
    if (p == -1) {
      cur = dp[g[v][0]];
    } else {
      cur = rdp[v];
    }
    if (cur) {
      res = true;
    }
  }
}

void solve() {
  res = false;
  dfs(0, -1);
  dfs1(0, -1, true);
  if (res) {
    printf("First\n");
  } else {
    printf("Second\n");
  }
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
