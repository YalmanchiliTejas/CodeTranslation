#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[51], ub[51];

void init() {
	dp[0] = 1; ub[0] = 1;
	for (int i = 0; i < 50; i++) {
		dp[i + 1] = dp[i] * 2 + 1;
		ub[i + 1] = ub[i] * 2 + 3;
	}
}

ll calc(ll n, ll x) {
	if (x <= 0) return 0;
	if (n == 0) return 1;
	if (x == ub[n - 1] + 1) return dp[n - 1];
	if (x >= ub[n - 1] + 1) return dp[n - 1] + 1 + calc(n - 1, x - ub[n - 1] - 2);
	return calc(n - 1, x - 1);
}

int main()
{
	init();
	ll N, X;
	cin >> N >> X;
	cout << calc(N, X) << endl;
	return 0;
}
