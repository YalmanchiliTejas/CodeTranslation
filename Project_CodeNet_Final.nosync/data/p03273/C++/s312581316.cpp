#include <iostream>
using namespace std;

int main() {
  int h, w;
  char a[100][100];
  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) cin >> a[i][j];
  }
  bool rows[100] = {}, columns[100] = {};
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '#') rows[i] = true;
    }
  }
  for (int j = 0; j < w; ++j) {
    for (int i = 0; i < h; ++i) {
      if (a[i][j] == '#') columns[j] = true;
    }
  }
  for (int i = 0; i < h; ++i) {
    if (!rows[i]) continue;
    for (int j = 0; j < w; ++j) {
      if (columns[j]) cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}