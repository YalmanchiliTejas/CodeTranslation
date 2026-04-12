#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int h, w;
  string a[100];
  int yy[100] = {0};
  int xx[100] = {0};
  cin >> h >> w;
  rep(0, h) { cin >> a[i]; }

  for (int y = 0; y < h; ++y) {
    string s = a[y];
    for (int x = 0; x < w; ++x) {
      if (s[x] == '#') {
        yy[y]++;
        xx[x]++;
      }
    }
  }

  for (int y = 0; y < h; ++y) {
    if (yy[y] == 0) {
      continue;
    }
    for (int x = 0; x < w; ++x) {
      if (xx[x] == 0) {
        continue;
      }
      cout << a[y][x];
    }
    cout << endl;
  }

  return 0;
}
