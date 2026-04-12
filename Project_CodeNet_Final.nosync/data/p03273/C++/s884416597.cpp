#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  vector<bool> all_period_row(H, true);
  vector<bool> all_period_col(W, true);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++){
      if (A.at(i).at(j) == '#'){
        all_period_row.at(i) = false;
        all_period_col.at(j) = false;
      }
    }
  }
    
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++){
      if (!all_period_row.at(i) && !all_period_col.at(j)){
        cout << A.at(i).at(j);
      }
      if (!all_period_row.at(i)){
        if (j == W-1) cout << endl;
      }
    }
  }
    
          
  
}