#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
  int h, w;
  cin >> h >> w;
  char data[h][w];
  rep(i, h) {
    rep(j, w) {
      cin >> data[i][j];
    }
  }


  rep(i, h) {
    bool only_white = true;
    rep(j, w) {
      if (data[i][j] == '#') only_white = false;
    }
    if (only_white) {
      rep(j, w) {
        data[i][j] = ' ';
      }
    }
  }

  rep(j, w) {
    bool only_white = true;
    rep(i, h) {
      if (data[i][j] == '#') only_white = false;
    }
    if (only_white) {
      rep(i, h) {
        data[i][j] = ' ';
      }
    }
  }

  rep(i, h) {
    bool only_white = true;
    rep(j, w) {
      if (data[i][j] != ' ') {
        only_white = false;
        cout << data[i][j];
      }
    }
    if (!only_white) cout << endl;
  }
}
