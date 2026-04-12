#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Possible(const vector<string>& field) {
  const int H = field.size();
  const int W = field[0].size();
  static const int U = 1 << 3;
  static const int D = 1 << 2;
  static const int L = 1 << 1;
  static const int R = 1 << 0;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (field[i][j] == '.')
        continue;
      int flag = ((i > 0 && field[i - 1][j] == '#') << 3)
          + (((i < H - 1) && field[i + 1][j] == '#') << 2)
          + ((j > 0 && field[i][j - 1] == '#') << 1)
          + (((j < W - 1) && field[i][j + 1] == '#'));
      switch (flag) {
        case (U | R): case U:
        case (U | D): case L:
        case (L | R): case D:
        case (L | D): case R:
          break;
        default:
          return false;
      }
    }
  }
  return true;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> field(h);
  for (int i = 0; i < h; ++i)
    cin >> field[i];

  cout << (Possible(field) ? "Possible\n" : "Impossible\n");

  return 0;
}
