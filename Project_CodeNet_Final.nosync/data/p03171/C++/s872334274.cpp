#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double lld;

vector<ll> a;
const int maxn = 3001;
pair<bool, pair<ll, ll>> dp[maxn][maxn][2];

pair<ll, ll> solve(int x, int y, bool first) {
	if(x > y) {
		return make_pair(0, 0);
	}


	if(x == y) {
		if (first) {
			return make_pair(a[x], 0);	
		} else {
			return make_pair(0, a[x]);
		}
	}
	if(dp[x][y][first].first) return dp[x][y][first].second;

	// a[x]
	pair<ll, ll> ans;
	auto u = solve(x + 1, y, !first);
	auto v = solve(x, y - 1, !first);
	if(first) {
		ll ud = a[x] + u.first - u.second;
		ll vd = a[y] + v.first - v.second;
		if(ud > vd) { ans.first = a[x] + u.first; ans.second = u.second;}
		else { ans.first = a[y] + v.first; ans.second = v.second;}
	} else {
		ll ud = u.first - (u.second + a[x]);
		ll vd = v.first - (v.second + a[y]);
		if(ud < vd) {ans.first = u.first; ans.second = u.second + a[x];}
		else {ans.first = v.first; ans.second = v.second + a[y];}
	}
	dp[x][y][first].first = true; dp[x][y][first].second = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	a.resize(n, 0);
	for(int i = 0; i < n; i++) cin >> a[i];

	auto ans = solve(0, n - 1, true);
	cout << ans.first - ans.second << endl;
}