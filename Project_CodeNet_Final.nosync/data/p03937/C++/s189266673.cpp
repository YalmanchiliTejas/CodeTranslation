#include <iostream>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int H, W; in(H); in(W);

  char A[H][W];
  rep(i, H) rep(j, W) {
    in(A[i][j]);
  }
  rep(i, H) rep(j, W) {
    if (i+1 < H && A[i+1][j] == '#' && j+1 < W && A[i][j+1] == '#') {
      out("Impossible");
      return 0;
    }
  }
  out("Possible");

  return 0;
}
