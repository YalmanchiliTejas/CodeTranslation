#include<bits/stdc++.h>
#define ll long long int
#define MEM(a, b) memset(a, (b), sizeof(a))
using namespace std;
ll dp[3001][3001];
ll arr[3001]={};
ll dfs(int i,int j,int temp)
{
  if(dp[i][j]!=-1) return dp[i][j];
  if(temp==0)
  {
    if(i==j) return dp[i][j]=arr[i];
    return dp[i][j]=max(arr[i]+dfs(i+1,j,1-temp),arr[j]+dfs(i,j-1,1-temp));
  }
  if(temp==1)
  {
    if(i==j) return dp[i][j]=0;
    return dp[i][j]=min(dfs(i+1,j,1-temp),dfs(i,j-1,1-temp));
  }
	// temp=0 means take max //temp=1 means take min
  return 0;
}
int main()
{  	ios_base::sync_with_stdio(false); cin.tie(0);
    int n;cin>>n;
    MEM(dp ,-1);
    ll sum=0;
    for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
      sum+=arr[i];
		}
    cout<<2*dfs(1,n,0)-sum<<"\n";
    // for(int i=0;i<=4;i++)
    // {
    //   for(int j=0;j<=4;j++)
    //   cout<<dp[i][j]<<"  ";
    //   cout<<"\n";
    // }
return 0;
}
