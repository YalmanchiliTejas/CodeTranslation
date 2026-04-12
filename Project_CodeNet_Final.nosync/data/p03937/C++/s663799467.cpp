#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<char>> board(h,vector<char>(w));
  int cnt=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>board[i][j];
      if(board[i][j]=='#')cnt++;
    }
  }
  if(cnt==h+w-1){
    cout<<"Possible"<<endl;
  }else{
    cout<<"Impossible"<<endl;
  }
  return 0;
}