#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> a(H, vector<char>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }

  for (int i = 0; i < H; i++) {
    int c_dot = 0;

    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '.') {
        c_dot++;
      }
    }

    if (c_dot == W) {
      for (int j = 0; j < W; j++) {
        a.at(i).at(j) = ' ';
      }
    }
  }

  for (int j = 0; j < W; j++) {
    int c_dot = 0;

    for (int i = 0; i < H; i++) {
      if (a.at(i).at(j) == '.' || a.at(i).at(j) == ' ') {
        c_dot++;
      }
    }

    if (c_dot == H) {
      for (int i = 0; i < H; i++) {
        a.at(i).at(j) = ' ';
      }
    }
  }

  for (int i = 0; i < H; i++) {
    int c_space = 0;

    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == ' ') {
        c_space++;
      }
    }

    if (c_space == W) {
      continue;
    }

    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) != ' ') {
        cout << a.at(i).at(j);
      }
    }

    cout << endl;
  }
}
