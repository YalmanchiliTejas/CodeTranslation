#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[3001];
ll dp[3001][3001];
ll s[3001];
ll calc(ll i,ll j){
	if(i==j){
		dp[i][j]=a[i];
		return dp[i][j];
	}
	if(dp[i][j]!=-1)
	return dp[i][j];
	dp[i][j]=max(a[i]+s[j]-s[i]-calc(i+1,j),a[j]+s[j-1]-s[i-1]-calc(i,j-1));
	return dp[i][j];
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	memset(dp,-1,sizeof(dp));
	calc(1,n);
	cout<<(dp[1][n]-(s[n]-s[0]-dp[1][n]));
	return 0;
}