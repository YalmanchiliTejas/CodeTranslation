#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[3002][3002];
int main()
{	//dp[i][j] answer of segment [i,j]
	int n;cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int l=n-1;~l;l--)
	for(int r=l;r<n;r++)
	{
		if(l==r)dp[l][r]=a[l];
		else
		dp[l][r]=max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
	}
	cout<<dp[0][n-1]<<"\n";
	
	
	
}
