#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <climits>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  char a[H][W + 1];
  int i, j;

  for (i = 0; i < H; i++) {
    cin >> a[i];
    a[i][W] = '\0';
  }

  int rows[H];
  int cols[W];

  for (i = 0; i < H; i++) {
    rows[i] = 0;
  }
  for (i = 0; i < W; i++) {
    cols[i] = 0;
  }

  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      if (a[i][j] == '#') {
	rows[i] = 1;
      }
    }
  }

  for (j = 0; j < W; j++) {
    for (i = 0; i < H; i++) {
      if (a[i][j] == '#') {
	cols[j] = 1;
      }
    }
  }

  for (i = 0; i < H; i++) {
    if (rows[i] == 1) {
      for (j = 0; j < W; j++) {
	if (cols[j] == 1) {
	  cout << a[i][j];
	}
      }
      cout << endl;
    }
  }

  return 0;
}