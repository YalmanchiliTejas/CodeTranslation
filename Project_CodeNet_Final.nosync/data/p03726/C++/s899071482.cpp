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

int power(int x, int pw) {
  int res = 1;
  for (; pw; pw >>= 1) {
    if (pw & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
  }
  return res;
}

void precalc() {
}


const int maxn = (int) 1e5 + 10;
vector<vector<int> > es;
int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  es = vector<vector<int> >(n);
  for (int i = 0; i < n - 1; ++i) {
    int s, t;
    scanf("%d%d", &s, &t);
    --s, --t;
    es[s].pb(t), es[t].pb(s);
  }
  return 1;
}

int pr[maxn];
pair<int, int> tosort[maxn];
int used[maxn];

void dfs(int v, int p) {
  pr[v] = p;
  for (int u : es[v]) {
    if (u == p) {
      continue;
    }
    tosort[u] = mp(tosort[v].first + 1, u);
    dfs(u, v);
  }
}

void solve() {
  tosort[0] = mp(0, 0);
  dfs(0, -1);
  sort(tosort, tosort + n);

  for (int i = 0; i < n; ++i) {
    used[i] = 0;
  }

  for (int iter = n - 1; iter >= 0; --iter) {
    int v = tosort[iter].second;
    if (used[v]) {
      continue;
    }
    if (pr[v] == -1 || used[pr[v]]) {
      printf("First\n");
      return;
    }
    used[v] = used[pr[v]] = 1;
  }

  printf("Second\n");
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
