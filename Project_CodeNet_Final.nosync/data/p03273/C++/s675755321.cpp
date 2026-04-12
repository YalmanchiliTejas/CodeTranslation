#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table.at(i).at(j);
    }
  }
  
  
  for (int i = 0; i < H; i++) {
    bool is_all_dot = false;
    for (int j = 0; j < W; j++) {
      if (table.at(i).at(j) == '#') {
        break;
      }
      if (j == W - 1) {
        is_all_dot = true;
      }
    }
    if (is_all_dot) {
      table.erase(table.begin() + i);
      i--;
      H--;
    }
  }
  
    
  for (int i = 0; i < W; i++) {
    bool is_all_dot = false;
    for (int j = 0; j < H; j++) {
      if (table.at(j).at(i) == '#') {
        break;
      }
      if (j == H - 1) {
        is_all_dot = true;
      }
    }
    if (is_all_dot) {
      for (int j = 0; j < H; j++) {
        table.at(j).erase(table.at(j).begin() + i);
      }
      i--;
      W--;
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << table.at(i).at(j);
      if (j == W - 1) {
        cout << endl;
      }
    }
  }

  
}
