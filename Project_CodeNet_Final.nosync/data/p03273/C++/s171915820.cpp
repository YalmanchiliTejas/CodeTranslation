#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < a.size(); i++) {
    bool rm = true;
    if (a[i][0] == '.') {
      for (int j = 1; j < a[i].size(); j++) {
        if (a[i][j] == '#') {
          rm = false;
          break;
        }
      }
      if (rm) {
        a.erase(a.begin() + i);
        i = -1;
        continue;
      }
    }
    for (int j = 0; j < a[0].size(); j++) {
      rm = true;
      if (a[0][j] == '.') {
        for (int z = 1; z < a.size(); z++) {
          if (a[z][j] == '#') {
            rm = false;
            break;
          }
        }
        if (rm) {
          for (int z = 0; z < a.size(); z++) {
            a[z].erase(j, 1);
          }
          i = -1;
          break;
        }
      }
    }
  }

  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << endl;
  }
}