#include <iostream>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  char a[h][w];
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(a[i][j] == '#') {
        break;
      } else if(j == w - 1) {
        for(int k = 0; k < w; k++) {
          a[i][k] = '!';
        }
      }
    }
  }
  for(int i = 0; i < w; i++) {
    for(int j = 0; j < h; j++) {
      if(a[j][i] == '#') {
        break;
      } else if(j == h - 1) {
        for(int k = 0; k < h; k++) {
          a[k][i] = '!';
        }
      }
    }
  }
  int count = 0;
  for(int i = 0; i < h; i++) {
    count = 0;
    for(int j = 0; j < w; j++) {
      if(a[i][j] != '!') {
        cout << a[i][j];
      } else {
        count++;
      }
    }
    if(count != w && i != h - 1) {
      cout << "\n";
    }
  }
}