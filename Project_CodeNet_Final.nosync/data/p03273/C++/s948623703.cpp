#include <bits/stdc++.h>
using namespace std;

int main() {
  //入力
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> a.at(i).at(j);
    }
  }
  //判定i
  vector<int> counti(H);
  
  for(int i=0; i<H; i++){
    int count = 0;
    for(int j=0; j<W; j++){
      if(a.at(i).at(j) == '.'){
        count++;
      }
    }
    if(count == W){
      counti.at(i) = 1;
    }
  }
  //判定j
  vector<int> countj(W);
  for(int j=0; j<W; j++){
    int count = 0;
    for(int i=0; i<H; i++){
      if(a.at(i).at(j) == '.'){
        count++;
      }
    }
    if(count == H){
      countj.at(j) = 1;
    }
  }
  //出力
  for(int i=0; i<a.size(); i++){
    if(counti.at(i) == 0){
      for(int j=0; j<a.at(0).size(); j++){
        if(countj.at(j) == 0){
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}