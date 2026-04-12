#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int arr[3005];
ll dp[3005][3005][2];

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  for(int i = n - 1; i >= 0; i--)
  {
      for(int j = i; j < n; j++)
      {
        if(i == j)
        {
          dp[i][j][0] = arr[i];
          dp[i][j][1] = -arr[i];
        }
        else
        {
          dp[i][j][0] = max(arr[i] + dp[i + 1][j][1], arr[j] + dp[i][j - 1][1]);
          dp[i][j][1] = min(dp[i + 1][j][0] - arr[i], dp[i][j - 1][0] - arr[j]);
        }
      }
  }
  cout << dp[0][n - 1][0];
  return 0;
}
