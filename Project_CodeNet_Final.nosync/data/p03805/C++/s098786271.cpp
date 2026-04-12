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
  ll n, m;
  cin >> n >> m;
  vector<set<int>> g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].insert(b);
    g[b].insert(a);
  }
  ll ans = 0;
  vi v;
  rep2(i, 1, n) v.push_back(i);
  do {
    bool ok = true;
    if(!g[v[0]].count(0)) ok = false;
    rep(i, n - 2) if(!g[v[i + 1]].count(v[i])) ok = false;
    if(ok) ans++;
  } while(next_permutation(all(v)));
  cout << ans << endl;
}