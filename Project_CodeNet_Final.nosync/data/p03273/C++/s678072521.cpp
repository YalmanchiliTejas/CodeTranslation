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
  
  //H
  vector<bool> heightWhite(W, false);
  for (int i = 0; i < W; i++) {
    bool isAllWhite = true;
    for (int j = 0; j < H; j++) {
      if (data.at(j).at(i) == '#') {
        isAllWhite = false;
        break;
      }
    }
    
    if (isAllWhite)
      heightWhite.at(i) = isAllWhite;
  }
  
  //W
  vector<bool> widthWhite(H, false);
  for (int i = 0; i < H; i++) {
    bool isAllWhite = true;
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) == '#') {
        isAllWhite = false;
        break;
      }
    }
    
    if (isAllWhite)
      widthWhite.at(i) = isAllWhite;
  }
  
  for (int i = 0; i < H; i++) {
    if(!widthWhite.at(i)) {
      for (int j = 0; j < W; j++) {
        if (!heightWhite.at(j))
          cout << data.at(i).at(j);
      }
      cout << endl;
    }
  }
}