#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> table(H, vector<char>(W));
  vector<bool> rows_have_black(H, false);
  vector<bool> columns_have_black(W, false);

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table.at(i).at(j);
      if (table.at(i).at(j) == '#') {
        rows_have_black.at(i) = true;
        columns_have_black.at(j) = true;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (rows_have_black.at(i)) {
      for (int j = 0; j < W; j++) {
        if (columns_have_black.at(j)) {
          cout << table.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
