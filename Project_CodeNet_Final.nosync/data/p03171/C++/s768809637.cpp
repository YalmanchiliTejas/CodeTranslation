#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll FLAG = LLONG_MIN;

const int MAX = 3000;

ll a[MAX];
ll dp[MAX + 1][MAX + 1][2];

ll calc(int l, int r, bool f = true) {
	if (dp[l][r][f] != FLAG) return dp[l][r][f];
	if (r - l == 0) return dp[l][r][f] = 0;
	if (f) return dp[l][r][f] = max(calc(l, r - 1, false) + a[r - 1], calc(l + 1, r, false) + a[l]);
	return dp[l][r][f] = min(calc(l, r - 1, true) - a[r - 1], calc(l + 1, r, true) - a[l]);
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			dp[i][j][0] = FLAG;
			dp[i][j][1] = FLAG;
		}
	}
	cout << calc(0, N) << endl;
	return 0;
}
