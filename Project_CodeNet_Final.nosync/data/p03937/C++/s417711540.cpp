#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
int H, W;
int ALL_STEP;

bool dfs(vector<vector<char>> &A, int y, int x, int step) {
  if (y == (H - 1) && x == (W - 1)) {
    return (step == ALL_STEP);
  }
  int ny = y + 1;
  int nx = x + 1;
  bool ret = false;
  if (ny < H && A[ny][x] == '#') ret |= dfs(A, ny, x, step + 1);
  if (nx < W && A[y][nx] == '#') ret |= dfs(A, y, nx, step + 1);
  return ret;
}

int main(void) {
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  ALL_STEP = 0;
  rep(i, H) rep(j, W) {
    cin >> A[i][j];
    if (A[i][j] == '#') ALL_STEP++;
  }

  if (A[0][0] == '.') {
    cout << "Impossible" << endl;
    return 0;
  }

  if (dfs(A, 0, 0, 1)) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}