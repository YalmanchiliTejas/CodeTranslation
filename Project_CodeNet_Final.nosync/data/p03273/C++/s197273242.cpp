#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> squares(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < W; j++) {
      squares.at(i).at(j) = input.at(j);
    }
  }

  for (int i = 0; i < H; i++) {
    int flag = 0;
    for (int j = 0; j < W; j++) {
      if (squares.at(i).at(j) == '#') {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      for (int j = 0; j < W; j++) {
        squares.at(i).at(j) = '*';
      }
    }
  }

  for (int i = 0; i < W; i++) {
    int flag = 0;
    for (int j = 0; j < H; j++) {
      if (squares.at(j).at(i) == '#') {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      for (int j = 0; j < H; j++) {
        squares.at(j).at(i) = '*';
      }
    }
  }

  for (int i = 0; i < H; i++) {
    int flag = 0;
    for (int j = 0; j < W; j++) {
      if (squares.at(i).at(j) == '*') {
        continue;
      }
      flag = 1;
      cout << squares.at(i).at(j);
    }
    if (flag == 0) {
      continue;
    }
    cout << endl;
  }
}
