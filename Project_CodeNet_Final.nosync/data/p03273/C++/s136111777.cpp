#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  char a[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  bool r[h] = {}, c[w] = {};
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        r[i] = true;
      }
    }
  }
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (a[j][i] == '#') {
        c[i] = true;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (r[i] && c[j]) {
        cout << a[i][j];
      }
    }
    if (r[i]) {
      cout << '\n';
    }
  }
  return 0;
}
