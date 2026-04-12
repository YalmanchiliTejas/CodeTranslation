// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define fore(x, c) for(auto &&x : c)
#define rep(i, a, n) for(int i = a, i##len = (int)(n); i < i##len; ++i)
#define rrep(i, a, n) for(int i = (int)(n - 1); i >= a; --i)
#define sz(c) ((int)c.size())
#define contains(c, x) (c.find(x) != end(c))
#define inseg(l, x, r) ((l) <= (x) && (x) < (r))
#define dump(...)
#define pb push_back
#define eb emplace_back
#define _ 0
const signed INF_ = 1001001001; const long long INF = 1001001001001001001LL;
const int DX[9] = {0,1,0,-1,1,1,-1,-1,0}, DY[9] = {-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os, const vector<T> &v) {
  for (auto i = begin(v); i != end(v); i++) os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is, vector<T> &v) {
  for (auto i = begin(v); i != end(v); i++) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
  is>>p.first>>p.second;return is;}
template<class T, class U> bool chmax(T &a, const U &b){return a<b?a=b,1:0;}
template<class T, class U> bool chmin(T &a, const U &b){return a>b?a=b,1:0;}
template <class T> void psum(T& c) {partial_sum(begin(c), end(c), begin(c));}
template<class T> using heap = priority_queue<T, deque<T>, greater<T>>;
struct before_main_function {
  before_main_function() {
      cin.tie(nullptr); ios::sync_with_stdio(0);
      cout << setprecision(15) << fixed;
  }
} before_main_function;
// clang-format on
//------------------8<------------------------------------8<--------------------

signed main() {
  string N;
  int K;
  cin >> N >> K;

  int memo[110][4][2];
  rep(i, 0, 110) rep(j, 0, 4) rep(k, 0, 2) memo[i][j][k] = INF;
  auto dfs = [&](auto fun, int i, int k, bool less) -> int {
    if (k < 0) return 0;
    if (i == sz(N)) {
      return k == 0;
    }
    auto &MEMO = memo[i][k][less];
    if (MEMO != INF) return MEMO;

    int ret = 0;
    if (less) {
      rep(d, 0, 10) { ret += fun(fun, i + 1, k - (d != 0), true); }
    } else {
      {
        int d = N[i] - '0';
        ret += fun(fun, i + 1, k - (d != 0), false);
      }
      rep(d, 0, N[i] - '0') { ret += fun(fun, i + 1, k - (d != 0), true); }
    }
    return MEMO = ret;
  };
  cout << dfs(dfs, 0, K, false) << endl;
  return (0 ^ _ ^ 0);
}

