#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int H,W;
  cin >> H>>W;
  vector<vector<char>> data(H, vector<char>(W));
  rep(i,H) {
    rep(j,W) {
      cin >> data.at(i).at(j);
    }
  }
 
  vector<bool> h(H);
  for (int i = 0; i < H; i++) {
    h.at(i)=false;
    for (int j = 0; j < W; j++) {
      if(data.at(i).at(j)=='#'){
        h.at(i)=true;
      }
    }
  }
  vector<bool> w(W);
  for (int i = 0; i < W; i++) {
    w.at(i)=false;
    for (int j = 0; j < H; j++) {
      if(data.at(j).at(i)=='#'){
        w.at(i)=true;
      }
    }
  }
  
  rep(i,H){
    if(h.at(i)){
      rep(j,W){
        if(w.at(j)){
          cout<<data.at(i).at(j);
        }
      }
      cout<<endl;
    }
  }
  
}