/*
    JAI JAGANNATH!
*/
//@Author : zanj0
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<lli,lli>
#define vi              vector<lli>
#define mii             map<lli,lli>
#define pqb             priority_queue<lli>
#define pqs             priority_queue<lli,vi,greater<lli> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            lli x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void zanj0()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
lli n;
unordered_map < lli, unordered_map <lli, lli> > dp;
lli help(lli idx, lli k, vi& v) {
	if (k == 0) return 0;
	if (idx >= n) return -inf;
	int len = n - idx + 1;
	if (k  * 2 > len) return -inf;
	if (dp.count(idx) && dp[idx].count(k)) return dp[idx][k];
	lli ret ;
	ret = max(help(idx + 1, k, v), v[idx] + help(idx + 2, k - 1, v));

	return dp[idx][k] = ret;
}
void solve() {

	cin >> n;
	vi v(n);
	for (lli i = 0; i < n; i++) cin >> v[i];
	dp.clear();
	cout << help(0, n / 2, v) << endl;
}
int main()
{
	zanj0();
	solve();
	return 0;
}