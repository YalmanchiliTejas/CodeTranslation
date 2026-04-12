#include <bits/stdc++.h>
using namespace std;

int main() {
  int col,row,col_,row_;
  col_ = 0;
  row_ = 0;
  cin >> col >> row;
  vector<vector<char>> map(col,vector<char>(row));
  vector<bool> col_e(col,false);
  vector<bool> row_e(row,false);
  
  //cout << col_ << endl;
  
  for(int i = 0; i < col; i++){
    for(int j = 0; j < row; j++){
      cin >> map.at(i).at(j);
      if(map.at(i).at(j) == '#')
        col_e.at(i) = true;
      //cout << map.at(i).at(j);
    }
    if(col_e.at(i)){
      col_++;
    }
    //cout << endl;
  }
  
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      if(map.at(j).at(i) == '#')
        row_e.at(i) = true;
    }
    if(row_e.at(i)){
      row_++;
    }
    //cout << row_e.at(i);
  }
  //cout << "col_" << col_ << " row_" << row_ << endl;
  for(int i = 0; i < col; i++){
    for(int j = 0; j < row; j++){
      //cout << col_e.at(i) << row_e.at(j) << ':' << map.at(i).at(j) << ' ';
      if(col_e.at(i) == 1 && row_e.at(j) == 1)
        cout << map.at(i).at(j);
    }
    if(col_e.at(i))
      cout << endl;
  }
                            
}