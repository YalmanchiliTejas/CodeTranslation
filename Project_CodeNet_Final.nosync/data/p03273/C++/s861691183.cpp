#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc107_b.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int H, W;
  cin >> H >> W;

  vector<vector<char>> a(H, vector<char>(W));
  rep(i, H) rep(j, W) { cin >> a[i][j]; }

  vector<int> rows(0);
  rep(i, H) {
    bool ok = false;
    rep(j, W) {
      if (a[i][j] == '#') {
        ok = true;
        break;
      }
    }
    if (ok) rows.push_back(i);
  }

  vector<int> cols(0);
  rep(i, W) {
    bool ok = false;
    rep(j, H) {
      if (a[j][i] == '#') {
        ok = true;
        break;
      }
    }
    if (ok) cols.push_back(i);
  }

  for(auto i : rows) {
    for (auto j : cols) {
      cout << a[i][j];
    }
    cout << endl;
  }
}