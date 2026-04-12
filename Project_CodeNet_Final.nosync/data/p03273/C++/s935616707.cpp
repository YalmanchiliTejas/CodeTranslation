#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> M(H, vector<char>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> M.at(i).at(j);
    }
  }
  vector<int> s(H,0);
  for (int i = 0; i < H; i++) {
    bool flag=false;
    for (int j = 0; j < W-1; j++) {
      if(M.at(i).at(j)=='.'&&M.at(i).at(j+1)=='.') flag=true;
      else{
        flag=false;
        break;
      }
    }
    if(flag) s.at(i)=1;
  }

  vector<int> t(W,0);
  for (int i = 0; i < W; i++) {
    bool flag=false;
    for (int j = 0; j < H-1; j++) {
      if(M.at(j).at(i)=='.'&&M.at(j+1).at(i)=='.') flag=true;
      else{
        flag=false;
        break;
      }
    }
    if(flag) t.at(i)=1;
  }

  for (int i = 0; i < H; i++) {
    if(s.at(i)==0){
      for (int j = 0; j < W; j++) {
        if(t.at(j)==0) cout << M.at(i).at(j);
      }
      cout << endl;
    }
  }
}
