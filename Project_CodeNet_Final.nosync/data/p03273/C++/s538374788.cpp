#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> image(H, vector<char>(W));
  
  string white_row = ".";
  for (int i = 0; i < W - 1; i++) {
    white_row += ".";
  }
  
  int count = 0;
  for (int i = 0; i < H; i++) {
    string row;
    cin >> row;
    
    if (row != white_row) {
      for (int j = 0; j < W; j++) {
        image.at(count).at(j) = row.at(j);
      }
      count++;
    }
  }
  
  vector<bool> erase_w(W, false);
  
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < count; j++) {
      if (image.at(j).at(i) != '.')
        break;
      if (j != count - 1)
        continue;
      erase_w.at(i) = true;
    }
  }
  
  
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < W; j++) {
      if (erase_w.at(j) == false){
        cout << image.at(i).at(j);
      }
    }
    cout << endl;
  } 
}