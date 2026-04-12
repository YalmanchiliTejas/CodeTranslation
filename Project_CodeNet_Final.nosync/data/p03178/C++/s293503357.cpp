#include <bits/stdc++.h>
using namespace std;

int d, dp[10004][102][3];
string n;
const int mod = 1e9 + 7;

int solve(int i, int cur, int small)
{
	  if (i == n.size())
	      return small > 1 && cur == 0? -1: 0;
	  if (dp[i][cur][small] != -1)
	      return dp[i][cur][small];
	  int ans = 0;
	  for (int j = 0 + (i == 0); j < 10; j++)
	  {
	      int sum = (j + cur) % d, newsmall = small, num = n[i] - '0';
	      if (small == 1)
	      {
	      	  if (j > num)
	      	      newsmall = 2;
	      	  else
	      	      newsmall = j == num? 1: 0;
	      }
	      ans = (ans + solve(i + 1, sum, newsmall) + (sum == 0)) % mod;
	  }
	  return dp[i][cur][small] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> d;
    cout << solve(0, 0, 1);
    return 0;
}
