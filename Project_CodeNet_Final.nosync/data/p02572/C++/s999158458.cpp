#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define forn(i,n) for(int i=0;i<n;i++)
#define mod  1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

void solve() {

	int n; cin >> n;
	int a[n];
	vector<int>b(n + 1, 0);

	forn(i, n) {
		cin >> a[i];
		b[i + 1] = b[i] + a[i];
	}
	// for (auto x : b)cout << x << endl;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int s = (b[n] - b[i + 1]) % mod;
		ans = (ans + ((a[i] % mod) * (s % mod)) % mod) % mod;
	}

	cout << ans << endl;


}

int32_t main() {

	fastio;

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	// int t; cin >> t;/
	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}