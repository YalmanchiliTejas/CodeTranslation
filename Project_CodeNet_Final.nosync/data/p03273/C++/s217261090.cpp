#include <bits/stdc++.h>
#include <string>
using namespace std;



int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> data.at(i).at(j);
    }
  }
  
  vector<bool> row(H, false);
  vector<bool> col(W, false);
  
  for (int h = 0; h < H; ++h) {
    for (int w = 0; w < W; ++w) {
      if (data.at(h).at(w) == '#') {
        row.at(h) = true;
        col.at(w) = true;
      }
    }
  }
  for (int h = 0; h < H; ++h) {
    if(row.at(h)) {
      for (int w = 0; w < W; ++w) {
        if (col.at(w)) {
          cout << data.at(h).at(w);
        }
      }
      cout << endl;
    }
  }
}
