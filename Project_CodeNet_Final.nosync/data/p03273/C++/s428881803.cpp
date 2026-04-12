/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t H, W;
  cin >> H >> W;
  vector<int32_t> histgram_row(H);
  vector<int32_t> histgram_column(W);
  vector<vector<bool>> grid(H, vector<bool>(W));
  for (int32_t row = 0; row < H; ++row) {
    string s;
    cin >> s;
    for (int32_t column = 0; column < W; ++column) {
      const char ch = s.c_str()[column];
      if (ch == '#') {
        ++histgram_row[row];
        ++histgram_column[column];
        grid[row][column] = true;
      } else {
        grid[row][column] = false;
      }
    }
  }
  for (int32_t row = 0; row < H; ++row) {
    if (histgram_row[row] > 0) {
      for (int32_t column = 0; column < W; ++column) {
        if (histgram_column[column] > 0) {
          if (grid[row][column]) {
            cout << "#";
          } else {
            cout << ".";
          }
        }
      }
      cout << endl;
    }
  }

  return 0;
}
