#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3001][3001];
ll arr[3001];ll n;ll m;
ll solve(ll i,ll j)
{
	if(i>j)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	ll p=(j-i+1);p%=2;
	if(p==m)
	{
		dp[i][j]=max(solve(i+1,j)+arr[i],solve(i,j-1)+arr[j]);
	}
	else
	dp[i][j]=min(solve(i+1,j)-arr[i],solve(i,j-1)-arr[j]);
	return dp[i][j];
}
int main() {
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<3001;i++)
	for(int j=0;j<3001;j++)
	dp[i][j]=-1;
	m=n%2;
	cout<<solve(0,n-1);
}	