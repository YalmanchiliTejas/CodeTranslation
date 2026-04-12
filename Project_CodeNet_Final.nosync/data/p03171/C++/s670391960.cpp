#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define mp make_pair
#define x first
#define y second
typedef long long int ll;
// typedef tree< ll, null_type, less_equal< ll >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define pii pair<ll,ll>
const ll N = 3e5 +9;
// const ll m = 1e9 + 7;
const ll inf= 1e16;
const ll mod = 1e9 + 7;
ll dp[3005][3005][2];
ll a[3005];
ll rec(ll i,ll j,ll p){
	if(i==j){
		if(p==0){
			dp[i][j][p] = -a[i];
			return -a[i];		
		}
		dp[i][j][p] = a[i];
		return a[i];
	}
	if(dp[i][j][p]!=-1){
		return dp[i][j][p];
	}
	else{
		if(p==1){
			return dp[i][j][p] = max(rec(i+1,j,0)+a[i],rec(i,j-1,0)+a[j]);
		}
		else{
			return dp[i][j][p] = min(rec(i+1,j,1)-a[i],rec(i,j-1,1)-a[j]);
		

		}
	}
}

int main() {   
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    
     ll t=1;
     // cin>>t;
     while(t--){
     	ll n;cin>>n;
     	for(int i = 0;i<n;i++){
     		cin>>a[i];
     	}
     	memset(dp,-1,sizeof(dp));
     	cout<<rec(0,n-1,1);
     }     
}