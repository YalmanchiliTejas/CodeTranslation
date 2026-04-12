#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<18, mod = 1e9 + 7, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n,a[maxn];
ll ans;
map<array<int, 3>, ll> dp;
ll dfs(int i, int b, int l) {
	if(dp.count({i, b, l})) return dp[{i, b, l}];
	if(abs(b) > 3) return -(1ll<<50);
	if(i > n) return (i+b)/2 == n/2 ? 0 : -(1ll<<50);
	if(l == 0) {
		return dp[{i, b, l}] = max(a[i] + dfs(i+1, b+1, 1), dfs(i+1, b-1, 0));
	}
	return dp[{i, b, l}] = dfs(i+1, b-1, 0);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cout << dfs(1, 0, 0);
	return 0;
}
