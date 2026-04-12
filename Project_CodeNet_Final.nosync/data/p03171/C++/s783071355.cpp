/***** TheAnshul *****/

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vii         vector<pair<ll int, ll int>>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;
#define N  3005
ll n;
ll dp[N][N];
// bool dp1[N][N];
ll a[N];
ll fun(ll i,ll j)
{
	if(i==j)
	{
		return a[i];
	}
	if(dp[i][j]!=LLONG_MAX)
	{
		return dp[i][j];
	}
	ll v1,v2;
	dp[i][j]=max(-fun(i+1,j)+a[i],-fun(i,j-1)+a[j]);
	return dp[i][j];
}
void solve()
{
	cin>>n;
	rep(i,1,n+1)
	cin>>a[i];
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			dp[i][j]=LLONG_MAX;
		}
	}
	cout<<fun(1,n);
	// ll x=0,y=0,l=1,r=n,i=0;
	// while(l!=r)
	// {
	// 	cout<<dp1[l][r];
	// 	if(dp1[l][r])
	// 	{
	// 		if(i&1)
	// 			y+=a[l];
	// 		else
	// 			x+=a[l];
	// 		l++;
	// 	}
	// 	else
	// 	{
	// 		if(i&1)
	// 			y+=a[r];
	// 		else
	// 			x+=a[r];
	// 		r--;	
	// 	}
	// 	i++;
	// }
	// if(i&1)
	// {
	// 	y+=a[l];
	// }
	// else
	// {
	// 	x+=a[l];
	// }
	// cout<<x-y;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		solve();
	}
	time
	return 0;
}