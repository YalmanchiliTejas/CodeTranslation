#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int H, W;
char c[10][10];

bool f(int y, int x) {
  if (y < 0 || x < 0 || c[y][x] == '.') return false;
  if (y == 0 && x == 0) return true;
  return f(y-1, x) || f(y, x-1);
}

int main() {
  cin >> H >> W;
  int ctr = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> c[i][j];
      if (c[i][j] == '#') ctr++;
    }
  }
  if (ctr != W+H-1 || c[0][0] == '.') cout << "Impossible\n";
  else {
    cout << (f(H-1, W-1) ? "Possible" : "Impossible") << "\n";
  }
  return 0;
}

