#include <bits/stdc++.h>
using namespace std;
int main(){
  /*行と列を設定する*/
  int H,W;
  cin>>H>>W;
  /*マスを設定し、入力*/
  vector<vector<char>> board(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>board.at(i).at(j);
    }
  }
  /*少なくとも一個黒いマスがあれば、その行と列は消去しない*/
  vector<bool> row(H,false);
  vector<bool> column(W,false);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(board.at(i).at(j)=='#'){
        row.at(i)=true;
        column.at(j)=true;
      }
    }
  }
  /*見ているのが消去しない(少なくとも一個黒いマスがある)行と列であれば順番に出力*/
  for(int i=0;i<H;i++){
    if(row.at(i)){
      for(int j=0;j<W;j++){
        if(column.at(j)){
          cout<<board.at(i).at(j);
        }
      }
      cout<<endl;/*全ての列が終わったら改行*/
    }
  }
  return 0;
}