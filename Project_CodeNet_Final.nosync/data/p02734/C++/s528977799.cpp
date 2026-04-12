#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template <typename T> using orderMSet =
//tree <T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef unsigned long long llu;
#define filein freopen("input.txt", "r", stdin)
#define fileout freopen("output.txt", "w", stdout)
#define inf 1000000000000000018
#define mod 998244353
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>

#define MX 3003
ll dp[MX][MX], arr[MX], ans, n, s;

ll f(ll pos, ll rem)
{
	if(rem < 0) return 0;
	if(rem == 0) return n-pos+1;
	if(pos == n) return 0;

	ll &ret = dp[pos][rem];
	if(ret != -1) return ret;

	ll x = f(pos+1, rem);
	ll y = f(pos+1, rem-arr[pos]);

	if(rem == s) ans += ((pos+1)*y)%mod; ans %= mod;
	return ret = (x+y)%mod;
}

int main()
{
	scanf("%lld %lld", &n, &s);

	for(ll i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	memset(dp, -1, sizeof dp);
	f(0, s);

	printf("%lld\n", ans);
}
