#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[3005];
ll dp[3005][3005];
ll f(int i,int j)
{
  if(dp[i][j] != 0) return dp[i][j];
  if(i>j) return 0;
  dp[i][j] =  max(a[i] - f(i+1,j),a[j]-f(i,j-1));
  return dp[i][j];
}

int main() {
  int n;
  cin>>n;
  for(int i=0;i<3005;i++)
  {
    for(int j=0;j<3005;j++)
    {
      dp[i][j] = 0;
    }
  }
  for(int i=1;i<=n;i++) cin>>a[i];
  cout<<f(1,n)<<endl;
  return 0;
}