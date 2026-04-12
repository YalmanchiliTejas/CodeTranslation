#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int H, W;
  cin >> H >> W;

  char a[H][W];

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> a[i][j];
    }
  }

  int x = 0;
  int y = 0;
  a[0][0] = '.';
  while (true) {
    if (x < W - 1 && a[y][x + 1] == '#')
      ++x;
    else if (y < H - 1 && a[y + 1][x] == '#')
      ++y;
    else
      break;
    a[y][x] = '.';
    if (x == W - 1 && y == H - 1)
      break;
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (a[i][j] == '#') {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }

  cout << "Possible" << endl;

  return 0;
}