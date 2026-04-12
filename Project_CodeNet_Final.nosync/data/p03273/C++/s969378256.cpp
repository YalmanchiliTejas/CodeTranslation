#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for (int row = 0; row < H; row++) {
    for (int column = 0; column < W; column++) {
      cin >> data.at(row).at(column);
    }
  }
  int press = 0;
  for (int column = 0; column < W; column++) {
    for (int row = 0; row < H; row++) {
      if (data.at(row).at(column) == '#') {
        break;
      }
      else if (row == H - 1) {
        press++;
      }
    }
  }
  int i = 0;
  vector<vector<char>> pressed(H, vector<char>(W - press));
  for (int column = 0; column < W; column++) {
    bool check = false;
    for (int row = 0; row < H; row++) {
      if (data.at(row).at(column) == '#') {
        check = true;
        break;
      }
    }
    if (check) {
      for (int row = 0; row < H; row++) {
        pressed.at(row).at(i) = data.at(row).at(column);
      }
      i++;
    }
  }
  for (int row = 0; row < H; row++) {
    bool check = false;
    for (int column = 0; column < W - press; column++) {
      if (pressed.at(row).at(column) == '#') {
        check = true;
        break;
      }
    }
    if (check) {
      for (int column = 0; column < W - press; column++) {
        cout << pressed.at(row).at(column);
      }
      cout << endl;
    }
  }
}
