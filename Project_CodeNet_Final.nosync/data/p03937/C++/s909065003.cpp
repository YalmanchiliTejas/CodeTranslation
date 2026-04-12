#include <iostream>

using namespace std;

const int MAX_H = 8;
const int MAX_W = 8;
const int dx[2] = { 1, 0 }, dy[2] = { 0, 1 };

int main () {
  int H, W;
  int a[MAX_H][MAX_W];
  cin >> H >> W;
  for (int i=0;i<H;i++) {
    char tmp[MAX_W];
    cin >> tmp;
    for (int j=0;j<W;j++) {
      if (tmp[j] == '#') {
        a[i][j] = 1;
      } else {
        a[i][j] = 0;
      }
    }
  }

  int y, x, ny, nx;
  bool flag;
  y = x = 0;
  a[y][x] = 0;
  while (!flag) {
    flag = true;
    for (int i=0;i<2;i++) {
      ny = y+dy[i]; nx = x+dx[i];
      if (H <= ny || W <= nx) continue;
      if (a[ny][nx] == 1) {
        a[ny][nx] = 0;
        y = ny; x = nx;
        flag = false;
        break;
      }
    }
  }
  int sum = 0;
  for (int i=0;i<H;i++) {
    for (int j=0;j<W;j++) {
      sum += a[i][j];
    }
  }

  cout << (0<sum?"Impossible":"Possible") << endl;
  return 0;
}
