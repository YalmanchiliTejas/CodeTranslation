#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll h, w;
  cin >> h >> w;
  vector<vc> g(h, vc(w, '#'));
  rep(i, h) rep(j, w) {
    char c;
    cin >> c;
    if(c == '.') g[i][j] = '.';
  }
  vb bh(h, false), bw(w, false);
  rep(i, h) {
    bool ok = true;
    rep(j, w) if(g[i][j] == '#') ok = false;
    bh[i] = ok;
  }
  rep(j, w) {
    bool ok = true;
    rep(i, h) if(g[i][j] == '#') ok = false;
    bw[j] = ok;
  }
  rep(i, h) {
    bool ok = false;
    rep(j, w) {
      if(!bh[i] && !bw[j]) {
        cout << g[i][j];
        ok = true;
      }
    }
    if(ok) cout << '\n';
  }
}