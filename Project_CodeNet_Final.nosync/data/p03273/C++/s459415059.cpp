#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int H, W;
  cin >> H >> W;

  char grid[H][W];
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> grid[i][j];
    }
  }

  int w_left = 0;
  int w_right = W -1;
  int h_top = 0;
  int h_bot = H - 1;
  while (true) {
    bool changed = false;
    // search rows
    for (int i = h_top; i <= h_bot; ++i) {
      if (grid[i][w_left] == '.') {
        bool all = true;
        for (int j = w_left; j <= w_right; ++j) {
          if (grid[i][j] == '#') {
            all = false;
            break;
          }
        }

        // shrink
        int target_row = i;
        if (all) {
          for (int m = target_row; m >= h_top; --m) {
            for (int n = w_left; n <= w_right; ++n) {
              grid[m][n] = grid[m - 1][n];
            }
          }
          ++h_top;
          changed = true;
          break;
        }
      }
    }

    // serch columns
    for (int i = w_left; i <= w_right; ++i) {
      if (grid[h_top][i] == '.') {
        bool all = true;
        for (int j = h_top; j <= h_bot; ++j) {
          if (grid[j][i] == '#') {
            all = false;
            break;
          }
        }

        // srink
        int target_column = i;
        if (all) {
          for (int m = h_top; m <= h_bot; ++m) {
            for (int n = target_column; n < w_right; ++n) {
              grid[m][n] = grid[m][n + 1];
            }
          }
          --w_right;
          changed = true;
          break;
        }
      }
    }

//cout << h_top << " " << w_right << endl;

    if (!changed)
      break;
  }

  for (int i = h_top; i <= h_bot; ++i) {
    for (int j = w_left; j <= w_right; ++j) {
      cout << grid[i][j];
    }
    cout << endl;
  }

  return 0;
}