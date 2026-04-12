#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<vc> g(h + 2, vc(w + 2));
  rep2(i, 1, h + 1) rep2(j, 1, w + 1) cin >> g[i][j];
  vb hc(h + 2, false), wc(w + 2, false);
  rep2(i, 1, h + 1) {
    bool ok = true;
    rep2(j, 1, w + 1) if(g[i][j] == '#') ok = false;
    hc[i] = ok;
  }
  rep2(j, 1, w + 1) {
    bool ok = true;
    rep2(i, 1, h + 1) if(g[i][j] == '#') ok = false;
    wc[j] = ok;
  }
  rep2(i, 1, h + 1) {
    bool ok = false;
    rep2(j, 1, w + 1) {
      if(!hc[i] && !wc[j]) {
        cout << g[i][j];
        ok = true;
      }
    }
    if(ok) cout << endl;
  }
}