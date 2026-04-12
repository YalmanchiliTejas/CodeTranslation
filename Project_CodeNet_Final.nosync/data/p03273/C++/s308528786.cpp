#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> table(H, vector<char>(W));
  
  for (int h = 0; h < H; h++) {
    for(int w = 0; w < W; w++) {
      cin >> table.at(h).at(w);
    }
  }
  
  vector<int> del_line;
  vector<int> del_row;
  
  for (int h = 0; h < H; h++) {
    bool flag = false;
    for(int w = 0; w < W; w++) {
      if(table.at(h).at(w) == '#'){
        flag = true;
        break;
      }
    }
    if(flag == false) del_line.push_back(h);
  }
  
  for (int w = 0; w < W; w++) {
    bool flag = false;
    for(int h = 0; h < H; h++) {
      if(table.at(h).at(w) == '#'){
        flag = true;
        break;
      }
    }
    if(flag == false) del_row.push_back(w);
  }
  
  for (int h = 0; h < H; h++) {
    bool flag = false;
    for (int i : del_line) {
      if (h == i) {
        flag = true;
        break;
      }
    }
    if(flag == true) continue;
    
    for(int w = 0; w < W; w++) {
      flag = false;
      for (int j : del_row) {
        if (w == j) {
          flag = true;
          break;
        }
      }
      if (flag == true) continue;
      cout << table.at(h).at(w);
    }
    cout << endl;
  }
}
