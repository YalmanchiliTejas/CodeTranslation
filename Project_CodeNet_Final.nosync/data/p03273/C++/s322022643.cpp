#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> v(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> v.at(i).at(j);
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c = v.at(i).at(j);
      if ((c == '.') || (c == 'x')) {
        if (!j) {
          int cnt = 1;
          for (int k = 1; k < W; k++) {
            if (v.at(i).at(k) == '.') cnt++;
            if (v.at(i).at(k) == 'x') cnt++;
          }
          if (cnt == W) {
            for (int k = 0; k < W; k++) {
              v.at(i).at(k) = 'x';
            }
          }
        }
        
        int cnt = 0;
        for (int k = 0; k < H; k++) {
          if (v.at(k).at(j) == '.') cnt++;
          if (v.at(k).at(j) == 'x') cnt++;
        }
        if (cnt == H) {
          for (int k = 0; k < H; k++) {
            v.at(k).at(j) = 'x';
          }
        }
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c = v.at(i).at(j);
      if (c != 'x') {
        cout << c;
      }
    }
    
    int f = 0;
    for (int j = 0; j < W; j++) {
      if (v.at(i).at(j) != 'x') f = 1;
    }
    if (f) cout << endl;
  }
}