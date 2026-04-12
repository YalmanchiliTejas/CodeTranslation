#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> basic(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++)
      cin >> basic.at(i).at(j);
  }
    
  for (int i = 0; i < H; i++) {
    bool flagH = false;
    for (int j = 0; j < W; j++) {
      if (basic.at(i).at(j) == '#')
        flagH = true;
    }
    if (flagH == true) {
      for (int j = 0; j < W; j++) {
        bool flagW = false;
        for (int k = 0; k < H; k++) {
          if (basic.at(k).at(j) == '#')
            flagW = true;
        }
        if (flagW  == true)
          cout << basic.at(i).at(j);
      }
      cout << endl;
    }
  }
}