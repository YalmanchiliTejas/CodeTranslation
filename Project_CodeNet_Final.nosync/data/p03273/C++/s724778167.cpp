#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto&& u : s) cin >> u;
  vector<bool> bh(h, false), bw(w, false);
  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') {
      bh[i] = true;
      bw[j] = true;
    }
  }
  vector<string> ans;
  rep(i, h) {
    if (bh[i] == false) continue;
    string s0 = "";
    rep(j, w) {
      if (bw[j] == true) s0.push_back(s[i][j]);
    }
    ans.push_back(s0);
  }
  for (auto&& u : ans) cout << u << endl;
}