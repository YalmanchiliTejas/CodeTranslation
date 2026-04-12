#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int64_t i = 0; i < n; ++i)
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> v(H);
  vector<vector<char>> a(H, vector<char>(W));
  vector<bool> h(H), w(W);
  rep(i, H) cin >> v[i];
  rep(i, H){
    rep(j, W) a[i][j] = v[i][j];
  }
  rep(i, H){
    bool b = 1;
    rep(j, W){
      if(a[i][j] == '#'){
        b = 0;
        break;
      }
    }
    if(b) h[i] = 0;
    else h[i] = 1;
  }
  rep(i, W){
    bool b = 1;
    rep(j, H){
      if(a[j][i] == '#'){
        b = 0;
        break;
      }
    }
    if(b) w[i] = 0;
    else w[i] = 1;
  }
  rep(i, H){
    if(h[i]){
      rep(j, W) if(w[j]) cout << a[i][j];
      cout << endl;
    }
  }
  return 0;
}