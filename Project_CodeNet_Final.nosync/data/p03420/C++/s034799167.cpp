#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = int64_t;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1'001'001'001;
const ll INFL = (1LL<<60);
const double eps = (1e-9);

const ll mod = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, K;
  cin >> N >> K;

  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }

  ll ans = 0;
  for (ll b = K; b <= N; b++) {
    ans += (b - K) * (N / b) + max(ll(0), N % b - K + 1);
  }

  cout << ans << endl;

  return 0;
}
