#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a[i];
  vector<vector<bool>> d(h, vector<bool>(w, true));
  for (int i = 0; i < h; i++) {
    bool ok = true;
    for (int j = 0; j < w; j++) if (a[i][j] == '#') ok = false;
    if (ok) {
      for (int j = 0; j < w; j++) d[i][j] = false; 
    }
  }

  for (int j = 0; j < w; j++) {
    bool ok = true;
    for (int i = 0; i < h; i++) if (a[i][j] == '#') ok = false;
    if (ok) {
      for (int i = 0; i < h; i++) d[i][j] = false;
    }
  }
  vector<string> res;
  for (int i = 0; i < h; i++) {
    string tmp = "";
    for (int j = 0; j < w; j++) if (d[i][j]) tmp += a[i][j];
    if (tmp.size() > 0) res.emplace_back(tmp);
  }
  for (auto e : res) cout << e << endl;
  return 0;
} 