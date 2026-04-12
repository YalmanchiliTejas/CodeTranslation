#include<iostream>
#include<cstdio>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  int a[20][20];
  int n;
  while (true) {
    cin >> n;
    if (n == 0) break;
    int x = n / 2 - 1, y = n / 2;
    rep (i, n) rep (j, n) a[i][j] = -1;
    rep (i, n * n) {
      x = (x + 1) % n;
      y = (y + 1) % n;
      while (a[y][x] != -1) {
	x = (x + n - 1) % n;
	y = (y + 1) % n;
      }
      a[y][x] = i + 1;
    }
    rep (i, n) {
      rep (j, n) printf("%4d", a[i][j]);
      puts("");
    }
  }
  return 0;
}