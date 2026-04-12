#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int n;
  while(cin >> n && n) {
    int g[n][n];
    fill(g[0], g[n], 0);
    int x, y;
    x = n/2;
    y = n/2+1;
    g[y][x] = 1;
    for(int i = 1; i < n*n; ++i) {
      x = (x+1)%n;
      y = (y+1)%n;
      while(g[y][x] != 0) {
        x = (x+n-1)%n;
        y = (y+1)%n;
      }
      g[y][x] = i+1;
    }

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        printf("%4d", g[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}