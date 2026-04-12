 // In the name of GOD
 
#include <bits/stdc++.h>
#define ll long long
#define pp pair <int, int>
using namespace std;
const int N = 3e3 + 10, MOD = 1e9 + 7;
const ll INF = 1e18;
vector <int> a(N);
ll dp[N][N];
bool vis[N][N] = {0};

ll f(int l, int r) {
	if(vis[l][r])	return dp[l][r];

	if (l == r)	return a[l];

	ll t1 = a[l] - f(l + 1, r);
	ll t2 = a[r] - f(l, r - 1);
	dp[l][r] = max (t1, t2);
	vis[l][r] = true;
	return dp[l][r];
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << f(0, n - 1);
}

int main () {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int tt = 1;
    // cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) {
        solve();
    }
}                                  