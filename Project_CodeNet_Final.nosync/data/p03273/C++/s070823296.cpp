#include <bits/stdc++.h>
using namespace std;
  
int main(){
  int h, w;
  cin >> h >> w;
  string grid[h];
  vector<bool> t(h, false);
  vector<bool> y(w, false);
  for(int i = 0; i < h; i++) cin >> grid[i];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(grid[i][j] == '#'){
        t[i] = true; y[j] = true;
      }
    }
  }
  for(int i = 0; i < h; i++){
    if(!t[i]) continue;
    for(int j = 0; j < w; j++){
      if(y[j]) cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}