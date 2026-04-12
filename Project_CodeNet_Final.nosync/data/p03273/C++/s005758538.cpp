#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  int i,j;
  int judge;
  cin >> H >> W;
  vector<vector<char>> grid(H,vector<char>(W));
  vector<bool> height(H);
  vector<bool> wide(W);
  for(i=0;i<H;++i){
    for(j=0;j<W;++j){
      cin >> grid.at(i).at(j);
    }
  }

  for(i=0;i<H;++i){
    judge = 0;
    for(j=0;j<W;++j){
      if(grid.at(i).at(j) == '.')
        judge += 1;
    }
    if(judge != W){
      height.at(i) = true;
    }else{
      height.at(i) = false;
    }
}

for(i=0;i<W;++i){
  judge = 0;
  for(j=0;j<H;++j){
    if(grid.at(j).at(i) == '.')
      judge += 1;
  }
  if(judge != H){
    wide.at(i) = true;
  }else{
    wide.at(i) = false;
  }

}

for(i=0;i<H;++i){
  if(height.at(i)){
    for(j=0;j<W;++j){
      if(wide.at(j)){
        cout << grid.at(i).at(j);
      }
    }
    cout << endl;
  }
}

}