#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
constexpr int INF = 1e9;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

// Lv n バーガの下から x 個に含まれる P の数
ll calc(const vector<ll>& n_all, const vector<ll>& n_p, ll n, ll x) {
  if (n == 0 && x > 0) return 1;
  else if (n == 0) return 0;
  x--;
  ll ret = 0;
  if (x  >= n_all[n-1]) {
    ret += n_p[n-1];
    x -= n_all[n-1];
    if (x > 0) {  // ちょうど中間の P
      ret++;
      x--;
    }
  }

  if (x <= 0) return ret;
  ret += calc(n_all, n_p, n-1, x);
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, x;
  cin >> n >> x;

  vector<ll> n_p(51);
  vector<ll> n_all(51);
  n_p[0] = 1;
  n_all[0] = 1;
  for (int i = 1; i <= 50; i++) {
    n_p[i] = n_p[i-1] * 2 + 1;
    n_all[i] = n_all[i-1] * 2 + 3;
  }
  ll ans = calc(n_all, n_p, n, x);

  cout << ans << endl;

  return 0;
}
