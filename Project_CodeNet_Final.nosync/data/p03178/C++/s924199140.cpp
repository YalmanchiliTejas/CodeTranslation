#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
int n, D;
vector<int> num;
vector<vector<vector<ll>>> dp;

ll recursion(int pos, int sum, bool flag) {
	if (pos == n) {
		if (sum % D) {
			return 0;
		}
		return 1;
	}
	if (dp[pos][sum][flag] != -1) {
		return dp[pos][sum][flag];
	}
	ll res = 0;
	int limit = 9;
	if (flag) {
		limit = num[pos];
	}
	for (int i = 0; i <= limit; i++) {
		if (i == num[pos]) {
			res = (res + recursion(pos + 1, (sum + i) % D, flag)) % mod;
		} else {
			res = (res + recursion(pos + 1, (sum + i) % D, 0)) % mod;
		}
	}
	return dp[pos][sum][flag] = res;
}

int main() {
	ios_base::sync_with_stdio(false);

	string K;
	cin >> K >> D;
	n = K.length();
	for (auto it : K) {
		num.push_back(it - '0');
	}
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		dp[i].resize(D, vector<ll> (2, -1));
	}
	ll ans = recursion(0, 0, 1);
	ans--;
	if (ans == -1) {
		ans = mod - 1;
	}
	cout << ans;

	return 0;
}