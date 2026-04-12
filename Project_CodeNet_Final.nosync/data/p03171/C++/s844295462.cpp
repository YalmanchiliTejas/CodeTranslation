#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
#define int long long int
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);
lli dp[3005][3005] = {};
// dp[x][y] 先頭からx, 最後にy個取られた状態からスタートしたときの結果
// x+y+1番目の行動 x+y+1が奇数のとき 太郎くんが動く.
// dp[x+1][y]またはdp[x][y+1]に遷移
// dp[x][y] := max(dp[x+1][y]+a[x], dp[x][y+1]+a[n-1-y]) if x+y+1 is odd
// dp[x][y] := min(dp[x+1][y]-a[x], dp[x][y+1]-a[n-1-y]) if x+y+1 is even
int n;
vector<lli> a;
lli f(int x, int y)
{
  if (x + y == n)
    return 0;
  if (dp[x][y] != 1e18)
    return dp[x][y];
  if ((x + y) & 1)
    dp[x][y] = min(f(x + 1, y) - a[x], f(x, y + 1) - a[n - 1 - y]);
  else
    dp[x][y] = max(f(x + 1, y) + a[x], f(x, y + 1) + a[n - 1 - y]);
  return dp[x][y];
}
void solve(long long N)
{
  n = N;
  rep(i, N + 1) rep(j, N + 1) dp[i][j] = 1e18;
  cout << f(0, 0) << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  a.resize(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &a[i]);
  }
  solve(N);
  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2>
bool chmin(T1 &l, const T2 &r)
{
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2>
bool chmax(T1 &l, const T2 &r)
{
  return (l < r) ? (l = r, true) : false;
}
