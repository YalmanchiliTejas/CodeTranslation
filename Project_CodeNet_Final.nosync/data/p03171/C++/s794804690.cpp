#include<bits/stdc++.h>
#define int long long int
#define pll pair<ll,ll>
#define un unsigned
#define dbl long double
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000009
#define eps 0.0000000001
#define inf 10000000000001
#define all(x) (x).begin(),(x).end()
#define size(x) (int)(x).size()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define vv(dt) vector<vector<dt>>
#define fastio(x) ios_base::sync_with_stdio(x); cin.tie(NULL)
#define debug(x) cerr<<"LINE: "<<__LINE__<<" || "<<#x<<" = "<<x<<endl
#define loop(i,s,n) for(auto i=s;i<n;i++)
#define rloop(i,n,b) for(auto i=n-1;i>=b;i--)
using namespace std;

int a[3001],dp[3001][3001];

int f(int l,int r)
{
	if(l==r) return a[l];
	if(dp[l][r]!=-1) return dp[l][r];
	dp[l][r] = max(a[l] - f(l+1,r), a[r] - f(l,r-1));
	return dp[l][r];
}

signed main()
{
	fastio(0);
	int n;
	cin>>n;
	loop(i,0,n) cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<f(0,n-1)<<endl;
	return 0;
}