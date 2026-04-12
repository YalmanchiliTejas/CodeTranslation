#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i<(int)n; i++)
int main() {
  int H,W; //行、列
  cin >> H >> W;
  vector <int> hflag(H,0);
  vector <int> wflag(W,0);
  vector <vector <char>> field(H,vector <char> (W));
  //入力格納
  rep(i,H)rep(j,W) cin >> field.at(i).at(j);
  //探索
  rep(i,H){
    rep(j,W){
      if(field.at(i).at(j) == '.') {
        hflag.at(i)++;
        wflag.at(j)++;
      }
    }
  }
  //変換
  rep(i,field.size()){
    if(hflag.at(i)==W){
      rep(j,field.at(0).size()) field.at(i).at(j) = 'F';
    }
  }
  //変換２
  rep(j,field.at(0).size()){
    if(wflag.at(j)==H){
      rep(i,field.size()) field.at(i).at(j) = 'F';
    }
  }
  //表示
  rep(i,field.size()) {
    int fd = 0;
    rep(j,field.at(0).size()) {
      if(field.at(i).at(j) != 'F'){
        cout << field.at(i).at(j);
        fd = 1;
      }
    }
    if(fd != 1) continue;
    cout << endl;
  } 
}
