#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
#define int long long int
#define all(v) v.begin(),v.end() 
#define rev(v) v.rbegin(),v.rend()
#define ssd ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define inp 100005
#define en "\n"
using namespace std;
using namespace __gnu_pbds;

signed main() 
{
    ssd
    int i,j,k,n;
	cin>>n;
	vector<int> val(n+5);
	for(i=1;i<=n;i++) cin>>val[i];

	vector<vector<pair<int,int>>> dp(n+5, vector<pair<int,int>> (n+5,{0,0}));
	for(i=1;i<=n;i++)
	{
		dp[1][i] = {val[i],0};
	} 
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j+i-1>n) break;
			if(i&1)
			{
				int a1 = dp[i-1][j].first + val[i+j-1], b1 = dp[i-1][j].second;
				int a2 = dp[i-1][j+1].first + val[j], b2 = dp[i-1][j+1].second;
				if(a1>a2) dp[i][j] = {a1,b1};
				else dp[i][j] = {a2,b2};
			}
			else
			{
				int a1 = dp[i-1][j].first, b1 = dp[i-1][j].second + val[i+j-1];
				int a2 = dp[i-1][j+1].first, b2 = dp[i-1][j+1].second + val[j];
				if(b1>b2) dp[i][j] = {a1,b1};
				else dp[i][j] = {a2,b2};
			}
			// cout<<i<<" "<<j<<endl;
			// cout<<dp[i][j].first<<" "<<dp[i][j].second<<endl;
		}
	}
	if(n&1) cout<<dp[n][1].first - dp[n][1].second;
	else cout<<dp[n][1].second - dp[n][1].first;
    return 0;           
}