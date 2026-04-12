/*
     Author:Raghav Bansal
     IIIT Una
                  */
#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define BOLT ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define X first
#define Y second
#define endl "\n"
using namespace std;
const int N = 2e5 + 1;
int dp[N][4];
int vis[N][4];
vector<int> v;
int n;
int dfs(int x, int state) {
	if (x <= 0)
		return 0;
	if (vis[x][state])
		return dp[x][state];
	vis[x][state] = 1;
	int &an = dp[x][state];
	if (state == 0) {
		an = v[x] + max({dfs(x - 2, 0), dfs(x - 3, 1), dfs(x - 4, 2)});
	} else if (state == 1) {
		an = v[x] + max(dfs(x - 2, 1), dfs(x - 3, 2));
	} else {
		an = v[x] + dfs(x - 2, 2);
	}
	return an;
}
void solve() {
	cin >> n;
	v.pb(0);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.pb(x);
	}
	if (n & 1) {
		cout << max({dfs(n, 0), dfs(n - 1, 1), dfs(n - 2, 2)}) << endl;
	} else {
		cout << max({dfs(n, 1), dfs(n - 1, 2)}) << endl;
	}
}
int32_t main() {
	BOLT;
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
}