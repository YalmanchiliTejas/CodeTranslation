#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H);
  char a;
  REP(i, H) {
    bool all_white = true;
    REP(j, W) {
      cin >> a;
      A.at(i).push_back(a);
      if (a == '#') {
        all_white = false;
      }
    }

    if (all_white) {
      replace(A.at(i).begin(), A.at(i).end(), '.', 'x');
    }
  }

  REP(j, W) {
    bool all_white = true;
    REP(i, H) {
      if (A.at(i).at(j) == '#') {
        all_white = false;
      }
    }
    if (all_white) {
      REP(k, H) { A.at(k).at(j) = 'x'; }
    }
  }

  REP(i, H) {
    bool empty = true;
    REP(j, W) {
      if (A.at(i).at(j) != 'x') {
        cout << A.at(i).at(j);
        empty = false;
      }
    }

    if (!empty) {
      cout << endl;
    }
  }

  return 0;
}
