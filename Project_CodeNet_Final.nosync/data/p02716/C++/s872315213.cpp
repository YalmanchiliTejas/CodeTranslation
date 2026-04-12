#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long,long long> ii; 	
typedef complex<long double> com;

const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vector <ll> arr(n+1);
	for (int z=1;z<=n;z++){
		cin >> arr[z];
	}
	vector <map<ll,vector<ll>>> dp(n+1);
	dp[0][0].resize(2);
	dp[0][0][0] = 0;
	dp[0][0][1] = -(ll(1) << 50);
	for (int z=1;z<=n;z++){
		for (int x=max(ll(z)/2-5,ll(0));x<z/2+5;x++){
			dp[z][x].resize(2);
			dp[z][x][0] = -(ll(1) << 60);
			dp[z][x][1] = -(ll(1) << 60);
			for (int i=1;i<=4;i++){
				if (z-i < 0) break;
				if (dp[z-i].find(x) != dp[z-i].end()) dp[z][x][0] = max(dp[z][x][0],dp[z-i][x][1]);
				if (dp[z-i].find(x-1)!= dp[z-i].end()) dp[z][x][1] = max(dp[z][x][1],dp[z-i][x-1][0]+arr[z]);
			}
		}
	}
	ll ans = -LLONG_MAX;
	for (int z=1;z<=n;z++){
		if (dp[z].find(n/2) != dp[z].end()){
			ans = max(ans,max(dp[z][n/2][0],dp[z][n/2][1]));
		}
	}
	cout << ans << endl;
}
