#include <iostream>
#include <vector>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> table.at(i).at(j);
    }
  }
  vector<bool> row(H,false);
  vector<bool> column(W,false);
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(table.at(i).at(j)=='#'){
        row.at(i)=true;
        column.at(j)=true;
      }
    }
  }
  for(int i=0; i<H; i++){
    if(row.at(i)){
      for(int j=0; j<W; j++){
        if(column.at(j)){
          cout << table.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
  return 0;
}