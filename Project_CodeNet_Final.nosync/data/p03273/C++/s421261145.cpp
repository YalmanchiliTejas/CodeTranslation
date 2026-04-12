#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<bool>> ma(H,vector<bool>(W,false));
  char a;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> a;
      if (a == '#') {
        ma[i][j] = true;
      }
    }
  }
  vector<bool> tfH(H,false);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (ma[i][j]) {
        tfH[i] = true;
        break;
      }
    }
  }
  vector<bool> tfW(W,false);
  for (int i=0; i<W; i++) {
    for (int j=0; j<H; j++) {
      if (ma[j][i]) {
        tfW[i] = true;
        break;
      }
    }
  }
  for (int i=0; i<H; i++) {
    if (tfH[i] == false) {
      continue;
    }
    for (int j=0; j<W; j++) {
      if (tfW[j] == false) {
        continue;
      }
      if (ma[i][j]) {
        cout << '#';
      }
      else {
        cout << '.';
      }
    }
    cout << endl;
  }
}