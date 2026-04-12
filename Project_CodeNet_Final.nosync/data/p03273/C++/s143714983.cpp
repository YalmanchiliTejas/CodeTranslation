#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));

  rep(i, H) {
    rep(j, W) {
      cin >> data.at(i).at(j);
    }
  }

  bool flg = true;
  unordered_set<int> rows;
  unordered_set<int> cols;
  rep(i, H) {
    rep(j, W) {
      if (data.at(i).at(j) == '#') {
        flg = false;
        break;
      }
    }
    if (flg) {
      rows.insert(i);
    } else {
      flg = true;
    }
  }

  rep(j, W) {
    rep(i, H) {
      if (data.at(i).at(j) == '#') {
        flg = false;
        break;
      }
    }
    if (flg) {
      cols.insert(j);
    } else {
      flg = true;
    }
  }

  rep(i, H) {
    if (rows.find(i) == rows.end()) {
      rep(j, W) {
        if (cols.find(j) == cols.end()) {
          cout << data.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
