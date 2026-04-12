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
  int h = 0;
  vector<vector<char>> vec2(H, vector<char>(W));
  //行の探索
  for (int i = 0; i < H; i++) {
    int count = 0;
    for (int j = 0; j < W; j++) {
      if (vec.at(i).at(j) == '.') {
        count++;
      }
    }
    if (count == W) {
      h++;
    } else {
      for (int j = 0; j < W; j++) vec2.at(i - h).at(j) = vec.at(i).at(j);
    }
  }
  int w = 0;
  vector<vector<char>> vec3(H - h, vector<char>(W));
  for (int j = 0; j < W; j++) {
    int count = 0;
    for (int i = 0; i < H - h; i++) {
      if (vec2.at(i).at(j) == '.') {
        count++;
      }
    }
    if (count == H - h) {
      w++;
    } else {
      for (int i = 0; i < H - h; i++) {
        vec3.at(i).at(j - w) = vec2.at(i).at(j);
      }
    }
  }

  for (int i = 0; i < H - h; i++) {
    for (int j = 0; j < W - w; j++) {
      cout << vec3.at(i).at(j);
      if (j == W - w - 1) {
        cout << endl;
      }
    }
  }
}
