#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int h, w; cin >> h >> w;
  int a[101][101] = {};
  for (int i = 0; i < h; i++) {
    string ss; cin >> ss;
    for (int j = 0; j < w; j++) {
      if (ss[j] == '#') a[i][j] = 1;
    }
  }

  bool no_change = false;
  while(!no_change) {
    // row check
    for (int i = 0; i < h; i++) {
      bool all_white = true;
      for (int j = 0; j < w; j++) {
        if (a[i][j]<0) continue;
        if (a[i][j]>0) {
          all_white = false;
          no_change = true;
          break;
        }
      }
      if (all_white) {
        for (int j = 0; j < w; j++) {
          a[i][j] = -1;
        }
      }
    }

    // col check
    for (int j = 0; j < w; j++) {
      bool all_white = true;
      for (int i = 0; i < h; i++) {
        if (a[i][j]<0) continue;
        if (a[i][j]>0) {
          all_white = false;
          no_change = true;
          break;
        }
      }
      if (all_white) {
        for (int i = 0; i < h; i++) {
          a[i][j] = -1;
        }
      }
    }
  }

  for (int i = 0; i < h; i++) {
    bool need_endl = false;
    for (int j = 0; j < w; j++) {
      if (a[i][j]<0) continue;
      if (a[i][j]>0) cout << '#';
      else cout << '.';
      need_endl = true;
    }
    if (need_endl)
      cout << endl;
  }
}