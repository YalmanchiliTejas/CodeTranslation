#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> figure(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> figure.at(i).at(j); 
    }
  }
  
  vector<bool> row(H, false);
  vector<bool> column(W, false);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (figure.at(i).at(j) == '#') {
        row.at(i) = true;    
        column.at(j) = true;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (row.at(i)) {
      for (int j = 0; j < W; j++) {
		if (column.at(j)) {
          cout << figure.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
  
}