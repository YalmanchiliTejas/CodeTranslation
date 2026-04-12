#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int n; cin >> n;
  vector<pair<int, int>> xy(n);
  REP(i, n) {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    xy[i] = {x, y};
  }
  sort(ALL(xy));
  vector<pair<int, int>> idx(n);
  map<int, int> red, blue;
  REP(i, n) {
    int x, y; tie(x, y) = xy[i];
    idx[i] = {-y, i};
    ++red[x];
    ++blue[y];
  }
  ll ans = 1LL * (red.rbegin()->first - red.begin()->first) * (blue.rbegin()->first - blue.begin()->first);
  REP(i, n) {
    int x, y; tie(x, y) = xy[idx[i].second];
    --red[x];
    if (red[x] == 0) red.erase(x);
    --blue[y];
    if (blue[x] == 0) blue.erase(y);
    ++red[y];
    ++blue[y];
    chmin(ans, 1LL * (red.rbegin()->first - red.begin()->first) * (blue.rbegin()->first - blue.begin()->first));
  }
  red.clear();
  blue.clear();
  REP(i, n) {
    int x, y; tie(x, y) = xy[i];
    ++red[x];
    ++blue[y];
  }
  REP(i, n) {
    int x, y; tie(x, y) = xy[i];
    --red[x];
    if (red[x] == 0) red.erase(x);
    --blue[y];
    if (blue[x] == 0) blue.erase(y);
    ++red[y];
    ++blue[y];
    chmin(ans, 1LL * (red.rbegin()->first - red.begin()->first) * (blue.rbegin()->first - blue.begin()->first));
  }
  cout << ans << '\n';
  return 0;
}
