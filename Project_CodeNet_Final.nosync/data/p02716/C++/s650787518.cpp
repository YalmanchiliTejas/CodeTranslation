#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define pb push_back
#define in insert
#define pi pair<int, int>
#define pii pair<int, pi>
#define mp make_pair
#define fir first
#define sec second
#define MAXN 200001
#define INF 1000000000

int n;
lli v[MAXN];
lli dp[MAXN][3];

lli solve(int i, int limit)
{
  if (dp[i][limit] != -1)
    return dp[i][limit];
  if (i >= n)
    return dp[i][limit] = 0;
  lli coloca = v[i] + solve(i + 2, limit);
  if (limit > 0)
  {
    lli nao_coloca = solve(i + 1, limit - 1);
    dp[i][limit] = max(coloca, nao_coloca);
  }
  else
    dp[i][limit] = coloca;
  return dp[i][limit];
}
signed main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  memset(dp, -1, sizeof(dp));
  lli m;
  (n % 2 == 0) ? m = 1 : m = 2;
  cout << solve(0, m) << endl;
  return 0;
}