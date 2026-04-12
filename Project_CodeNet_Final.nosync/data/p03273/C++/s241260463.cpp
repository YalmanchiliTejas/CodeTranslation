#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;

  vector<string> a(H);
  for(int i = 0; i < H; i++){
    cin >> a[i];
  }

  vector<bool> row(H, false); // row: 行
  vector<bool> column(W, false); // colimn: 列
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(a[i][j] == '#'){
        row[i] = true;
        column[j] = true;
      }
    }
  }

  int flag = 0;
  for(int i = 0; i < H; i++){
    flag = 0;
    for(int j = 0; j < W; j++){
      if(row[i] && column[j]){
        cout << a[i][j];
        flag = 1;
      }
    }
    if(flag){
      cout << endl;
    }
  }

  return 0;

}