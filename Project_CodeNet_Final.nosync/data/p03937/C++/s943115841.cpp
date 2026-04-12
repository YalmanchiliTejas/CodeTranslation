#include<bits/stdc++.h>
using namespace std;
int main(){
  int h, w;
  cin >> h >> w;
  vector<string> t(h);
  for(int i = 0; i < h; ++i) cin >> t[i];
  int H = 0, W = 0;
  bool flag = true;
  int all = 0;
  int passed = 1;
  for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) if(t[i][j] == '#') all++;
  while(H != h - 1 || W != w - 1){
    if(W + 1 <= w - 1 && H + 1 <= h - 1){
      if(t[H + 1][W] == '#' && t[H][W + 1] == '#'){
        flag = false;
        break;
      }
    }
    if(W + 1 <= w - 1){
      if(t[H][W + 1] == '#'){
        ++W;
        passed++;
        continue;
      }
    }
    if(H + 1 <= h - 1){
      if(t[H + 1][W] == '#'){
        ++H;
        passed++;
        continue;
      }
    }
    flag = false;
    break;
  }
  if(flag && all == passed) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}