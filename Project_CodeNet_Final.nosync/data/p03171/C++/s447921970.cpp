
// Problem : L - Deque
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_l
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define int         long long
#define ull 		unsigned long long
#define ll 			long long
#define MM			1000000007
#define N			100005
#define pb 			push_back
#define p_q 		priority_queue
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define Endl        '\n'
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define ios	    	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp 			make_pair
#define lb 			lower_bound
#define ub			upper_bound
#define F           first
#define S           second
#define rep(i, begin, end) for(int i=begin;i<end;i++)
#define repr(i,begin,end) for(int i=end-1;i>=begin;i--)
#define ini(a,n,b)	for(ll int i=0;i<n;i++) a[i]=0;
#define cset(a)		__builtin_popcountll(a)
#define hell 		(ull)1e9
#define re 			resize
 
 
 
signed main(void)
{ios
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
	{
		int n;
		cin>>n;
		int a[n+1];
		rep(i,1,n+1) cin>>a[i];
		int dp[n+1][n+1];
		for(int l=n;l>=1;l--)
		{
		    for(int r=l;r<=n;r++)
		    {
		        if(l==r) dp[l][r]=a[l];
		        else dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
		    }
		}
		cout<<dp[1][n];
	}
}