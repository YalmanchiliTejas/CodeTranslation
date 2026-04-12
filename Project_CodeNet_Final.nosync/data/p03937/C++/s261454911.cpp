#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int H, W; cin >> H >> W;
  vector<string> a(H);
  rep(i, H) cin >> a[i];
  
  int i=0, j=0;
  a[i][j] = '.';
  while(!(i==H-1&&j==W-1)) {
    if(i < H-1 && a[i+1][j] == '#') {
      a[i+1][j] = '.';
      i++;
    } else if(j < W-1 && a[i][j+1] == '#') {
      a[i][j+1] = '.';
      j++;
    } else {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  rep(i, H) rep(j, W) if(a[i][j] == '#') {
    cout << "Impossible" << endl;
    return 0;
  }
  
  cout << "Possible" << endl;
}