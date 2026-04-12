#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long int> v(n);
  long long int sum =0;
  for(int i = 0;i<n;i++)
  {  
    cin >> v[i];
    sum += v[i];
  }
  vector<vector<long long int> > dp(n,vector<long long int>(n,0));
  
  for(int i = 0;i<n;i++)
    dp[i][i] = v[i];
  for(int i = 0;i< n-1;i++)
    dp[i][i+1] = max(v[i],v[i+1]);
  for(int l =3 ; l <= n;l++)
  {
    int i = 0;
    int j = i+l-1;
    while(j < n)
    {
      dp[i][j] = max(v[i] + min(dp[i+1][j-1],dp[i+2][j]),
                                v[j] + min(dp[i+1][j-1],dp[i][j-2]));
      i++;j++;
    }
  }
  cout << (2*dp[0][n-1] - sum) << endl; 
  return 0;
}