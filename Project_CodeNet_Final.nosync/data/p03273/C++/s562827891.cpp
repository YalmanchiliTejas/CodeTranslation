#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> v(H);
  for (int i = 0; i < H; i++) cin >> v[i];

  for (int i = 0; i < H; i++) {
    bool flag = true;
    for (int j = 0; j < W; j++) if (v[i][j] != '.') flag = false;
    if (flag) for (int j = 0; j < W; j++) v[i][j] = '*';
  }

  for (int i = 0; i < W; i++) {
    bool flag = true;
    for (int j = 0; j < H; j++) if (v[j][i] != '.' && v[j][i] != '*') flag = false;
    if (flag) for (int j = 0; j < H; j++) v[j][i] = '*';
  }

  for (int i = 0; i < H; i++) {
    bool flag = false;
    for (int j = 0; j < W; j++) {
      if (v[i][j] != '*') {
        cout << v[i][j];
        flag = true;
      }
    }
    if (flag) cout << endl;
  }
}
