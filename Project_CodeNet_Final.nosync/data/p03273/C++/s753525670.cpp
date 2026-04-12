#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int h, w;
  std::vector<std::string> a;

  cin >> h >> w;
  a.resize(h);
  for (int i = 0; i < h; ++i) {
    cin >> a[i];
  }

  bool row[101], col[101];
  
  std::fill(row, row + h, false);
  std::fill(col, col + w, false);

  for (int i = 0; i < h; ++i) {
    int cnt = 0;
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '#') {
        cnt++;
      }
    }

    if (cnt == 0) {
      row[i] = true;
    }
  }

  for (int i = 0; i < w; ++i) {
    int cnt = 0;
    for (int j = 0; j < h; ++j) {
      if (a[j][i] == '#') {
        cnt++;
      }
    }

    if (cnt == 0) {
      col[i] = true;
    }
  }
  for (int i = 0; i < h; ++i) {
    if (row[i]) {
      continue;
    }
    for (int j = 0; j < w; ++j) {
      if (col[j]) {
        continue;
      }

      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}