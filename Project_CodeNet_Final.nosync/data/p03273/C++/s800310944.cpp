#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  vector<int> rows(H, 0);
  vector<int> cols(W, 0);
  for (int h = 0; h < H; ++h) {
    for (int w = 0; w < W; ++w) {
      cin >> grid[h][w];
      if (grid[h][w] == '#') {
        ++rows[h];
        ++cols[w];
      }
    }
  }

  for (int h = 0; h < H; ++h) {
    if (rows[h] == 0) continue;
    for (int w = 0; w < W; ++w) {
      if (cols[w] == 0) continue;
      cout << grid[h][w];
    }
    cout << endl;
  }
  return 0;
}
