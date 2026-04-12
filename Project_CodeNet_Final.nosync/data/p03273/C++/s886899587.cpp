#include <bits/stdc++.h>
using namespace std;

int main() {

  int H, W;
  cin >> H >> W;

  vector<vector<char>> table(H,vector<char>(W));
  vector<bool> x(W,false);
  bool isblack = false;

  for (int i = 0; i < H; i++){
    isblack = false;
    for(int j = 0; j < W; j++){
      cin >> table.at(i).at(j);
      //yokocheck
      if (table.at(i).at(j) == '#'){
        isblack = true;
        x.at(j) = true;
      }
    }
    if (isblack == false){
      H--;
      i--;
    }
  }

  for (int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if (x.at(j) == true){
        cout << table.at(i).at(j);
      }
      if (j == W-1) {
        cout << endl;
      }
    }
  }
//
}
