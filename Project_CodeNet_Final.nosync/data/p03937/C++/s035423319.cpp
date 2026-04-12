#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W; cin >> H >> W;
  vector<string> a(H);
  rep(i, H) cin >> a[i];

  int cnt = 0;
  rep(i, H) rep(j, W) {
    if(a[i][j] == '#') cnt++;
  }

  cout << (cnt == H+W-1 ? "Possible" : "Impossible") << '\n';
  return 0;
}
