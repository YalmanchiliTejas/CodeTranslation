#include <bits/stdc++.h>
using namespace std;

int main(){
  int row, col;
  cin >> row >> col;
  bool del = true; 
  
  vector<vector<char>> grid(row, vector<char>(col));
  
  for (int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cin >> grid.at(i).at(j);
      if(grid.at(i).at(j) == '#') del = false;
    }
    if(del){
      i--;
      row--;
    }
  del = true;
  }
  
  for(int j = 0; j < col; j++) {
    for(int i = 0; i < row; i++) {
      if(grid.at(i).at(j) == '#') del = false;
    }
    if(del){
      for(int k = j; k < col; k++){
        for(int l = 0; l < row; l++) {
          if(k == col - 1) grid.at(l).at(k) = '\0';
          else grid.at(l).at(k) = grid.at(l).at(k+1);
        }
      }
      j--;
      col--;
    }
    del = true;
  }
  
      
  for (int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cout << grid.at(i).at(j);
    }
    cout << endl;
  }
}