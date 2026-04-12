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

void precalc() {
}

const int maxn = 8 + 2;
char s[maxn][maxn];

int n, m;

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  return 1;
}

void solve() {
  int x = 0, y = 0;
  for (; x + y < n + m - 2;) {
    if (s[x][y] != '#') {
      printf("Impossible\n");
      return;
    }
    if (x < n && s[x + 1][y] == '#') {
      x += 1;
      continue;
    }
    if (y < m && s[x][y + 1] == '#') {
      y += 1;
      continue;
    }
    printf("Impossible\n");
    return;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += count(s[i], s[i] + m, '#');
  }
  if (cnt != n + m - 1) {
    printf("Impossible\n");
    return;
  }
  printf("Possible\n");
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
