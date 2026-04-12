#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);


int main(int argc, char* argv[])
{
  ll n, k;
  cin >> n >> k;

  if (k == 0) {
    cout << n * n << endl;
    return 0;
  }

  ll ans = 0;
  for (int b = k+1; b <= n; b++) {
    ans += (b-k) * (n/b);
    ans += max(ll(0), (n % b - k + 1));
  }

  cout << ans << endl;

  return 0;
}
