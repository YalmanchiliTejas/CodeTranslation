#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (ll (i) = 0; (i) < (n); (i)++)
#define REPI(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define int long long
using namespace std;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;

int H, W;
char a[100][100];
bool b[100], c[100];

void solve() {
  REP (i, H) {
    REP (j, W) {
      if (a[i][j] == '#') {
        b[i] = true;
        c[j] = true;
      }
    }
  }
  REP (i, H) {
    if (!b[i]) { continue; }
    REP (j, W) {
      if (!c[j]) { continue; }
      cout << a[i][j];
    }
    cout << endl;
  }
}

signed main() {
  cin >> H >> W;
  REP (i, H) {
    REP (j, W) {
      cin >> a[i][j];
    }
  }
  solve();
}
