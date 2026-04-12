#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  int H, W;
  cin >> H >> W;
  char a[H][W];
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }

  int h_skip[H];
  int w_skip[W];

  for(int i = 0; i < H; i++) {
    h_skip[i] = 1;
    for(int j = 0; j < W; j++) {
      if(a[i][j] == '#') {
        h_skip[i] = 0;
        break;
      }
    }
  }
  for(int j = 0; j < W; j++) {
    w_skip[j] = 1;
    for(int i = 0; i < H; i++) {
      if(a[i][j] == '#') {
        w_skip[j] = 0;
        break;
      }
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(h_skip[i] != 1 && w_skip[j] != 1) {
        cout << a[i][j];
      }
    }
    if(h_skip[i] != 1) cout << endl;
  }
  return 0;
}
