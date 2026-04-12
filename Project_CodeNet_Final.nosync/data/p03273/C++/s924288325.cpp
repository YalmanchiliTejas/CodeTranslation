#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;
  char m[H][W];

  for (int h = 0; h < H; h++) {
    string a;
    cin >> a;
    if (a.find('#') != string::npos) {
      for (int w = 0; w < W; w++) {
        m[h][w] = a[w];
      }
    } else {
      for (int w = 0; w < W; w++) {
        m[h][w] = 'x';
      }
    }
  }

  for (int w = 0; w < W; w++) {
    int cnt = 0;
    for (int h = 0; h < H; h++) {
      if (m[h][w] == '.' || m[h][w] == 'x') {
        cnt++;
      }
    }

    if (cnt == H) {
      for (int h = 0; h < H; h++) {
        m[h][w] = 'x';
      }
    }
  }

  for (int h = 0; h < H; h++) {
    bool out = false;
    for (int w = 0; w < W; w++) {
      if (m[h][w] != 'x') {
        cout << m[h][w];
        out = true;
      }
    }
    if (out) cout << endl;
  }
  return 0;
}