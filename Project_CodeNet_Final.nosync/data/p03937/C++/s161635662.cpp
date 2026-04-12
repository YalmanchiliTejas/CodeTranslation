#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  string a[h];
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  bool right[h][w], left[h][w];
  for (int i = 0; i < h; i++) {
    fill(right[i], right[i] + w, false);
    fill(left[i], left[i] + w, false);
    for (int j = 1; j < w; j++) {
      if (a[i][j] == '#' && a[i][j - 1] == '#')
        right[i][j - 1] = left[i][j] = true;
    }
  }
  for (int j = 0; j < w; j++) {
    for (int i = 1; i < h; i++) {
      if (a[i][j] == '#' && a[i - 1][j] == '#') {
        if (right[i - 1][j] || left[i][j]) {
          cout << "Impossible" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Possible" << endl;
  return 0;
}