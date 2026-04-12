#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    bool flag = 1;
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        flag = 0;
        break;
      }
    }
    if (flag) {
      a.erase(a.begin() + i);
      i--;
      h--;
    }
  }

  vector<vector<char>> b(w, vector<char>(h));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      b[j][i] = a[i][j];
    }
  }
  for (int i = 0; i < w; i++) {
    bool flag = 1;
    for (int j = 0; j < h; j++) {
      if (b[i][j] == '#') {
        flag = 0;
        break;
      }
    }
    if (flag) {
      b.erase(b.begin() + i);
      i--;
      w--;
    }
  }
  vector<vector<char>> ans(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      ans[i][j] = b[j][i];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}