#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;
vector<long long> a;
int n;

long long f(int s, int e) {
	if (s < 1 || e > n)
		return 0;
	if (dp[s][e] == -1) {
		if (((n + 1) - (s + e)) & 1) {
			//second player
			if (s == e)
				dp[s][e] = -a[s];
			else
				dp[s][e] = min(f(s + 1, e) - a[s], f(s, e - 1) - a[e]);
		} else {
			//first player
			if (s == e)
				dp[s][e] = a[s];
			else
				dp[s][e] = max(f(s + 1, e) + a[s], f(s, e - 1) + a[e]);
		}
	}
	return dp[s][e];
}

int main() {
	cin >> n;
	a.resize(n + 1);
	dp.resize(n + 1, vector<long long>(n + 1, -1));
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	cout << f(1, n);

	return 0;
}
