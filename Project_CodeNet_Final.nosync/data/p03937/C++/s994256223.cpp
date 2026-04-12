#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

char grid[20][20];
bool used[20][20];

int main() {
  // 入力
  int H, W;
  cin >> H >> W;
  fill(grid[0], grid[19], '.');
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> grid[i][j];
    }
  }

  int x = 1, y = 1;
  bool flag = false;
  while (1) {
    used[y][x] = true;

    if (grid[y+1][x] == '#' && grid[y][x+1] == '.') {
      y++;
    } else if (grid[y+1][x] == '.' && grid[y][x+1] == '#') {
      x++;
    } else {
      break;
    }

    if (y == H && x == W) {
      flag = true;
      used[y][x] = true;
      break;
    }
  }

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (grid[i][j] == '#' && !used[i][j]) flag = false;
    }
  }

  // 解答
  cout << (flag ? "Possible" : "Impossible") << endl;

  return 0;
}
