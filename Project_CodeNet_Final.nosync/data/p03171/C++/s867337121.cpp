
// Problem : L - Deque
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_l
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define db double
#define mod 1000000007
#define pb push_back
#define pp pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repe(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=b;i>=a;i--)
#define maxn 3005
#define ss second
#define ff first
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
int inv(int a, int b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}
int n;
int a[maxn],dp[maxn][maxn][2];
void fun(int l,int r,int f)
{
	//cout <<l <<" " << r <<" "<<f <<"\n";
	if(dp[l][r][f]!=-1)
		return;
	if(l == r)
	{
		dp[l][r][f]=a[l];
		dp[l][r][1-f]=0;
		return;
	}
	fun(l,r-1,1-f);
	fun(l+1,r,1-f);
	dp[l][r][f] = max(a[l]+dp[l+1][r][f],a[r]+dp[l][r-1][f]);
	if(dp[l][r][f] == a[l]+dp[l+1][r][f])
		dp[l][r][1-f] = dp[l+1][r][1-f];
	else dp[l][r][1-f]=dp[l][r-1][1-f];
}
void solve()
{
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	memset(dp,-1,sizeof(dp));
	fun(0,n-1,1);
	cout << dp[0][n-1][1]-dp[0][n-1][0];
}
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while(t--)
    solve();
    return 0;
}
