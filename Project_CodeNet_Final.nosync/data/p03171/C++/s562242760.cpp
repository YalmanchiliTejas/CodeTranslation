#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for(int& i : a)
  {
    scanf("%d", &i);
  }
  long long dp[n][n];
  for(int i = n - 1; i >= 0; i--)
  {
    for(int j = i; j < n; j++)
    {
      if(i == j)
        dp[i][j] = a[i];
      else
        dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);  
    
    }
  } 
  printf("%lld", dp[0][n - 1]);
  return 0;
}
