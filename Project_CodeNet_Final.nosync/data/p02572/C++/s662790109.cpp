
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define fo(i,n)         for(i=0;i<n;i++)
#define Fo(i,k,n)       for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int N = 3e5, M = N;
//=======================

vi g[N];

void solve() {
	int i, j, n, m;
	cin >> n;
	int a[n];
	fo(i, n) cin >> a[i];
	int prefix_s[n];
	fo(i, n) {
		prefix_s[i] = a[i] % mod;
		if (i != 0) prefix_s[i] = (prefix_s[i] % mod + prefix_s[i - 1] % mod) % mod;
	}
	int ans = 0;
	Fo(i, 1, n) {
		// deb2(i, ans);
		ans = ((ans % mod) + ((a[i] % mod) * (prefix_s[i - 1] % mod)) % mod) % mod;
		// ans += a[i] * prefix_s[i - 1];
		// deb2(i, ans);

	}
	cout << ans << "\n";
}

int32_t main()
{
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	solve();
	return 0;
}

void ipgraph(int n, int m) {
	int i, u, v;
	while (m--) {
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par) {
	for (int v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
	}
}