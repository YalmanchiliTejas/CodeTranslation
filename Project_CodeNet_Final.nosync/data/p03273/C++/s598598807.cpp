#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> vec(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    int count = 0;
    for (int j = 0; j < W; j++) {
      cin >> vec.at(i).at(j);
      if (vec.at(i).at(j) == '.') {
        count++;
      }
    }
    if (count == W) {
      vec.at(i).at(0) = 'D';
    }
  }
  
  for (int i = 0; i < W; i++) {
    int count = 0;
    for (int j = 0; j < H; j++) {
      if (vec.at(j).at(i) == '.' || vec.at(j).at(i) == 'D') {
        count++;
      }
    }
    if (count == H) {
      for (int j = 0; j < H; j++) {
        if (vec.at(j).at(i) == '.') {
          vec.at(j).at(i) = 'N';
        }
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (vec.at(i).at(0) != 'D') {
      for (int j = 0; j < W; j++) {
        if (vec.at(i).at(j) != 'N') {
          cout << vec.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
