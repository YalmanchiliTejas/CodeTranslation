#include <cstdio>
using namespace std;

int n;
int ans[100][100];

bool WithinRange(int y, int x) {
  if (y >= n) return false;
  if (y < 0) return false;
  if (x >= n) return false;
  if (x < 0) return false;
  return true;
}

int main() {
  while (1) {
    scanf("%d", &n);
    if (n == 0) return 0;

    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        ans[i][j] = 0;
      }
    }

    int cnt = 0;
    int y = n/2+1;
    int x = n/2;
    while (cnt < n*n) {
      cnt++;

      if (!WithinRange(y, x) || ans[y][x]) {
        y--;
        x++;
        do {
          y++;
          x--;
          if (y >= n) y %= n;
          if (y < 0) y += n;
          if (x >= n) x %= n;
          if (x < 0) x += n;
        } while (!WithinRange(y, x) || ans[y][x]);
      }

      ans[y][x] = cnt;
      y++;
      x++;
    }

    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        printf("%4d", ans[i][j]);
      }
      puts("");
    }
  }
}