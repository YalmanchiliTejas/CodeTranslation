#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> gyo(H);
  for (int i =0; i < H; i++) {
    cin >> gyo.at(i);
  }
  vector<bool> tate(H, false);
  vector<bool> yoko(W, false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (gyo.at(i).at(j) == '#') {
        tate.at(i) = true;
        yoko.at(j) = true;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if (tate.at(i)) {
      for (int j = 0; j < W; j++) {
        if(yoko.at(j)) {
          cout << gyo.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}