#include<bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define __ cout<<fixed;cout<<setprecision(10);
#define int long long

void solve() {
	int n;
	cin >> n;
	if (n >= 30) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}

int32_t main() {
	_ __
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif

	return 0;
}