#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int n;
string s;
bool solve(int p, int q) {
	vector<int> a(n);
	a[0] = p, a[1] = q;
	repl(i, 1, n - 1) {
		if (a[i] == 1) {
			if (s[i] == 'o')
				a[i + 1] = 1 - a[i - 1];
			else
				a[i + 1] = a[i - 1];
		} else {
			if (s[i] == 'o')
				a[i + 1] = a[i - 1];
			else
				a[i + 1] = 1 - a[i - 1];
		}
	}
	if (a[n - 1] == 1) {
		if (s[n - 1] == 'o' and a[n - 2] == a[0]) return false;
		if (s[n - 1] == 'x' and a[n - 2] != a[0]) return false;
	} else {
		if (s[n - 1] == 'o' and a[n - 2] != a[0]) return false;
		if (s[n - 1] == 'x' and a[n - 2] == a[0]) return false;
	}
	if (a[0] == 1) {
		if (s[0] == 'o' and a[n - 1] == a[1]) return false;
		if (s[0] == 'x' and a[n - 1] != a[1]) return false;
	} else {
		if (s[0] == 'o' and a[n - 1] != a[1]) return false;
		if (s[0] == 'x' and a[n - 1] == a[1]) return false;
	}
	rep(i, n) {
		if (a[i] == 0)
			cout << 'S';
		else
			cout << 'W';
	}
	cout << endl;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	rep(i, 2) rep(j, 2) {
		if (solve(i, j)) return 0;
	}
	cout << -1 << endl;
	return 0;
}