#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long int64;

int n;
vector<int64> a;
map<pair<int, int>, int64> dp;
int64 solve(int pos, int cnt) {
	if (pos >= n) {
		if (cnt == n / 2) return 0;
		else return -1e15;
	}
	if (cnt == n / 2) return 0;
	if ((n - pos + 1) / 2 < (n / 2 - cnt)) return -1e15;
	if (dp.find({pos, cnt}) != dp.end()) return dp[{pos, cnt}];
	return dp[{pos, cnt}] = max(a[pos] + solve(pos + 2, cnt + 1), solve(pos + 1, cnt));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	a = vector<int64> (n);
	for (int i = 0; i < n; ++ i) {
		cin >> a[i];
	}
	cout << solve(0, 0);
}