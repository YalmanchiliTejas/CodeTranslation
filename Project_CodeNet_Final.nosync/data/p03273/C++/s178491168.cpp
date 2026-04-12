#include <bits/stdc++.h>
using namespace std;

char c[105][105];
set<int> xx, yy;

int main() {
  int x, y;
  cin >> x >> y;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      cin >> skipws >> c[i][j];
      if (c[i][j] == '#') {
        xx.insert(i), yy.insert(j);
      }
    }
  }
  for (int x : xx) {
    for (int y : yy)
      cout << c[x][y];
    cout << endl;
  }
}