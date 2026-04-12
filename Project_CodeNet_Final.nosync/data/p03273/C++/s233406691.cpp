#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>>table(H,vector<char>(W));

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> table.at(i).at(j);
    }
  }
  
  vector<bool> x(H,false);
  vector<bool> y(W,false);
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(table.at(i).at(j)=='#'){
        x[i]=true;
        y[j]=true;
      }
    }
  }
  for(int i=0;i<H;i++){
    if(x[i]){
      for(int j=0;j<W;j++){
        if(y[j]){
          cout << table.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}

