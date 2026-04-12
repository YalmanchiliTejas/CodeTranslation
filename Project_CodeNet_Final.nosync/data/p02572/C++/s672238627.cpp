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
constexpr int INF = 1001001001;
constexpr long long INFL = (1LL<<60);
constexpr double eps = (1e-9);

ll mod = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> csum(n, 0);
  csum[n-1] = a[n-1];
  for (int i = n - 2; i >= 0; i--) {
    csum[i] = (a[i] + csum[i+1]) % mod;
  }

  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ll tmp = a[i] * csum[i+1];
    tmp %= mod;
    ans += tmp;
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}
