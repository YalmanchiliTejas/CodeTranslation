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
const int INF = (1 << 29);
const long long INFL = (1LL<<60);
const double eps = (1e-9);

int main(int argc, char* argv[])
{
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  ll ans = INFL;
  for (int i = 0; i <= max(x, y) * 2; i += 2) {
    ll tmp = i * c;
    if ((x - i / 2) > 0) tmp += (x - i / 2) * a;
    if ((y - i / 2) > 0) tmp += (y - i / 2) * b;
    chmin(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}
