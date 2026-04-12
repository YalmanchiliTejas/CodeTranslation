#include "bits/stdc++.h"
using namespace std;
#define forn(i, x, n) for (int i = x; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
typedef long double ld;
typedef long long ll;
template <typename... Args> void dbg(Args &&... args) {
  using expander = int[];
  (void)expander{
      0,
      (static_cast<void>(void(cout << std::forward<Args>(args) << " ")), 0)...};
  cout << endl;
}
void gen() {
  exit(0);
}

const int N = 103;
int h, w;
char a[N][N];

void input() {
  scanf("%d %d", &h, &w);
  forn(i, 0, h) {
    forn(j, 0, w) {
      scanf(" %c", &a[i][j]);
    }
  }
}

void solve() {
  forn(i, 0, h) {
    bool bad = true;
    forn(j, 0, w) {
      if (a[i][j] == '#')
        bad = false;
    }
    if (bad) {
      forn(j, 0, w) {
        a[i][j] = 'x';
      }
    }
  }
  forn(i, 0, w) {
    bool bad = true;
    forn(j, 0, h) {
      if (a[j][i] == '#')
        bad = false;
    }
    if (bad) {
      forn(j, 0, h) {
        a[j][i] = 'x';
      }
    }
  }

  forn(i, 0, h) {
    bool nl = false;
    forn(j, 0, w) {
      if (a[i][j] != 'x') {
        printf("%c", a[i][j]);
        nl = true;
      }
    }
    if (nl)
      printf("\n");
  }
}

int main() {
#ifdef DEBUG
  freopen("input", "r", stdin);
//  freopen("output", "w", stdout);
//  gen();
#endif
  input();
  solve();
  return 0;
}
