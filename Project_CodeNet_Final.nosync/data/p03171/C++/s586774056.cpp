#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	
	int n;
	cin>>n;
	vector<ll> A(n),pre(n);
	for(int i=0;i<n;i++)cin>>A[i];
	for(int i=0;i<n;i++)pre[i]=(i==0?A[i]:pre[i-1]+A[i]);
	ll sum=0;
	for(int x:A)sum+=x;
	vector<vector<ll>> dp(n,vector<ll>(n,0));
	for(int l=n-1;l>=0;l--)
	{
		for(int r=l;r<n;r++)
		{
			if(l==r)dp[l][r]=A[l];
			else 
			dp[l][r]= (pre[r]-pre[l]+A[l]) -min(dp[l+1][r] , dp[l][r-1] );
		}
	}
	cout<<2*dp[0][n-1]-sum<<endl;
	
}