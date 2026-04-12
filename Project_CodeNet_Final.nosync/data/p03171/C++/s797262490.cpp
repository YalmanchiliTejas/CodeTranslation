
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

const int N = 3001, M = N;
//=======================

vi g[N];
int dp[N][N][2];

void solve() {
	int i, j, n, m;
	cin >> n;
	int a[n];
	fo(i, n) cin >> a[i];
	int prefix[n];
	fo(i, n) {
		prefix[i] = a[i];
		if (i) prefix[i] += prefix[i - 1];
	}
	//y=(prefix[j]-prefix[i-x]);
	//dp[i][j][p]=max(a[i]+(y-dp[i+1][j][p^]),a[j]+(y-dp[i][j-1][p^]))
	int len = 0;
	fo(i, n + 1) {
		dp[i][i][0] = a[i];
		dp[i][i][1] = a[i];
	}
	Fo(len, 1, n + 1) {
		for (int i = 0; i + len < n; i++) {
			j = i + len;
			int y = prefix[j];
			y += (i - 1 >= 0) ? -prefix[i - 1] : 0;
			// deb2(i, j); deb(y);
			dp[i][j][0] = max((y - dp[i + 1][j][1]), (y - dp[i][j - 1][1]));
			dp[i][j][1] = max((y - dp[i + 1][j][0]), (y - dp[i][j - 1][0]));
			// deb2(dp[i][j][0], dp[i][j][1]);
		}
	}
	cout << 2 * dp[0][n - 1][0] - prefix[n - 1] << "\n";
}

int32_t main()
{
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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