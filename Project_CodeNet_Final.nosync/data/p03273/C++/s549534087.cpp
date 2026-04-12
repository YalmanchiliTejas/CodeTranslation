#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin>>H>>W;
  vector<vector<char>> table(H, vector<char>(W));
  vector<bool> deleted_row(H, true);
  vector<bool> deleted_col(W, true);
  for(int i=0;i<H;i++) {
    for(int j=0;j<W;j++){
      cin>>table.at(i).at(j);
      if(table.at(i).at(j)=='#'){
        deleted_row.at(i)=false;
        deleted_col.at(j)=false;
      }
    }
  }
  
  for(int i=0;i<H;i++){
    if(!deleted_row.at(i)){
      for(int j=0;j<W;j++){
        if(!deleted_col.at(j)){
          cout<<table.at(i).at(j);
        }
      }
      cout<<endl;
    }
  }
}