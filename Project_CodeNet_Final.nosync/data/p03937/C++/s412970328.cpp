#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  int H,W; cin >> H>>W;
  string board[H];
  bool check[H][W];
  REP(i,H){
    cin>>board[i];
    REP(j,W){
      check[i][j] = true;
    }
  }
  REP(i,H){
    REP(j,W){
      char mas = board[i][j];
      if(mas=='#'){
        for(int k=i+1;k<H;k++){ for(int l=0;l<j;l++){
          check[k][l] = false;
        } }
      }
    }
  }
  bool r = true;
  REP(i,H){
    REP(j,W){
      if(check[i][j]==false){
        if(board[i][j]=='#'){
          r = false;
          break;
        }
      }
    }
    if(!r) break;
  }
  if(r){ cout << "Possible\n";}
  else{ cout << "Impossible\n";  }       
}