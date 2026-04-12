#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> grid(h, vector<char>(w));

  rep(i, h) {
    rep(j, w) {
      cin >> grid.at(i).at(j);
    }
  }
  
  vector<int> h_skip(h, 1), w_skip(w, 1);
  rep(i, h) {
    rep(j, w) {
      if (grid.at(i).at(j) == '#') {
        h_skip.at(i) = 0;
        break;
      }
    }
  }

  rep(i, w) {
    rep(j, h) {
      if (grid.at(j).at(i) == '#') {
        w_skip.at(i) = 0;
        break;
      }
    }
  }

  rep(i, h) {
    if (h_skip.at(i) == 1) continue;
    rep(j, w) {
      if (w_skip.at(j) == 1) continue;
      else {
        cout << grid.at(i).at(j);
      }
    }
    cout << endl;
  }

}