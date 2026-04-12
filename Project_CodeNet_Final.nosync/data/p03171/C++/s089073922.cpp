#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define watch(x) cout<<(#x)<<" is "<<x<<endl;
#define ll long long int
#define pb push_back
#define in insert
#define mp make_pair
#define F first
#define S second
#define N 1000000
#define MOD 1000000007
#define PI acos(-1)
ll dp[3005][3005];
ll func(ll l,ll r,ll a[])
{
	if(l>r)
	return 0;
	if(dp[l][r]!=-1)
	return dp[l][r];
	if(l==r)
	return dp[l][r]=a[l];
	return dp[l][r]=max(a[l]-func(l+1,r,a),a[r]-func(l,r-1,a));
}
int main()
{
	IOS
	ll n;
	cin>>n;
	ll a[n],i;
	for(i=0;i<n;i++)
	cin>>a[i];
	memset(dp,-1,sizeof(dp));
	ll ans=func(0,n-1,a);
	cout<<ans;
}