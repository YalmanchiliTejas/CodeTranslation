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
  int n, m;
  cin >> n >> m;
  vector<vb> g(n, vb(n, false));
  vi v;
  rep(i, n) v.push_back(i);
  int ans = 0;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a][b] = g[b][a] = true;
  }
  do {
    if(v[0] != 0) continue;
    bool ok = true;
    rep(k, n - 1) {
      int i = v[k];
      int j = v[k + 1];
      if(!g[i][j]) ok = false;
    }
    if(ok) ans++;
  } while(next_permutation(all(v)));
  cout << ans << endl;
}