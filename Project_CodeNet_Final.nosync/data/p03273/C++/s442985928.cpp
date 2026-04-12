#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w; cin >> h >> w;
  vector<string> g(h);
  vector<bool> ish(h), isw(w);
  rep(i,h) cin >> g.at(i);
  rep(i,h) {
    int cnt = 0;
    rep(j,w) {
      if (g.at(i).at(j) == '.') cnt++;
    }
    if (cnt == w) ish.at(i) = true;
  }
  rep(i,w) {
    int cnt = 0;
    rep(j,h) {
      if (g.at(j).at(i) == '.') cnt++;
    }
    if (cnt == h) isw.at(i) = true;
  }

  rep(i,h) {
    if (ish.at(i)) continue;
    rep(j,w) {
      if (isw.at(j)) continue;
      cout << g.at(i).at(j);
    }
    cout << endl;
  }
  return 0;
}