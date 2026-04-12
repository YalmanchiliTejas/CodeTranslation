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
vi dir2 = {0, 1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<vi> g(h + 2, vi(w + 2, -1));
  rep2(i, 1, h + 1) rep2(j, 1, w + 1) {
    char c;
    cin >> c;
    if(c == '#') g[i][j] = 0;
  }
  vi v;
  rep(i, h - 1) v.push_back(0);
  rep(j, w - 1) v.push_back(1);
  sort(all(v));
  bool ans = false;
  do {
    int i = 1, j = 1;
    vector<vi> gg = g;
    gg[1][1] = 1;
    bool ok = true;
    for(auto k : v) {
      if(k % 2)
        j++;
      else
        i++;
      if(gg[i][j] == -1)
        ok = false;
      else
        gg[i][j] = 1;
    }
    rep2(ih, 1, h + 1) rep2(jw, 1, w + 1) if(gg[ih][jw] == 0) ok = false;
    if(ok) ans = true;
  } while(next_permutation(all(v)));
  cout << (ans ? "Possible" : "Impossible") << endl;
}