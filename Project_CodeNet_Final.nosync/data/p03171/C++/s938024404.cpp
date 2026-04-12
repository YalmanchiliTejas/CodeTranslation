#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
 
#define int long long 
#define pb push_back
#define all(s) s.begin(),s.end()
#define pii pair<int,int>
#define fr first
#define sc second
#define bst ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;

using namespace std;

const int N = 3010, mod = 1e9 + 7, inf = 1e18 + 7, logn = 23;
const double pi = acos(-1);

int a[N], dp[N][N], vis[N][N];

void rec(int l, int r, int who = 0) {
	if(l > r) {
		return;
	}
	if(vis[l][r]) return;
	vis[l][r] = 1;

	rec(l + 1, r, 1 - who);
	rec(l, r - 1, 1 - who);

	if(l == r) {
		dp[l][r] = pow(-1, who) * a[l];
		return;
	}

	if(who) {
		dp[l][r] = inf;
		dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r]);
	} else {
		dp[l][r] = 0;
		dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r]);
	}
}
// 0 -first   1 - second
void solve() {
	//soln
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	rec(1, n);

	cout << dp[1][n];
}
main() {
	bst;
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
}
