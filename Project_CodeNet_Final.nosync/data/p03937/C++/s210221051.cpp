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

const int maxn = 10;
int n, m;
char c[maxn][maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

void solve() {
  if (c[0][0] != '#') {
    printf("Impossible\n");
    return;
  }
  int x = 0, y = 0;
  while (x < n - 1 || y < m - 1) {
    bool found = false;
    for (int i = 0; i < 2; i++) {
      int xx = x + i, yy = y + (i ^ 1);
      if (xx < n && yy < m && c[xx][yy] == '#') {
        x = xx;
        y = yy;
        found = true;
        break;
      }
    }
    if (!found) {
      printf("Impossible\n");
      return;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cnt += (c[i][j] == '#');
    }
  }
  if (cnt == n + m - 1) {
    printf("Possible\n");
  } else {
    printf("Impossible\n");
  }
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
