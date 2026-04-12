#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> table(H, vector<char>(W));
  vector<bool> rows(H, false);
  vector<bool> cols(W, false);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table.at(i).at(j);
      if (table.at(i).at(j) == '#') {
        rows.at(i) = true;
        cols.at(j) = true;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (!rows.at(i)) continue;
    for (int j = 0; j < W; j++) {
      if (cols.at(j)) cout << table.at(i).at(j);
    }
    cout << endl;
  }
}
