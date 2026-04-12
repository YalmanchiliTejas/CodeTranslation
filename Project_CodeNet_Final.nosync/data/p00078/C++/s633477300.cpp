#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) return 0;

    int magic[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	magic[i][j] = -1;
      }
    }

    magic[n / 2 + 1][n / 2] = 1;
    int x = n / 2 + 1;
    int y = n / 2;
    for (int i = 2; i <= n * n; i++) {
      x++;
      y++;
      if (y >= n) y = 0;
      else if (y < 0) y = n - 1;
      if (x >= n) x = 0;
      else if (x < 0) x = n - 1;

      while (magic[x][y] != -1) {
	x++;
	y--;
	if (x >= n) x = 0;
	if (y < 0) y = n - 1;
      }
      magic[x][y] = i;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	printf("%4d", magic[i][j]);
      }
      putchar('\n');
    }
  }
}