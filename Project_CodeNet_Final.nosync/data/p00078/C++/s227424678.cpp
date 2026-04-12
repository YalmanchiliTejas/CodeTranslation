#include <iostream>
#include <iomanip>
using namespace std;

int n;
int m[15][15];

void func(int x, int y, int l) {
  int nx, ny;
  if (!m[x][y]) {
    m[x][y] = l;
    if (l == n*n) return;
    if (x<n-1) nx = x+1;
    else nx = 0;
    if (y<n-1) ny = y+1;
    else ny = 0;
    func(nx, ny, l+1);
  } else {
    if (x<n-1) nx = x+1;
    else nx = 0;
    if (y) ny = y-1;
    else ny = n-1;
    func(nx, ny, l);
  }
}

int main() {
  int c;
  while (1) {
    cin >> n;
    if (!n) break;
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        m[i][j] = 0;
      }
    }
    c = 0;
    func(n/2+1, n/2, 1);
    for (int i=0; i<n; ++i) {
      for (int j=0; j<n; ++j) {
        cout << setw(4) << m[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}