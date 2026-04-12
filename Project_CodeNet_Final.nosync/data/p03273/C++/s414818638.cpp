#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> table(H,vector<char>(W,'.'));
  vector<bool> row(H,false);
  vector<bool> col(W,false);
  for (int i = 0; i < H; i++) {
    for(int j=0;j<W;j++){
      cin >> table[i][j];
    }
  }
  for (int i = 0; i < H; i++) {
    for(int j=0;j<W;j++){
      if(table[i][j]=='#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }
  
  for(int i=0;i<H;i++){
    if(row[i]){
      for(int j=0;j<W;j++){
        if(col[j]){
          cout << table[i][j];
        }
      }
      cout << endl;
    }
  }
}
