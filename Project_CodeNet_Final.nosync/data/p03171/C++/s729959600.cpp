#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int arr[3005];
ll dp[3005][3005][2];

ll solve(int i, int j, int turn)
{
    if(i > j)
      return 0;
    ll &ans = dp[i][j][turn];
    if(~ans)
      return ans;
    if(!turn)
      return ans = max(arr[i] + solve(i + 1, j, 1), arr[j] + solve(i, j - 1, 1));
    else
      return ans = min(solve(i + 1, j, 0) - arr[i], solve(i, j - 1, 0) - arr[j]);
}

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  memset(dp, -1, sizeof dp);
  cout << solve(0, n - 1, 0);
  return 0;
}
