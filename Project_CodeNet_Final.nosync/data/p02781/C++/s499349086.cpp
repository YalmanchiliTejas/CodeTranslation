#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>
#include <iomanip>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

// #define rep(i,n) for(int i=0;i<(n);++i)
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _fromto2(i,n) for(int i=0;i<=(n);++i)
#define _fromto3(i,a,b) for(int i=(a);i<=(b);++i)
#define fromto(...) _overload3(__VA_ARGS__,_fromto3,_fromto2,)(__VA_ARGS__)

#define rrep(i,n) for(int i=(n);i>=0;--i)
const int MOD = 1e9+7;
const int INF = 1e9;
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

// debug
template<class T>ostream& operator<<(ostream& os,const vector<T>& vec){os<<"{";for(int i=0;i<vec.size();++i)os<<(i?", ":"")<<vec[i];os<<"}";return os;}
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>& rhs){os<<"("<<rhs.first<<", "<<rhs.second<<")";return os;}

#ifdef LOCAL
void debug() {cerr << "\n";}
template<class First> void debug(const First& first) {cerr<<first<<"\n";}
template<class First, class... Rest> void debug(const First& first, const Rest&... rest) {cerr<<first<<",";debug(rest...);}
#else
#define debug(...) 42
#endif

string N; int n;
int memo[101][3][2];
int dfs(int keta, int rest, bool lower) {
  // あとrest個数字を選べて、残りketa桁決めれるときの場合の数
  if (memo[keta][rest][lower] != INF)
    return memo[keta][rest][lower];
  if (keta == n && rest > 0)
    return memo[keta][rest][lower] = 0;
  if (keta == n)
    return memo[keta][rest][lower] = 1;

  if (lower) {
    if (rest == 0)
      return memo[keta][rest][lower] = dfs(keta+1, rest, lower);
    return memo[keta][rest][lower] = 9 * dfs(keta+1, rest-1, lower) + dfs(keta+1, rest, lower);
  }

  // まだ未確定
  int D = N[keta] - '0';
  int ans = dfs(keta+1, rest, (D > 0));

  if (rest >= 1)
    fromto(i, 1, D) {
      ans += dfs(keta+1, rest-1, (i < D));
    }
  return memo[keta][rest][lower] = ans;
}

int main() {
  int K;
  cin >> N >> K;

  n = N.size();

  rep(i, n+1) rep(j, 3) {
    memo[i][j][0] = INF;
    memo[i][j][1] = INF;
  }
  // まず、Nより桁数が小さい場合をカウントしたい。
  ll ans = 0;
  rep(i, 1, n) {
    if (i < K)
      continue;
    // i桁のときを数える
    ll tmp = 1;
    rep(j, K)
      tmp *= 9;
    // i-1箇所からk-1個選ぶ。
    if (K == 2)
      tmp *= (i-1);
    if (K == 3)
      tmp *= (i-1) * (i-2) / 2;
    ans += tmp;
  }
  ans += ((N[0]-'0')-1) * dfs(1, K-1, true);
  ans += dfs(1, K-1, false);

  cout << ans << endl;
  return 0;
}
