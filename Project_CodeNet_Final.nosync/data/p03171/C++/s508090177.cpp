#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ass 1e18
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define debug(x) cout << #x << ": " << x << endl;
#define debug2(x,y) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<< endl;
#define debug3(x,y,z) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<<" "<<#z<<" : "<<z<< endl;
using namespace std;
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll arr[200005],dp[2][3005][3005],n;

ll dfs(ll x,ll y,ll s)
{
	if(dp[s][x][y]!=-1)
		return dp[s][x][y];
	if(x==y)
	{
		dp[0][x][x]=arr[x];
		dp[1][x][x]=-1*arr[x];
		return dp[s][x][y];
	}
	ll a,b;
	if(s==0)
	{
		a=dfs(x+1,y,1)+arr[x];
		b=dfs(x,y-1,1)+arr[y];
		dp[s][x][y]=max(a,b);
	}
	else
	{
		a=dfs(x+1,y,0)-arr[x];
		b=dfs(x,y-1,0)-arr[y];
		dp[s][x][y]=min(a,b);
	}
	return dp[s][x][y];
}

int main()
{
	ll i;
	boost
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(i=1;i<=n;i++)
		cin>>arr[i];
	dfs(1,n,0);	
	cout<<dp[0][1][n];
	return 0;
}