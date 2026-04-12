#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
#pragma GCC omodtimize("unroll-loops,no-stack-protector")
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
	ll dp[n+1][3][2];
	for (int z=0;z<=n;z++){
		for (int x=0;x<3;x++){
			for (int y=0;y<2;y++){
				dp[z][x][y] = -(ll(1) << 50);
			}
		}
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	for (int z=1;z<=n;z++){
		dp[z][0][1] = max(dp[z][0][1],dp[z-1][0][0]+arr[z]);
		dp[z][0][0] = max(dp[z][0][0],dp[z-1][0][1]);

		dp[z][1][1] = max(dp[z][1][1],dp[z-1][1][0]+arr[z]);
		dp[z][1][0] = max(dp[z][1][0],dp[z-1][1][1]);

		dp[z][2][1] = max(dp[z][2][1],dp[z-1][2][0]+arr[z]);
		dp[z][2][0] = max(dp[z][2][0],dp[z-1][2][1]);

		if (z >= 3){
			dp[z][1][1] = max(dp[z][1][1],dp[z-3][0][1]+arr[z]);
			dp[z][2][1] = max(dp[z][2][1],dp[z-3][1][1]+arr[z]);
		}

		if (z >= 4){
			dp[z][2][1] = max(dp[z][2][1],dp[z-4][0][1]+arr[z]);
		}
		
	}
	ll ans = -LLONG_MAX;
	if (n & 1){
		for (int x=0;x<3;x++){
			for (int y=0;y<2;y++){
				if (x == 2 && y == 0) continue;
				ans = max(ans,dp[n][x][y]);
			}
		}
	} else {
		for (int x=0;x<2;x++){
			for (int y=0;y<2;y++){
				if (x == 1 && y == 0) continue;
				ans = max(ans,dp[n][x][y]);
			}
		}
	}
	
	cout << ans << endl;
}
