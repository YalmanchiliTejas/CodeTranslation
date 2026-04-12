#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  ll n; int x, m; cin >> n >> x >> m;
  vector<int> a{x};
  vector<bool> exist(m, false);
  exist[x] = true;
  ll cur = x;
  while (!exist[cur * cur % m]) {
    cur = cur * cur % m;
    a.emplace_back(cur);
    exist[cur] = true;
  }
  cur = cur * cur % m;
  vector<int> loop;
  while (a.back() != cur) {
    loop.emplace_back(a.back());
    a.pop_back();
  }
  loop.emplace_back(cur);
  a.pop_back();
  reverse(ALL(loop));
  ll ans = 0;
  for (int e : a) {
    if (n > 0) {
      --n;
      ans += e;
    }
  }
  ans += accumulate(ALL(loop), 0LL) * (n / loop.size());
  n %= loop.size();
  REP(i, n) ans += loop[i];
  cout << ans << '\n';
  return 0;
}
