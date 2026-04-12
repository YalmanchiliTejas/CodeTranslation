#include<bits/stdc++.h>
using namespace std;
long long int dp[3001][3001]; int arr[3000];
long long int solve(int i,int j)
{  if(i>j)
   return 0;
   if (dp[i][j]!=-1) return dp[i][j];
   dp[i][j]=max(arr[i]-solve(i+1,j),arr[j]-solve(i,j-1));
   return dp[i][j];
}
int main()
{int n;
cin>>n;
for(int i=0;i<n;++i)
cin>>arr[i];
memset(dp,-1,sizeof(dp));
long long int result=solve(0,n-1);
cout<<result;
}