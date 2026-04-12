/*
    STARK_BOY
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repe(i,a,b) for(ll i=a;i<=b;i++)
#define bac(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef vector< ll > vi;
typedef vector<pair<ll,ll> > vpii;
typedef pair<ll,ll> pii;
#define all(c) c.begin(),c.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setbitc(x) __builtin_popcount(x)
#define init(x,a) memset(x,a,sizeof(x))
#define PI           3.14159265358979323846  /* pi */
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
#define N 3005
//Variables Start
ll inf=1e18,MOD=1e9+7;
ll n,m,k,ar[N],dp[N][N][2];
string s,s1;
//Variables End

ll compute(ll l,ll r,ll st)
{
	if(dp[l][r][st]!=-inf)return dp[l][r][st];
	if(l==r && st)return ar[l];
	if(l==r && !st)return -ar[l];

	if(st)
	{
		dp[l][r][st]=max(compute(l+1,r,1-st)+ar[l],compute(l,r-1,1-st)+ar[r]);
	}
	else
	{
		dp[l][r][st]=min(compute(l+1,r,1-st)-ar[l],compute(l,r-1,1-st)-ar[r]);
	}

	return dp[l][r][st];
}
int main()
{
    ios
    int ti=1;
    //cin>>ti;
    while(ti--)
    {
		cin>>n;
		rep(i,0,n+1)rep(j,0,n+1)rep(k,0,2)dp[i][j][k]=-inf;

		rep(i,0,n)cin>>ar[i];
		cout<<compute(0,n-1,1);
    }
    return 0;
        
}