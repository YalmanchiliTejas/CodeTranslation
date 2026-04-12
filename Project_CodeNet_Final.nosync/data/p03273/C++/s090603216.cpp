#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  rep(i,h) cin >> v[i];
  map<int, int> mph;
  map<int, int> mpw;
  string bh = "", bw = "";
  rep(i,h) bh += ".";
  rep(i,w) bw += ".";
  rep(i,h) {
    if (v[i] == bw) mph[i]++;
  }
  rep(j,w) {
    string t = "";
    rep(i,h) {
      t += v[i][j];
    }
    if (t == bh) mpw[j]++;
  }
  rep(i,h) {
    if (mph[i]) continue;
    rep(j,w) {
      if (mpw[j]) continue;
      cout << v[i][j];
    }
    cout << endl;
  }
}

int main() {
  solve();
  return 0;
}