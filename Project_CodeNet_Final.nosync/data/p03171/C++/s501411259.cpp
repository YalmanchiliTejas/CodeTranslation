#include<bits/stdc++.h>
#define ll 				long long
#define ld 				long double
#define fastio 			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) 		cerr<<#x<<" "<<x<<endl
#define cina(a,n) 		for(ll i = 0;i<n;i++)	cin>>a[i];
#define couta(a,n) 		for(ll i = 0;i<n;i++) cout<<a[i]<<" ";
#define fauto(ar)		for(auto x : ar)	cout<<x<<" ";
#define mod 			1000000007
#define inf				10010010010010010
#define siz 			3005
#define f 				first
#define s 				second
#define pb 				push_back
#define endl 			"\n"
#define ci 				cin.ignore()
using namespace std;
ll dp[siz][siz];
ll getans(ll *a,ll n,ll s,ll e)
{
	if(s > e)	return 0;
	if(s == e)	return a[s];
	if(dp[s][e] != -inf)	return dp[s][e];
	return dp[s][e] = max(a[s] + min(getans(a,n,s+1,e-1),getans(a,n,s+2,e)),a[e] + min(getans(a,n,s+1,e-1),getans(a,n,s,e-2)));
}
int main()
{
	ll n,i,j = 0;
	cin>>n;
	ll a[n];
	cina(a,n);
	for(i = 0;i<n+1;i++)	for(j = 0;j<n+1;j++)	dp[i][j] = -inf;
	j = 0;
	for(ll x : a)
	j += x;
//	debug(getans(a,n,0,n-1));
	cout<<2*getans(a,n,0,n-1)-j;
}