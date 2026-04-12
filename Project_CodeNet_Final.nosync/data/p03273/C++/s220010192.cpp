#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<bool> row(H, 0);
  vector<bool> col(W, 0);
  vector<vector<char>> date(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> date.at(i).at(j);
      if (date.at(i).at(j) == '#') {
        row.at(i) = 1;
        col.at(j) = 1;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (row.at(i)) {
      for (int j = 0; j < W; j++) {
        if (col.at(j)) cout << date.at(i).at(j);
      }
      cout << endl;
    }
  }
}
