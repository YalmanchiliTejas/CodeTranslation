#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  char a;
  cin >> H >> W;
  vector<int> height(H);
  vector<int> width(W);
  vector<vector<char>> table(H, vector<char>(W));
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> table.at(i).at(j); 
    }
  }

  for(int i = 0; i < H * W; i++){
    if(table.at(i / W).at(i % W) == '#' && width.at(i % W) == 0){
      width.at(i % W) = 1;
    }
    if(table.at(i / W).at(i % W) == '#' && height.at(i / W) == 0){
      height.at(i / W) = 1;
    }
  }
  
  for(int i = 0; i < H; i++){
    if (height.at(i) == 0) continue;
    for(int j = 0; j < W; j++){
      if (width.at(j) == 0) continue;
      cout << table.at(i).at(j); 
    }
    cout << endl;
  }

}
