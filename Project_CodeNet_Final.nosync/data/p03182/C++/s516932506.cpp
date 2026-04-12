#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> query[200002];

const int n = 1<<18;
ll ma[n*2], lazy[n*2];
void add(int i, ll v) {
  for (i += n; i > 1; i >>= 1) {
    if (i&1)
      lazy[i-1] += v;
    ma[i>>1] = max(ma[i]+lazy[i],ma[i^1]+lazy[i^1]);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int l, r, a;
    cin >> l >> r >> a;
    r++;
    query[l].emplace_back(l,a);
    query[r].emplace_back(l,-a);
  }
  ll off = 1e15;
  ll ans = 0;
  add(1,off);
  for (int i = 1; i <= n; i++) {
    for (auto p : query[i])
      add(p.first, p.second);
    ll score = ma[1];
    ans = max(ans, score-off);
    add(i+1, score);
    add(i  ,-score);
  }
  cout << ans << endl;
}
