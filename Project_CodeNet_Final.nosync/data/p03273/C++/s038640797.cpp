#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> map(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> map.at(i).at(j);
    }
  }
  vector<int> delW(W);
  vector<int> delH(H);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (map.at(i).at(j) == '#') break;
      if (j == W - 1) delH.at(i)++;
    }
  }
  
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (map.at(j).at(i) == '#') break;
      if (j == H - 1) delW.at(i)++;
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (delH.at(i) == 1) continue; 
    for (int j = 0; j < W; j++) {
      if (delW.at(j) == 0) cout << map.at(i).at(j);
      if (j == W - 1) cout << endl;
    }
  }
}

