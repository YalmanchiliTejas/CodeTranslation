#include<bits/stdc++.h>
using namespace std;

bool Rblank(vector<vector<char>> &grid, int row, int weigh){
  for(int i=0; i<weigh; i++){
    if(grid.at(row).at(i) == '#'){
      return false;
    }
  }
  return true;
}

bool Cblank(vector<vector<char>> &grid, int column, int high){
  for(int i=0; i<high; i++){
    if(grid.at(i).at(column) == '#'){
      return false;
    }
  }
  return true;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> a.at(i).at(j); 
    }
  }
  
  int Rzip = 0;
  int Czip = 0;
  
  for(int i=0; i<H; i++){
    if(Rblank(a, i, W)){
      for(int j=i; j>0; j--){
        a.at(j) = a.at(j - 1);
      }
      Rzip++;
    }
  }    
  
  for(int i=0; i<W; i++){
    if(Cblank(a, i, H)){
      for(int j=0; j<H; j++){
        for(int k=i; k>0; k--){
          a.at(j).at(k) = a.at(j).at(k - 1);
        }
      }
      Czip++;
    }  
  }


  vector<string> ans(H - Rzip);
  for(int i=Rzip; i<H; i++){
    for(int j=Czip; j<W; j++){
      ans.at(i - Rzip) += a.at(i).at(j);
    }
  }

  for(string L : ans){
    cout << L << endl;
  }
}