#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
const int N = 100030;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int mod =    1e9+7;
ll n;
ll a[3010];
ll dp[3030][3030][2];
ll fn(ll s,ll l,ll x)
{
	ll y=0;
	if(dp[s][l][x])
	return dp[s][l][x];
	if(s==l)
	{
		
		if(s>=1&&s<=n){

	  if(!x){

	  dp[s][s][0]=a[s];
	return a[s];}
	else  {
	dp[s][s][1]=-a[s];return -a[s];}}
	else
	return 0;
}
 if(!x)
	 y=max(a[s]+fn(s+1,l,1^x),a[l]+fn(s,l-1,1^x));
 else
 y=min(fn(s+1,l,1^x)-a[s],fn(s,l-1,1^x)-a[l]);
	dp[s][l][x]=y;
//	cout<<s<<" "<<l<<" "<<x<<" "<<y<<endl;
	return y;
}
int main()
{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
rep(i,1,n+1)
cin>>a[i];
memset(dp,0,sizeof(dp));
fn(1,n,0);
cout<<dp[1][n][0];
}