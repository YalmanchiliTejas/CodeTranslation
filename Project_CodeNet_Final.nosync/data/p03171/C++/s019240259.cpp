/* Dsingh_24 */

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ios	    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

#define N  100005
ll n,dp[3003][3003][3],a[3003];
ll f(ll i,ll j,ll p,ll c){
	if(i>j)return 0;
	if(dp[i][j][p]!=-hell)return dp[i][j][p];
	ll ans;
	if(!p){
		if(c==0)ans=min(f(i+1,j,p,!c),f(i+1,j,!p,!c))+a[i];
		else ans=max(f(i+1,j,p,!c),f(i+1,j,!p,!c))-a[i];
	}else{	
		if(c==0)ans=min(f(i,j-1,p,!c),f(i,j-1,!p,!c))+a[j];
		else ans=max(f(i,j-1,p,!c),f(i,j-1,!p,!c))-a[j];
	}
	return dp[i][j][p]=ans;
}
int main()
{
	ios
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=0;i<3003;i++)for(j=0;j<3003;j++)dp[i][j][0]=dp[i][j][1]=-hell;
	ll ans=max(f(1,n,0,0),f(1,n,1,0));
	cout<<ans;
	return 0;
}