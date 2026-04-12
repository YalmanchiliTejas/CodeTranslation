#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(20);

  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];

  vector<int> row_ok;
  rep(i, h) {
    bool ok = true;
    rep(j, w) {
      if (a[i][j] != '.') {
        ok = false;
        break;
      }
    }
    if (ok) row_ok.push_back(i);
  }

  vector<int> col_ok;
  rep(j, w) {
    bool ok = true;
    rep(i, h) {
      if (a[i][j] != '.') {
        ok = false;
        break;
      }
    }
    if (ok) col_ok.push_back(j);
  }

  rep(i, h) {
    if (find(row_ok.begin(), row_ok.end(), i) != row_ok.end()) continue;
    rep(j, w) {
      if (find(col_ok.begin(), col_ok.end(), j) != col_ok.end()) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
