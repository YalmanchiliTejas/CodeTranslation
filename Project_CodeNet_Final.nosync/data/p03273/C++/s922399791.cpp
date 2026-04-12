#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> table(H, vector<char>(W));
  vector<bool> row(H);
  vector<bool> col(W);

  for (size_t i = 0; i < H; i++) {
    string tmp;
    cin >> tmp;

    for (size_t j = 0; j < W; j++) {
      table.at(i).at(j) = tmp.at(j);
    }
  }

  for (size_t i_h = 0; i_h < H; i_h++) {
    for (size_t i_w = 0; i_w < W; i_w++) {
      if (table.at(i_h).at(i_w) == '#') {
        row.at(i_h) = true;
        col.at(i_w) = true;
      }
    }
  }

  
  for (size_t i_h = 0; i_h < H; i_h++) {
    int count = 0;
    for (size_t i_w = 0; i_w < W; i_w++) {
      if (row.at(i_h) && col.at(i_w)) {
        cout << table.at(i_h).at(i_w);
        count++;
      }
    }
    if (count > 0) cout << endl;
    count = 0;
  }
}
