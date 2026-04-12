#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int h, w;
char grid[200][200];

int main(){
  cin >> h >> w;
  rep(i, h){
    rep(j, w){ 
      cin >> grid[i][j];
    }
  }
  rep(i, h){
    bool flag = true;
    rep(j, w){
      if(grid[i][j] == '#'){
        flag = false;
        break;
      }
    }
    if(flag){
      for(int k = i; k < h; k++){
        rep(l, w){
          grid[k][l] = grid[k + 1][l];
          cerr << k <<" "<< l;
        }
      }
      i--; h--;
    }
  }
  rep(i, w){
    bool flag = true;
    rep(j, h){
      if(grid[j][i] == '#'){
        flag = false;
        break;
      }
    }
    if(flag){
      for(int k = i; k < w; k++){
        rep(l, h){
          grid[l][k] = grid[l][k + 1];
        }
      }
      i--; w--;
    }
  }
  rep(i, h){
    rep(j, w){
      cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}