#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> table(H,vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table.at(i).at(j);
    }
  }
  
  vector<vector<char>> table2(0,vector<char>(W));
  int Hnew = H;
  
  for (int i = 0; i < H; i++) {
    bool keep = false;
    for (int j = 0; j < W; j++) {
      if (table.at(i).at(j) == '#') {
        keep = true;
        break;
      }
      if (j == W-1) {
        Hnew--;
      }
    }
    if (keep) {
      table2.push_back(table.at(i));
    }
  }
  
  vector<vector<char>> table3(Hnew);
  int Wnew = W;
  
  for (int j = 0; j < W; j++) {
    bool keep = false;
    for(int i = 0; i < Hnew; i++) {
      if (table2.at(i).at(j) == '#') {
        keep = true;
        break;
      }
      if (i == Hnew-1) {
        Wnew--;
      }
    }
    if (keep) {
      for (int i = 0; i < Hnew; i++) {
        table3.at(i).push_back(table2.at(i).at(j));
      }
    }
  }
  
  for (int i = 0; i < Hnew; i++) {
    for (int j = 0; j < Wnew; j++) {
      cout << table3.at(i).at(j);
    }
    cout << endl;
  }
}