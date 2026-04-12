#include<bits/stdc++.h>
#define ll long long int
#define MEM(a, b) memset(a, (b), sizeof(a))
using namespace std;
ll dp[3001][3001];
ll arr[3001]={};
// ll dfs(int i,int j,int temp)
// {
//   // if(dp[i][j]!=-1) return dp[i][j];
//   // if(temp==0)
//   // {
//   //   if(i==j) return dp[i][j]=arr[i];
//   //   return dp[i][j]=max(arr[i]+dfs(i+1,j,1-temp),arr[j]+dfs(i,j-1,1-temp));
//   // }
//   // if(temp==1)
//   // {
//   //   if(i==j) return dp[i][j]=0;
//   //   return dp[i][j]=min(dfs(i+1,j,1-temp),dfs(i,j-1,1-temp));
//   // }
// 	// // temp=0 means take max //temp=1 means take min
//   // return 0;
//   temp=1;
//   for(int i=n;i>=0;i--)
//   {
//     for(int j=i;j<=n;j++)
//     {
//       if(temp==1) { temp=0; if(i==j) { dp[i][j]=arr[i];} else { dp[i][j]=max(dp[i+1][j],dp[i][j-1]); } }
//  else if(temp==0) { temp=1; if(i==j) { dp[i][j]=0;     } else { dp[i][j]=min(dp[i+1][j],dp[i][j-1]); } }
//     }
//   }
// }
int main()
{  	ios_base::sync_with_stdio(false); cin.tie(0);
    int n,a,temp;cin>>n;
    MEM(dp ,0);
    ll sum=0;
    for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
      sum+=arr[i];
		}
    a=(1+n)%2;
    for(int i=n;i>=0;i--)
    {
      for(int j=i;j<=n;j++)
      { if((i+j)%2==a) { temp=1; }else { temp=0; }
        if(temp==1) {  if(i==j) { dp[i][j]=arr[i];} else { dp[i][j]=max(arr[i]+dp[i+1][j],arr[j]+dp[i][j-1]); } }
   else if(temp==0) {  if(i==j) { dp[i][j]=0;     } else { dp[i][j]=min(dp[i+1][j],dp[i][j-1]); } }
      }
    }
    cout<<2*dp[1][n]-sum<<"\n";
    // for(int i=0;i<=4;i++)
    // {
    //   for(int j=0;j<=4;j++)
    //   cout<<dp[i][j]<<"  ";
    //   cout<<"\n";
    // }
return 0;
}
