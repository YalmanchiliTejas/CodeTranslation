#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) {
    rep(j, w) {
      cin >> a.at(i).at(j);
    }
  }
  bool ok = true;
  rep(i, h) {
    rep(j, w) {
      bool isStart = false;
      bool isGoal = false;
      if (i == h - 1 && j == w - 1) {
        isGoal = true;
      }
      if (i == 0 && j == 0) {
        isStart = true;
      }
      char cur = a.at(i).at(j);
      if (cur != '#') {
        continue;
      }
      bool rightOk = false;
      bool bottomOk = false;
      int ni = i + 1;
      int nj = j + 1;
      if (ni >= 0 && ni < h) {
        rightOk = a.at(ni).at(j) == '#';
      }
      if (nj >= 0 && nj < w) {
        bottomOk = a.at(i).at(nj) == '#';
      }
      // 右か下かどちらかにだけいける場合がOK
      if (!isGoal) {
        if ((rightOk && bottomOk) || (!rightOk && !bottomOk)) {
          ok = false;
        }
      }
      int ni2 = i - 1;
      int nj2 = j - 1;
      bool leftOk = false;
      bool upOk = false;
      if (ni2 >= 0 && ni2 < h) {
        leftOk = a.at(ni2).at(j) == '#';
      }
      if (nj2 >= 0 && nj2 < w) {
        upOk = a.at(i).at(nj2) == '#';
      }
      // 上か左かどちらかからだけこれる場合がOK
      if (!isStart) {
        if ((leftOk && upOk) || (!leftOk && !upOk)) {
          ok = false;
        }
      }
    }
  }
  cout << (ok ? "Possible" : "Impossible") << endl;
  return 0;
}
