#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> gridTable(H, vector<char>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> gridTable.at(i).at(j);
    }
  }

  vector<bool> rowFlag(H, false), colFlag(W, false);

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (gridTable.at(i).at(j) == '#') {
        rowFlag.at(i) = true;
        colFlag.at(j) = true;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (rowFlag.at(i)) {
      for (int j = 0; j < W; j++) {
        if (colFlag.at(j)) cout << gridTable.at(i).at(j);
      }
      cout << endl;
    }
  }
}
