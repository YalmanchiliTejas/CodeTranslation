#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define INF 0x3f3f3f3f

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<pair<int,int>,null_type, less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>   ordered_set;
const int N=3e3+10, mod=1e9+7;
ll dp[N][N],a[N];

int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0);
	memset(dp,0,sizeof dp);
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	
	for(int len=1;len<=n ;len++){
		for(int l=0;l+len-1<n;l++){
			int r=l+len-1;
			if( (n-len)%2==0 ){ // if even number of turns have been occured
				dp[l][r]=max(a[l]+dp[l+1][r] ,a[r]+dp[l][r-1] );
			}else dp[l][r]=min(-a[l]+dp[l+1][r] ,-a[r]+dp[l][r-1] );
		}
	}
	cout<<dp[0][n-1];
}

// check for any potential overflow before submitting
