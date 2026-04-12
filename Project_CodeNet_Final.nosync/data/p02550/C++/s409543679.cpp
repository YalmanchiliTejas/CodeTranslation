/**
 *  author: nayakashutosh9
 *	[2020-09-19 17:25]
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define endl '\n'
#define mod 1000000007
#define modd 998244353
#define inf 1e18
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/


void solve() {
	int n, x, m; cin >> n >> x >> m;
	int ans = x, cur = x;
	map<int, pii> vis;
	for (int i = 2; i <= n; i++) {
		cur = (cur * cur) % m;
		cur %= m;
		ans += cur;
		if (vis.count(cur)) {
			int st = i - vis[cur].ff;
			int val = ans - vis[cur].ss;
			int left = n - i;
			ans += (left / st) * val;
			int rem = left % st;
			while (rem > 0) {
				cur = (cur * cur) % m;
				cur %= m;
				ans += cur;
				rem--;
			}
			break;
		}
		else vis[cur] = {i, ans};
		if (cur == 0) break;
	}
	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T; cin.ignore();
	for (int i = 1; i <= T; i++) {
		// cout << "Case #" << i << ": ";
		// clock_t start = clock();
		solve();
		// clock_t end = clock();
		// cout << (end-start) << endl;
		//print execution time in ms
	}

	return 0;
}