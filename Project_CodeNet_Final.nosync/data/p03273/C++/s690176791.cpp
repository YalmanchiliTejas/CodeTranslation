#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  bool check[h][w];
  char map[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> map[i][j];
      if (map[i][j] == '.') check[i][j] = true;
      else check[i][j] = false;
    }
  }
  for (int i = 0; i < h; i++) {
      bool a = true;
      for (int x = 0; x < w; x++) {
        if (check[i][x]!=true) a = false;
      }
      if (a==true) continue;

      for (int j = 0; j < w; j++) {
        bool b = true;
        for (int y = 0; y < h; y++) {
          if (check[y][j] != true) b = false;
        }
        if (b == true) continue;
        else {
          cout << map[i][j];
        }
      }
    cout << '\n';
  }
}
