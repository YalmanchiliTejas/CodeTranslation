#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for (int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  vector<bool> row(H), col(W);
  bool flag_row=false, flag_col=false;
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      if (j==0 && a.at(i).at(j) == '.') flag_row = true;
      if (a.at(i).at(j) == '#') flag_row = false;
    }
    row.at(i) = flag_row;
    flag_row = false;
  }
  
  for (int i=0; i<W; i++){
    for (int j=0; j<H; j++){
      if (j==0 && a.at(j).at(i) == '.') flag_col = true;
      if (a.at(j).at(i) == '#') flag_col = false;
    }
    col.at(i) = flag_col;
    flag_col = false;
  }
  
  for (int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if (!(row.at(i) || col.at(j))){
        cout << a.at(i).at(j);
      }
    }
    if (!(row.at(i))) cout << endl;
  }
}