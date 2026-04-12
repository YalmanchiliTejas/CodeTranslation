#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;


#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
string k;
ll d;
ll dp[10001][101][2], mod = 1e9 + 7;
ll calc(ll pos, ll small, ll rem) {
	if(pos == k.length()) {
		if(rem == 0) {
			return 1;
		}
		return 0;
	}
	if(dp[pos][rem][small] != -1) {
		return dp[pos][rem][small];
	}
	int maxi = k[pos] - '0';
	if(small) {
		maxi = 9;
	}
	int ret = 0;
	for(int i = 0; i <= maxi; i++) {
		int nextSmall = small;
		if(i < maxi) {
			nextSmall = 1;
		}
		ll newRem = (rem + i) % d;
		ret = (ret + calc(pos + 1, nextSmall, newRem)) % mod;
	}
	return dp[pos][rem][small] = ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>d;
    for(int i = 0; i < 10001; i++) {
    	for(int j = 0; j < 101; j++) {
    		dp[i][j][0] = dp[i][j][1] = -1;
    	}
    }
    cout<<((calc(0, 0, 0) - 1)%mod + mod)%mod<<"\n";
}