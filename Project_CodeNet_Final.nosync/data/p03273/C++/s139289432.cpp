#include <iostream>
#include <vector>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> G(H);
  rep(i, H) {
    cin >> G[i];
  }
  vector<int> rows, cols;
  rep(i, H) {
    bool ok = false;
    rep(k, W) if (G[i][k] == '#') {
      ok = true;
      break;
    }
    if (ok) rows.push_back(i);
  }
  rep(k, W) {
    bool ok = false;
    rep(i, H) if (G[i][k] == '#') {
      ok = true;
      break;
    }
    if (ok) cols.push_back(k);
  }
  for (auto r : rows) {
    for (auto c : cols) cout << G[r][c];
    cout << endl;
  }
  return 0;
}