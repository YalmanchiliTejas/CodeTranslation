#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC omodtimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long ,long long> ii; 	
typedef complex<long double> com;
 
const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,s;
	cin >> n >> s;
	vector <ll> arr(n+1);
	for (int z=1;z<=n;z++){
		cin >> arr[z];
	}
	vector <vector<ll>> dp(n+1,vector<ll>(s+1));
	dp[0][0] = 1;
	for (int z=1;z<=n;z++){
		if (arr[z] <= s)
		dp[z][arr[z]] += z;
		for(int x=1;x<=s;x++){
			dp[z][x] += dp[z-1][x];
			dp[z][x] %= mod;
			if (x-arr[z] >= 1)
			dp[z][x] += dp[z-1][x-arr[z]];
			dp[z][x] %= mod;
		}
	}
	ll ans = 0;
	for (int z=1;z<=n;z++){
		ans += dp[z][s];
		ans %= mod;
	}
	cout << ans << endl;
}