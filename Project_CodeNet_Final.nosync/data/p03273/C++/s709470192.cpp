// AtCoder Beginner Contest 108
// B - Grid Compression
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> a(h);
  rep (i, h) cin >> a.at(i);

  vector<bool> hflg(h, false);
  vector<bool> wflg(w, false);

  rep (i, h) {
    rep (j, w) {
      if (a.at(i).at(j) == '#') {
        hflg.at(i) = true;
        wflg.at(j) = true;
      }
    }
  }

  rep (i, h) {
    if (hflg.at(i) == true) {
      rep (j, w) {
        if (wflg.at(j) == true) {
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }

  return 0;
}