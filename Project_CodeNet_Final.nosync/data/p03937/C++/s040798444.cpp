#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int h, w, s = 1;
  cin >> h >> w;
  vector<string> v(h);
  rep(i, h) cin >> v[i];
  rep(i, h){
    rep(j, w) if(v[i][j] == '#') ++s;
  }
  if(s == h + w) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}