#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> table.at(i).at(j);
    }
  }
  vector<bool> row(H,false),col(W,false);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(table.at(i).at(j)=='#'){
        break;
      }
      else if(j==W-1){
        row.at(i)=true;
      }
    }
  }
  for(int j=0;j<W;j++){
    for(int i=0;i<H;i++){
      if(table.at(i).at(j)=='#'){
        break;
      }
      else if(i==H-1){
        col.at(j)=true;
      }
    }
  }
  for(int i=0;i<H;i++){
    if(row.at(i)==true){
      continue;
    }
    for(int j=0;j<W;j++){
      if(col.at(j)==true){
        continue;
      }
      cout << table.at(i).at(j);
    }
    cout << endl;
  }
}
