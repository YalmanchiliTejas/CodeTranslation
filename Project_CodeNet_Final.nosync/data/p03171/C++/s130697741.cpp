#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9 + 5;
constexpr long long INFLL = 1LL << 62;
constexpr double eps = (1e-9);

ll solve(const int& n, const int& l, const int& r, const vector<ll>& a, vector<vector<ll>>& dp) {
  if (dp[l][r] != -1) return dp[l][r];
  if (l == r) {
    dp[l][r] = a[l];
  } else {
    dp[l][r] = max(a[l] - solve(n, l + 1, r, a, dp), a[r] - solve(n, l, r - 1, a, dp));
  }
  return dp[l][r];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));

  ll ans = solve(n, 0, n-1, a, dp);

  cout << ans << endl;

  return 0;
}
