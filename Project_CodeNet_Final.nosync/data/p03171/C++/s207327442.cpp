/* C/C++ program to remove invalid parenthesis */
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int
//#define inf 1e9+1

ll dp[3001][3001][2];

ll fun(int i, int j,int arr[], int turn)
{
    if(i>j)
    return 0;
    if(dp[i][j][turn]!=-1)
    return dp[i][j][turn];
    if(turn==1)
    return dp[i][j][turn]=max(arr[i]+fun(i+1,j,arr,0),arr[j]+fun(i,j-1,arr,0));
    else
    return dp[i][j][turn]=min(fun(i+1,j,arr,1),fun(i,j-1,arr,1));
}
int main() 
{ 
   int n;
   cin>>n;
   int arr[n];
  // ll dp[n][n];
   ll sum=0;
   for(int i=0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
   }
   
     memset(dp,-1,sizeof(dp));
    ll scoreA=fun(0,n-1,arr,1);
   // cout<<scoreA<<"  "<<sum<<" ";
    ll scoreB=sum-scoreA;
    ll ans=scoreA-scoreB;
    cout<<ans;
	return 0; 
} 
