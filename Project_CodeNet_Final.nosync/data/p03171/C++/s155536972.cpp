#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n;
vector<int>arr(3025);
int dp[3033][3033][2];
int solve(int i ,int j ,int turn)
{
    if(i>j)
      return 0;
    
    if(dp[i][j][turn]!= -1)
      return dp[i][j][turn];

    if(turn==1)
      return dp[i][j][turn] = max((arr[i]+solve(i+1,j,0)),(arr[j]+solve(i,j-1,0)));
    else
      return dp[i][j][turn] = min(solve(i+1,j,1),solve(i,j-1,1));
}
signed main(void)
{
   
   cin>>n;
   int sum = 0;
   for(int  i = 1;i<=n;i++){
    cin>>arr[i];
    sum+=arr[i];
   }
   memset(dp , -1 ,sizeof dp);
   int ret = solve(1,n,1);
   sum-=ret;
   cout<<ret-sum<<endl;

}