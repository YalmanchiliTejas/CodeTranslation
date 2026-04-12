#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; string s; cin >> n >> s;
  REP(x, 2) REP(y, 2) {
    vector<int> ans{x, y};
    FOR(i, 1, n - 1) {
      if (ans[i] == 0) {
        ans.emplace_back(s[i] == 'o' ? ans[i - 1] ^ 1 : ans[i - 1]);
      } else {
        ans.emplace_back(s[i] == 'o' ? ans[i - 1] : ans[i - 1] ^ 1);
      }
    }
    bool ok = true;
    if (ans[0] == 0) {
      ok &= (s[0] == 'o' ? ans[1] != ans[n - 1] : ans[1] == ans[n - 1]);
    } else {
      ok &= (s[0] == 'o' ? ans[1] == ans[n - 1] : ans[1] != ans[n - 1]);
    }
    if (ans[n - 1] == 0) {
      ok &= (s[n - 1] == 'o' ? ans[n - 2] != ans[0] : ans[n - 2] == ans[0]);
    } else {
      ok &= (s[n - 1] == 'o' ? ans[n - 2] == ans[0] : ans[n - 2] != ans[0]);
    }
    if (ok) {
      REP(i, n) cout << (ans[i] == 0 ? 'W' : 'S');
      cout << '\n';
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
