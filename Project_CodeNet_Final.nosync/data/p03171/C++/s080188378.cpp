#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxm=3e3+2;
 ll dp[maxm][maxm];
ll arr[maxm];
ll cal(int start,int end)
{
	if(start==end)return arr[start];
    if(dp[start][end]!=-1)return dp[start][end];
	return dp[start][end]=max(arr[start]-cal(start+1,end),arr[end]-cal(start,end-1));
}
int main()
{ 
   int n;cin>>n;memset(dp,-1,sizeof(dp));
   for(int i=0;i<n;i++)cin>>arr[i];
   	cout<<cal(0,n-1);  		
}