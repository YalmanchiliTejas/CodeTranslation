#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long

using namespace std;
const int INF = 1e15;
const int MB = 30;
const int MOD = 1e9 + 7;

void solve() {
	int x;
	cin >> x;
	if (x >= 30) cout << "Yes";
	else cout << "No";
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(12);
	srand(time(0));
	int t = 1;
	//int t;
	//cin >> t;
	while (t--) solve();
}