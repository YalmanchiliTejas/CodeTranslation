#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++) cin >> a.at(i);
  for (int y = 0; y < H; y++) {
    bool flag_y = false;
    for (int x = 0; x < W; x++) {
      if (a.at(y).at(x) == '#') {
        flag_y = true;
        cout << a.at(y).at(x);
        continue;
      }
      bool flag_x = false;
      for (int h = 0; h < H; h++) {
        if (a.at(h).at(x) == '#') flag_x = true;
      }
      for (int w = 0; w < W; w++) {
        if (a.at(y).at(w) == '#') flag_y = true;
      }
      if (flag_x && flag_y) cout << '.';
    }
    if (flag_y) cout << endl;
  }
}