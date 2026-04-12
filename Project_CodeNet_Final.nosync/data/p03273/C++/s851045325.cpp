#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  char g[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> g[i][j];
    }
  }
  
  int r[H], c[W];
  for (int i = 0; i < H; i++) r[i] = 0;
  for (int j = 0; j < W; j++) c[j] = 0;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (g[i][j] == '#') { r[i] = 1; c[j] = 1; }
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (r[i]) {
      for(int j = 0; j < W; j++) {
        if (c[j]) cout << g[i][j];
      }
      cout << endl;
    }
  }

}