#include <iostream>
using namespace std;

int main() {
  int h,w;
  char a[8][8];
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  bool pos = true;
  for (int i = 0, j = 0;;) {
    if (i == h-1 && j == w-1) {
      break;
    }
    if (i == h-1) {
      if (a[i][j+1] == '#') {
        j++; continue;
      } else {
        pos = false; break;
      }
    }
    if (j == w-1) {
      if (a[i+1][j] == '#') {
        i++; continue;
      } else {
        pos = false; break;
      }
    }
    if (a[i+1][j] == a[i][j+1]) {
      pos = false; break;
    }
    if (a[i+1][j] == '#') {
      i++;
    }
    if (a[i][j+1] == '#') {
      j++;
    }
  }
  int sum = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') sum++;
    }
  }
  if (sum != h + w - 1) pos = false;
  if (pos) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
}
