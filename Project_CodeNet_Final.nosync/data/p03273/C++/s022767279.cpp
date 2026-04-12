#include <bits/stdc++.h>
using namespace std;

int main(int, char**) {
  int H, W;
  cin >> H >> W;

  vector<string> grid;
  bitset<100> row_to_delete;
  for (int i = 0; i < H; i++) {
    string s;
    int cnt = 0;
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      s.push_back(c);
      if (c == '.')
        ++cnt;
    }
    grid.push_back(s);
    if (cnt == s.size())
      row_to_delete.set(i);
  }

  bitset<100> col_to_delete;
  for (int j = 0; j < W; j++) {
    int cnt = 0;
    for (int i = 0; i < H; i++) {
      if (grid[i][j] == '.')
        ++cnt;
    }
    if (cnt == H)
      col_to_delete.set(j);
  }

  for (int i = 0; i < H; i++) {
    if (row_to_delete[i])
      continue;
    for (int j = 0; j < W; j++) {
      if (!col_to_delete[j])
        cout << grid[i][j];
    }
    cout << endl;
  }

  return 0;
}
