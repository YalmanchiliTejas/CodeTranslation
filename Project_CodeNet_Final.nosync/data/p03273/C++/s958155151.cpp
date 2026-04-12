#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int H,W;
  cin >> H >> W;

  vector<string> data(H);
  for (int i = 0; i < H; i++) {
    cin >> data[i];
    bool flag = true;
    for (int j = 0; j < W; j++) {
      if (data[i][j] == '#') {
        flag = false;
      }
    }
    if (flag == true) {
      data[i][0] = '$';
    }
  }

  for (int i = 0; i < W; i++) {
    bool flg = true;
    for (int j = 0; j < H; j++) {
      if (data[j][i] == '#') {
        flg = false;
      }
    }
    if (flg == true) {
      for (int k = 0; k < H; k++) {
        if (data[k][i] != '$') data[k][i] = '%';
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (data[i][0] == '$') {
      continue;
    }
    for (int j = 0; j < W; j++) {
      if (data[i][j] == '%') continue;
      cout << data[i][j];
    }
    cout << endl;
  }
}
