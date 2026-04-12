#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  int cnt = 0;
  rep(i, h) rep(j, w) if (a[i][j] == '#') ++cnt;
  if (cnt == h + w - 1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}