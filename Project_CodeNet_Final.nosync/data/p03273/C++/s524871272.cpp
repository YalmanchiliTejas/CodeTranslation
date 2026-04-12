#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> vec(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> vec.at(i).at(j);
    }
  }
  vector<int> tate(H, 0);
  vector<int> yoko(W, 0);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (vec.at(i).at(j) == '#')
        tate.at(i) = 1;
    }
  }
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (vec.at(j).at(i) == '#')
        yoko.at(i) = 1;
    }
  }
  for (int i = 0; i < H; i++) {
    if (tate.at(i) == 1) {
      for (int j = 0; j < W; j++) {
        if (yoko.at(j) == 1)
          cout << vec.at(i).at(j);
      }
      cout << endl;
    }
  }
}
