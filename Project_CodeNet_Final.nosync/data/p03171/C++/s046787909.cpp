#include <bits/stdc++.h>
#define range(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, b) for (int i = 0; i < (b); i++)
#define ranger(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define repr(i, b) for (int i = (b)-1; i >= 0; i--)
#define all(a) (a).begin(), (a).end()
#define show(x) cerr << #x << " = " << (x) << endl;
#define int long long
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}
template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	rep(i, v.size()) { os << v[i] << (i == v.size() - 1 ? "" : " "); }
	return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S>& p) {
	os << '(' << p.first << ',' << p.second << ')';
	return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
	for (T& x : v) { is >> x; }
	return is;
}

const int INF = 1e18;

int n;
vector<int> a;
int memo[3005][3005];

int dfs(int l, int r, bool t) { // [l,r]
	if (not(l == -1 or r == n + 1)) {
		if (memo[l][r] != -1) return memo[l][r];
	}

	if (t) { // min
		int res = INF;
		if (l + 1 < r) res = min(res, dfs(l + 1, r, t ^ 1) - a[l + 1]);
		if (l < r - 1) res = min(res, dfs(l, r - 1, t ^ 1) - a[r - 1]);
		if (res == INF) res = 0;
		//cout << l << ' ' << r << ' ' << res << endl;
		if (not(l == -1 or r == n + 1)) { return memo[l][r] = res; }
		return res;
	} else { // max
		int res = -INF;
		if (l + 1 < r) res = max(res, dfs(l + 1, r, t ^ 1) + a[l + 1]);
		if (l < r - 1) res = max(res, dfs(l, r - 1, t ^ 1) + a[r - 1]);
		if (res == -INF) res = 0;
		//cout << l << ' ' << r << ' ' << res << endl;
		if (not(l == -1 or r == n + 1)) { return memo[l][r] = res; }
		return res;
	}
}

signed main() {
	int n;
	cin >> n;

	a = vector<int>(n);
	cin >> a;

	rep(i, 3005) rep(j, 3005) memo[i][j] = -1;
	cout << dfs(-1, n, 0) << endl;
}
