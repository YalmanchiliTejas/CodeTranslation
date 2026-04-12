#include<bits/stdc++.h>
#include<string>
#define rep(i,a,b) for(long long int i=(a);i<(b);i++)
#define se(a) a.begin(),a.end()
#define ll long long int
#define mll map<ll,ll>
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define mod 1000000007
#define maxn 100005
#define inf 1e16
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll dp[3001][3001];
ll solve(ll a[],ll i,ll j)
{
	if(i>j)
	return 0;
	if(dp[i][j]!=-1)
	return dp[i][j];
	return dp[i][j]=max(a[i]+min(solve(a,i+1,j-1),solve(a,i+2,j)),a[j]+min(solve(a,i+1,j-1),solve(a,i,j-2)));
}
int main()
{
  boost;
	ll n;
	cin>>n;
	ll a[n];
	rep(i,0,n)
	cin>>a[i];
	memset(dp,-1,sizeof(dp));
	ll ans=solve(a,0,n-1);
	ll sum=0;
	rep(i,0,n)
	sum=sum+a[i];
	sum=sum-ans;
	cout<<ans-sum<<endl;
}