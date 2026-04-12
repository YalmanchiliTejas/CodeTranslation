#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  for(int i = 0; i<H; i++){
    for(int j = 0; j<W; j++){
      cin >> a.at(i).at(j);
    }
  }
  vector<bool> row(H,false);
  vector<bool> lin(W,false);
  for(int i = 0; i<H; i++){
    for(int j = 0; j<W; j++){
      if(a.at(i).at(j) == '#'){
        row.at(i) = true;
        lin.at(j) = true;
      }
    }
  }
  for(int i = 0;i<H;i++){
    if(row.at(i)){
      for(int j = 0; j<W;j++){
        if(lin.at(j)){
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }

}