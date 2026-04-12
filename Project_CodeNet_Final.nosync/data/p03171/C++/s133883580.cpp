#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#define MAX 3100
#define pb push_back
#define For(i,s,e) for (ll i=(s); i<(e); i++)
#define Debug_array(a,n) for (ll i=(0); i<(n); i++) cout<<a[i]<<" "
#define Foe(i,s,e) for (ll i=(s); i<=(e); i++)
#define Fod(i,s,e) for (ll i=(s)-1; i>=(e); i--)
#define Mod 1000000007
#define pii pair<ll,ll>
#define fi first
#define se second
#define endl "\n"
#define mp make_pair
#define big_prime 15486277
#define bigger_prime 179424697
#define biggest_prime 32416188691
using namespace __gnu_pbds; 
using namespace std;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> new_data_set; 

ll a[MAX];
pii dp[MAX][MAX];
pii f(ll start,ll end,ll n,ll chance){
	if(start>end) return mp(0,0);
	if(dp[start][end].fi!=-1) return dp[start][end];

	pii first = f(start+1,end,n,!chance);
	pii second = f(start,end-1,n,!chance);
	if(chance){
		first.fi+=a[start];
		second.fi+=a[end];
		if(first.fi-first.se>second.fi-second.se) dp[start][end]=first;
		else dp[start][end]=second;
	}else{
		first.se+=a[start];
		second.se+=a[end];
		if(first.fi-first.se>second.fi-second.se) dp[start][end]= second;
		else dp[start][end]= first;
	}
	return dp[start][end];
}

int main(){
	ios_base::sync_with_stdio(false);
	For(i,0,MAX) For(j,0,MAX){
		pii temp(-1,-1);
		dp[i][j]=temp;
	}
	ll n;cin>>n;
	For(i,0,n) cin>>a[i];
	pii ans = f(0,n-1,n,1);
	cout<<ans.fi-ans.se<<endl;
}
