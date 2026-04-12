#include <bits/stdc++.h>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  char a[H][W];
  bool row[H] = {0};
  bool col[W] = {0};
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> a[i][j];
      if(a[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(row[i] && col[j]){
        cout << a[i][j];
      }
      if(j == W-1 && row[i] != 0){
        cout << endl;
      }
    }
  }
}