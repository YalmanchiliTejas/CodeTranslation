#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll memo[3001][3001];

ll sol(int n,ll *arr,int i,int j)
{
   if(j<i)
   	return 0;
//   if(i==j)
//   	return memo[i][j]=arr[i];
   if(memo[i][j]!=-1)
   	return memo[i][j];

   ll op1=arr[i]-sol(n,arr,i+1,j);
   ll op2=arr[j]-sol(n,arr,i,j-1);

   return memo[i][j]=max(op1,op2);
}

int main()
{
	int n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
    // ll dp[n+1][n+1];
    

    // for(int i=n-2;i>=0;i--)
    // {
    // 	for(int j=i;j<n;j++)
    // 	{
    // 		if(i==j)
    // 			dp[i][j]=arr[i];
    // 		else
    // 		dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
    // 	}
    // }
    // cout<<dp[0][n-1];
    memset(memo,-1,sizeof memo);
    cout<<sol(n,arr,0,n-1);
}