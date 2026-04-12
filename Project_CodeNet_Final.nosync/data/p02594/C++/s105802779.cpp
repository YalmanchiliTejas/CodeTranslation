# include <bits/stdc++.h>
# define int long long
# define endl "\n"
using namespace std;

void solve() {

	int x;
	cin >> x;
	if (x >= 30) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

# ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
# endif

	// int t;
	// cin >> t;
	// while (t--)
	solve();

	return 0;
}