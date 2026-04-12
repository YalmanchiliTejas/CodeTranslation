#include<iostream>
#include<algorithm>
using namespace std;

char G[1000][1000];
int H, W;

int solve(){
  int mi = 1000000000;
  int ma = 0;
  for ( int i = 0; i < H; i++ ){
    for ( int j = 0; j < W; j++ ){
      if ( G[i][j] == '.' ) continue;
      mi = min(mi, i+j);
      ma = max(ma, i+j);
    }
  }
  return ma - mi;
}

void rev(){
  char t[1000];
  for ( int i = 0; i < H; i++ ){
    for ( int j = 0; j < W; j++ ) t[j] = G[i][j];
    for ( int j = 0; j < W; j++ ) G[i][j] = t[W-j-1];
  }
}

int main(){
  cin >> H >> W;
  pair<int, int> s, t, o;
  for ( int i = 0; i < H; i++ ){
    for ( int j = 0; j < W; j++ ){
      cin >> G[i][j];
    }
  }
  int ans = solve();
  rev();
  ans = max(ans, solve());
  cout << ans << endl;

}










