#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  vector<int> hcount(H);
  vector<int> wcount(W);
  
  for(int i=0;i < H;i++){
    for(int j=0;j < W;j++){
      cin >> a.at(i).at(j);
    }
  }
  
  for(int i=0;i < H;i++){
    for(int j=0;j < W;j++){
      if (a.at(i).at(j) == '.'){
        hcount.at(i)++;
        wcount.at(j)++;
      }
    }
  }
  
  for(int i=0;i < H;i++){
    
    if (hcount.at(i) == W){
      continue;
    }
    for(int j=0;j < W;j++){
      if (wcount.at(j) == H){
        continue;
      }
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
}