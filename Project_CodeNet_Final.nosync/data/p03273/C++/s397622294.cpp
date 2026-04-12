#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> table.at(i).at(j);
    }
  }
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (table.at(i).at(j) == '#'){
        break;
      }
      else if (j == W-1){
        for (int k = i+1; k < H; k++){
          table.at(k-1) = table.at(k);
        }
        table.pop_back();
        H--;
        i--;
      }
    }
  }
  for (int j = 0; j < W; j++){
    for (int i = 0; i < H; i++){
      if (table.at(i).at(j) == '#'){
        break;
      }
      else if (i == H-1){
        for (int l = 0; l < H; l++){
		  for (int k = j+1; k < W; k++){
          table.at(l).at(k-1) = table.at(l).at(k);
          }
        }
        for (int k = 0; k < H; k++){
          table.at(k).pop_back();
        }
        W--;
        j--;
      }
    }
  }
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cout << table.at(i).at(j);
      if (j == W-1){
        cout << endl;
      }
    }
  }
}
