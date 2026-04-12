#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int H, W, i, j;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  vector<int> wc(H, 0), hc(W, 0);
  
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      cin >> a[i][j];
    }
  }
  
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      if(a[i][j] == '#') wc[i] = 1;
    }
  }
  
  for(i=0; i<W; i++){
    for(j=0; j<H; j++){
      if(a[j][i] == '#') hc[i] = 1;
    }
  }
  
  for(i=0; i<H; i++){
    bool flag = false;
    for(j=0; j<W; j++){
      if(wc[i] == 1 && hc[j] == 1){
        cout << a[i][j];
        flag = true;
      }
    }
    if(flag) cout << endl;
  }
  return 0;
}