#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  char a[H][W];
  bool g[H], r[W];
  fill(g, g + H, false);
  fill(r, r + W, false);
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> a[i][j];
      if(a[i][j] == '#'){
        g[i] = true;
        r[j] = true;
      }
    }
  }
  for(int i = 0; i < H; i++){
    if(!g[i]) continue;

    for(int j = 0; j < W; j++){
      if(!r[j]) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
