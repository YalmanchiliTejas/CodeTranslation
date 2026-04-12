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
ll dp[N][N][2],a[N];

ll calc(int l,int r,int x){
	if(l==r) return (x?a[l]:-a[l]);
	if(l>r) return 0;
	
	ll& ans=dp[l][r][x];
	if(ans!=-1) return ans;
	
	if(x==1){
		ans=-1e15;
		ans=max( ans, a[l]+ calc(l+1,r,x^1)  );
		ans=max( ans, a[r]+ calc(l,r-1,x^1)  );
	}else{
		ans=1e15;
		ans=min( ans, -a[l]+ calc(l+1,r,x^1)  );
		ans=min( ans, -a[r]+ calc(l,r-1,x^1)  );
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0);
	memset(dp,-1,sizeof dp);
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	cout<<calc(0,n-1,1);
}
// check for any potential overflow before submitting
