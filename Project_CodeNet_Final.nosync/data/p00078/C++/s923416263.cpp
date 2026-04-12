#include <iostream>

using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      break;

    int x = n / 2;
    int y = n / 2 - 1;
    int ans[15][15] = {};

    for (int i = 1; i <= n * n; ++i) {
      x = (x + 1 + n) % n;
      y = (y + 1 + n) % n;
      while (ans[x][y]) {
        x = (x + 1 + n) % n;
        y = (y - 1 + n) % n;
      }
      ans[x][y] = i;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        printf("%4d", ans[i][j]);
      printf("\n");
    }
  }
}
