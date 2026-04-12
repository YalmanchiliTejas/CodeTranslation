#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[3001][3001];

ll dop(ll a[],int i,int n,bool b)
{
	if(dp[i][n]!=0)return dp[i][n];
	if(i==n)
	{
		if(b)return a[i-1];
		else return (-1)*a[i-1];
	}
	if(b)
	{
		dp[i][n]=max(a[i-1]+dop(a,i+1,n,!b),a[n-1]+dop(a,i,n-1,!b));
		
	}
	else
		dp[i][n]=min(dop(a,i+1,n,!b)-a[i-1],dop(a,i,n-1,!b)-a[n-1]);
	
	return dp[i][n];
}
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		memset(dp[i+1],0,(n)*(sizeof(int)));
	}
	ll ans=dop(a,1,n,true);
	cout<<ans<<endl;
	
}