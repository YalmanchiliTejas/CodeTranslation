#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int n, S;
vector<ll> a;
vector<vector<int>> dp;

ll rec(int i, int s) {
	if (s < 0) return 0;
	if (s == 0) return n - i + 1;
	if (i == n) return 0;
	if (dp[i][s] != -1) return dp[i][s];
	if (s == S) return dp[i][s] = (((rec(i + 1, s) + rec(i + 1, s - a[i]) * ll(i+1)) % MOD)) % MOD;
	return dp[i][s] = (((rec(i + 1, s) + rec(i + 1, s - a[i])) % MOD)) % MOD;
}

int main() {
	cin.sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> S;
	a = vector<ll>(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	dp = vector<vector<int>>(n, vector<int>(S+1, -1));
	cout << rec(0, S) << endl;
	return 0;
}