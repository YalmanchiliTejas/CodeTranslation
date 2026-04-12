#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  string moji[101];
  
  for (int i = 0; i < h; i++) {
    cin >> moji[i];
  }
  
  bool hy[101] = {0};
  bool hx[101] = {0};
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (moji[i][j] == '#') {
        hy[i] = true;
        hx[j] = true;
      }
    }
  }
  
  for (int i = 0; i < h; i++) {
    if (hy[i]) {
      for (int j = 0; j < w; j++) {
        if (hx[j]) {
          cout << moji[i][j];
        }
      }
      cout << endl;
    }
  }
}