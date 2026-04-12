#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string wb = "";
  char A[H][W];
  
  int r[H];
  int c[W];
  
  for (int i = 0; i < H; i++) {
    r[i] = -1;
    for (int j = 0; j < W; j++) {
      c[j] = -1;
      char s;
      cin >> s;
      A[i][j] = s;
    }
  }
  
  for (int i = 0; i < H; i++) {
    int flag = 0;
    for (int j = 0; j < W; j++) {
      if (A[i][j] == '#') {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      r[i] = i;
    }
  }
  
  for (int j = 0; j < W; j++) {
    int flag = 0;
    for (int i = 0; i < H; i++) {
      if (A[i][j] == '#') {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      c[j] = j;
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(r[i] == i && c[j] == j)
        cout << A[i][j];
    }
    if (r[i] == i) cout << endl;
  }
}