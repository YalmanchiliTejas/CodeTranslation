#include<bits/stdc++.h>
#define F first
#define S second
#define REP(i, a, b, c) for(int i = a; i <= b; i+=c)
#define pb push_back
#define int long long int
#define MOD 1000000007
using namespace std;

int a[3005];
int dp[3005][3005][2];

int solve(int i, int j, int turn) {
  if (i > j)
    return 0;
  if (dp[i][j][turn] != -1)
    return dp[i][j][turn];
  if (turn == 1)
    return dp[i][j][turn] = max(a[i] + solve(i + 1, j, 0), a[j] + solve(i, j - 1, 0));
  else
    return dp[i][j][turn] = min(solve(i + 1, j, 1), solve(i, j - 1, 1));

}

int32_t main()
{
  ios :: sync_with_stdio(false); cin.tie(0);
  int t = 1;
  //cin >> t;
  for (int i9 = 1; i9 <= t; i9++)
  {
    int n, sum = 0;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    int X = solve(1, n, 1);
    cout << (-1) * (sum - 2 * X) << endl;
  }
}

