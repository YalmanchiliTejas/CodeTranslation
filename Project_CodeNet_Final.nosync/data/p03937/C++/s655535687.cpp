#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  string a[h];
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  int right = 0, down = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j < w - 1 && a[i][j] == '#' && a[i][j + 1] == '#') {
        right++;
      }
      if (i < h - 1 && a[i][j] == '#' && a[i + 1][j] == '#') {
        down++;
      }
    }
  }
  cout << (right == w - 1 && down == h - 1 ? "Possible" : "Impossible") << endl;
}