#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 20;
int n, m;
char s[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  memset(s, 0, sizeof(s));
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  return true;
}

bool used[maxn][maxn];

void solve() {
  memset(used, 0, sizeof(used));
  int x = 0, y = 0;
  used[n - 1][m - 1] = 1;
  while (x != n - 1 || y != m - 1) {
    bool ok = false;
    used[x][y] = 1;
    if (s[x + 1][y] == '#') {
      x++;
      ok = true;
      continue;
    }
    if (s[x][y + 1] == '#') {
      y++;
      ok = true;
      continue;
    }
    if (!ok) {
      printf("Impossible\n");
      return;
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#' && !used[i][j]) {
        ok = false;
      }
    }
  }
  printf(ok ? "Possible\n" : "Impossible\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}