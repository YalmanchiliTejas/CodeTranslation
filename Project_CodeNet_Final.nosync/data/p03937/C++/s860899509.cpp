#include "bits/stdc++.h"
#define rep(i,a,n) for(int i = (a);i <(n);i++)
using namespace std;

int main(){
  int n,m,x=0,y=0;
  char cell[10][10];
  cin >> n >> m;
  
  rep(i,0,10){
    rep(j,0,10){
      cell[i][j] = 'X';
    }
  }
  
  rep(i,0,n){
    rep(j,0,m){
      cin >> cell[i][j];
    }
  }
  
  while(1){
    if(cell[x+1][y] == '#'){
      cell[x][y] = '.';
      x++;
    }
    else if(cell[x][y+1] == '#'){
      cell[x][y] = '.';
      y++;
    }
    else{
      cell[n-1][m-1] = '.';
      break;
    }
  }
  
  rep(i,0,n){
    rep(j,0,m){
      if(cell[i][j] == '#'){
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  
  cout << "Possible" << endl;
  return 0;
  
}