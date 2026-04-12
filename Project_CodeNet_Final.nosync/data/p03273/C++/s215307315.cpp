#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> chart(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> chart.at(i).at(j);
    }
  }
  vector<bool> line(H, false);
  vector<bool> row(W, false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (chart.at(i).at(j) == '#') {
        line.at(i) = true;
        row.at(j) = true;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if (line.at(i)) {
      for (int j = 0; j < W; j++) {
        if (row.at(j)) {
          cout << chart.at(i).at(j);
        }
      }
    cout << endl;
    }
  }
}
