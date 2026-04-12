#include <bits/stdc++.h>
using namespace std;

void remove_row(vector<vector<char>> &table, int row){
  int height = table.size();
  for (int i=row;i<height-1;i++) {
    table.at(i) = table.at(i+1);
  }
  table.pop_back();
  
  return;
}

void remove_col(vector<vector<char>> &table, int col){
  int height = table.size();
  int width = table.at(0).size();
  
  for (int i=0;i<height;i++) {
    for (int j=col;j<width-1;j++) {
      table.at(i).at(j) = table.at(i).at(j+1);
    }
    table.at(i).pop_back();
  }
  
  return;
}

int main() {
  int H, W;
  cin >> H >> W;
 
  vector<vector<char>> grid(H,vector<char>(W));
  
  for (int row=0;row<H;row++) {
    for (int col=0;col<W;col++) {
      cin >> grid.at(row).at(col);
    }
  }
  
  int num_black = 0;
  
    
  //行のチェック
  for (int row=0;row<grid.size();row++) {
    num_black = 0;
    for (int col=0;col<grid.at(0).size();col++) {
      if (grid.at(row).at(col) == '#') {
        num_black++;
      }
    }
    
    if (num_black == 0) {
      remove_row(grid, row);
      row--;
    }
  }
  
   //列のチェック
  for (int col=0;col<grid.at(0).size();col++) {
    num_black = 0;
    for (int row=0;row<grid.size();row++) {
      if (grid.at(row).at(col) == '#') {
        num_black++;
      }
    }
    
    if (num_black == 0) {
      remove_col(grid, col);
      col--;
    }
  }
  
  // 出力
  H = grid.size();
  W = grid.at(0).size();  
  for (int row=0;row<H;row++) {
    for (int col=0;col<W;col++) {
      cout << grid.at(row).at(col);
      
      if (col == W-1){
        cout << endl;
      } 
    }
  }
  
  
}
