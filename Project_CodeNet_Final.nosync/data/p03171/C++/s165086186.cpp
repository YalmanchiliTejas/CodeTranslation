#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=3e3+2,Mod=1e9+7;
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
int n;
ll dp[N][N],a[N];
ll solve(int i,int j)
{
  if(i==j) return dp[i][j]=a[i];
  if(dp[i][j]!=-1) return dp[i][j];
  return dp[i][j]=max(a[i]-solve(i+1,j),a[j]-solve(i,j-1));
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  memset(dp,-1,sizeof(dp));
  solve(1,n);
  cout<<dp[1][n]<<endl;
  return 0;
}
