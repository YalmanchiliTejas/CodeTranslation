#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (int i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define fi first
#define se second
#define int long long
using namespace std;
using ll = long long;
using II = pair<int, int>; using VII = vector<II>;
using VI = vector<int>; using VVI = vector<VI>; using VVVI = vector<VVI>;
template <class T = int> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T = int> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { int n = d.size(); REP (i, n) s << d[i] << " "; return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& dd) { for (vector<T> d: dd) s << d << endl; return s; }
template <class T, class S> ostream& operator<<(ostream &s, const pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
#ifdef _MY_DEBUG
  #define dump(...) cerr << "\t" << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl << "\t", dump_func(__VA_ARGS__);
#else
  #define dump(...)
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
const int MOD = 1e9 + 7;

VI nums(50, 1);
VI ps(50, 1);
int solve(int n, int x) {
  dump(n, x);
  if (n == 0) {
    assert(x == 0 || x == 1);
    return x;
  }
  if (x <= nums[n - 1] + 1) {
    return solve(n - 1, max(0LL, x - 1));
  } else if (x <= nums[n - 1] + 2) {
    return ps[n - 1] + 1;
  } else {
    return ps[n - 1] + 1 + solve(n - 1, min(nums[n - 1], x - nums[n - 1] - 2));
  }
}
signed main() {
  REP (i, 49) {
    nums[i + 1] = nums[i] * 2 + 3;
    ps[i + 1] = ps[i] * 2 + 1;
  }
  int N, X; cin >> N >> X;
  cout << solve(N, X) << endl;
}
