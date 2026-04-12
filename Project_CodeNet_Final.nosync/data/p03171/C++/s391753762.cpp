#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll dp[3005][3005][2];
bool mark[3005][3005][2];
int arr[3005];

ll solve(int i, int j, int move)
{
  if(i > j)
    return 0;
  ll &ans = dp[i][j][move];
  if(mark[i][j][move])
    return ans;
  mark[i][j][move] = 1;
  if(move == 0)
  {
    return ans = max(arr[i] + solve(i + 1, j, 1), arr[j] + solve(i, j - 1, 1));
  }
  else
  {
    return ans = min(solve(i + 1, j, 0) - arr[i], solve(i, j - 1, 0) - arr[j]);
  }
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  cout << solve(0, n - 1, 0);
  return 0;
}
