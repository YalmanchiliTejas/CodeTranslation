#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> table(H,vector<char>(W,'.'));
  vector<vector<char>> reverse(W,vector<char>(H,'.'));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table.at(i).at(j);
    }
  }
  
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      reverse.at(i).at(j) = table.at(j).at(i);
    }
  }
  
  vector<char> row(W,'.');
  vector<char> col(H,'.');
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (table.at(i) != row && reverse.at(j) != col) {
      	cout << table.at(i).at(j);
      }
    }
    
    if (table.at(i) != row) {
      cout << endl;
    }
  }  
}
