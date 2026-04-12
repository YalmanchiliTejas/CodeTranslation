#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll a[3333];
ll dp[3333][3333];

ll solve(int l, int r)
{
	if(l>r) return 0;
	if(l==r) return a[l];
	if(dp[l][r]!=-ll(1e18)) return dp[l][r];
	return (dp[l][r]=max(a[l]-solve(l+1,r),a[r]-solve(l,r-1)));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) dp[i][j]=-ll(1e18);
	}
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<solve(0,n-1)<<'\n';
}
