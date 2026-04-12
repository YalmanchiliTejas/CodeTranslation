#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
ll n, a[3010], dp[3010][3010][2];

ll diff(int i, int j, int player)
{
  if(i == j && player)
    return -a[i];
  else if(i == j && !player)
    return a[i];
  if(dp[i][j][player])
    return dp[i][j][player];
  if(player)
    return dp[i][j][player] = min(diff(i+1,j,player ^ 1) - a[i],diff(i, j-1, player ^ 1) - a[j]);
  else
    return dp[i][j][player] = max(diff(i+1,j,player ^ 1) + a[i],diff(i, j-1, player ^ 1) + a[j]);
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];

  cout << diff(0,n-1,0);
  
  return 0;
}
