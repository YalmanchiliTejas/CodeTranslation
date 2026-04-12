#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int H, W;

void solve(string a[]) {
  bool ans[H][W];
  fill(ans[0], ans[H], false);
  REP(i, H) {
    bool check = false;
    REP(k, W) {
      if (a[i][k] == '#') {
        check = true;
        break;
      }
    }
    if (check) {
      REP(k, W) {
        ans[i][k] = true;
      }
    }
  }
  REP(i, W) {
    bool check = false;
    REP(k, H) {
      if (a[k][i] == '#') {
        check = true;
        break;
      }
    }
    if (!check) {
      REP(k, H) {
        if (a[k][i] == '.')
          ans[k][i] = false;
      }
    }
  }
  REP(i, H) {
    bool check = false;
    REP(k, W) {
      if (ans[i][k]) {
        cout << a[i][k];
        check = true;
      }
    }
    if (check)
      cout << endl;
  }
}

int main() {
  cin >> H >> W;
  string a[H];
  REP(i, H) {
    cin >> a[i];
  }
  solve(a);
}
