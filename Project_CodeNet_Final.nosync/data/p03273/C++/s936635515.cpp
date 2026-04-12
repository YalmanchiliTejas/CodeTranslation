#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  scanf("%d%d", &H, &W);

  vector<string> grid(H);
  for (int i = 0; i < H; i++) {
    cin >> grid.at(i);
  }

  vector<bool> row(H, false);
  vector<bool> col(W, false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid.at(i).at(j) == '#') {
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (row.at(i)) {
      for (int j = 0; j < W; j++) {
        if (col.at(j)) {
          cout << grid.at(i).at(j);
        }
      }
      cout << endl;
    }
  }

  return 0;
}
