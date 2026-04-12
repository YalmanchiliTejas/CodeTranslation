#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }

  vector<bool> latitude(W,0);
  vector<bool> longitude(H,0);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(data.at(i).at(j) == '.') {
        if(j == W - 1) longitude.at(i) = 1;
      }
      else break;
    }
  }
  
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if(data.at(i).at(j) == '.') {
        if(i == H - 1) latitude.at(j) = 1;
      }
      else break;
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (longitude.at(i) == 1);
    else {
      for (int j = 0; j < W; j++) {
        if (latitude.at(j) == 1);
        else cout << data.at(i).at(j);
      }
    cout << endl;
    }
  }
}