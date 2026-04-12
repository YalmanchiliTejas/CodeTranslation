#include <iostream>
using namespace std;
using ll = long long;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define fromto(i,a,b) for(int i=(a);i<=(b);++i)

const int INF = 1e9;

string N; int n;
int memo[101][3][2];
int dfs(int keta, int rest, bool lower) {
  // あとrest個数字を選べて、残りketa桁決めれるときの場合の数
  if (memo[keta][rest][lower] != INF)
    return memo[keta][rest][lower];
  if (keta == n)
    return rest > 0 ? 0 : 1;

  if (lower) {
    if (rest == 0)
      return memo[keta][rest][lower] = dfs(keta+1, rest, lower);
    return memo[keta][rest][lower] = 9 * dfs(keta+1, rest-1, lower) + dfs(keta+1, rest, lower);
  }

  // まだ未確定
  int D = N[keta] - '0';
  int ans = dfs(keta+1, rest, (D > 0));

  if (rest >= 1)
    fromto(i, 1, D)
      ans += dfs(keta+1, rest-1, (i < D));
  return memo[keta][rest][lower] = ans;
}

int main() {
  int K;
  cin >> N >> K;

  n = N.size();

  rep(i, n+1) rep(j, 3) {
    memo[i][j][0] = memo[i][j][1] = INF;
  }
  // まず、Nより桁数が小さい場合をカウントしたい。
  ll ans = 0;
  rep(i, 1, n) {
    if (i < K) continue;
    ll tmp = 1;
    rep(j, K) tmp *= 9;
    if (K == 2) tmp *= (i-1);
    if (K == 3) tmp *= (i-1) * (i-2) / 2;
    ans += tmp;
  }
  ans += ((N[0]-'0')-1) * dfs(1, K-1, true);
  ans += dfs(1, K-1, false);

  cout << ans << endl;
  return 0;
}
