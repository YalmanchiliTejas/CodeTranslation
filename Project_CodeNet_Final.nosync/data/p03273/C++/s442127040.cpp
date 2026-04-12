
#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w;
  char a[100][100];
  bool hu[100], wu[100];
  cin >> h >> w;
  for(int i = 0; i < 100; i++) {
    hu[i] = wu[i] = false;
  }
  for (int i = 0; i < h; i++) {
    cin >> a[i];
    for(int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        wu[j] = true;
        hu[i] = true;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    if (hu[i]) {
      for (int j = 0; j < w; j++) {
        if (wu[j]) {
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}