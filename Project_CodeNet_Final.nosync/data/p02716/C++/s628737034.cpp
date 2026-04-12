#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
#define inf 1000000000000000000
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15) << fixed;

  ll n; cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  map<tuple<ll, ll, ll>, ll> dp;
  dp[{0, 0, 0}] = 0;

  for (ll i = 1; i < n + 1; i++) {
    ll maxj = (i % 2 == 0)? i/2 : i/2 + 1;
    ll minj = ((n - i) % 2 == 0)? n/2 - (n - i)/2 : n/2 - ((n - i)/2 + 1);
    for (ll j = minj; j < maxj + 1; j++) {
      if (dp.count(make_tuple(i - 1, j, 0)) == 0) dp[{i - 1, j, 0}] = -inf;
      if (dp.count(make_tuple(i - 1, j, 1)) == 0) dp[{i - 1, j, 1}] = -inf;
      if (dp.count(make_tuple(i - 1, j - 1, 0)) == 0) dp[{i - 1, j - 1, 0}] = -inf;
      dp[{i, j, 0}] = max(dp[{i - 1, j, 0}], dp[{i - 1, j, 1}]);
      dp[{i, j, 1}] = dp[{i - 1, j - 1, 0}] + a[i - 1];
    }
  }
  cout << max(dp[{n, n/2, 0}], dp[{n, n/2, 1}]) << endl;
}
