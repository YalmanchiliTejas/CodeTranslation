#include<bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
#define chmax(x, a)  do { x = max(x, a); } while(0)
#define chmin(x, a)  do { x = min(x, a); } while(0)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> PLL;

ll N, X, M;

// 最初の頂点からの距離
vector<ll> visited(300000, -1);
vector<ll> sum(300000, 0);
ll ans = 0;

void solve() {
  cin >> N >> X >> M;
  visited.resize(M, -1);
  sum.resize(M, -1);

  ll i = 1;
  ll cur = X % M;
  ans += cur, visited[cur] = 1, sum[cur] = ans;
  i++;

  while (i <= N) {
    ll nxt = (cur * cur) % M;
    ll len = (i - visited[nxt]);
    ll _sum = ans - sum[nxt] + nxt;
    ll t = (N - i + 1) / len;

    if (visited[nxt] != -1 && t > 0) {
      // 2回目に訪れる
      ans += t * _sum;
      i   += t * len;
    } else {
      // 初回に訪れる
      ans += nxt, visited[nxt] = i, sum[nxt] = ans;
      cur = nxt;
      i++;
    }
  }
  cout << ans << endl;
}

int main() {
  //ll T;
  //cin >> T;
  //rep(_,T)
    solve();
  return 0;
}
