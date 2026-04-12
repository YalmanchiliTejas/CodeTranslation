#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 100, D = 110, MOD = 1000 * 1000 * 1000 + 7;

int d, dp[2][N][D];// type, len, mod
string s;

int sum(int a, int b) {
	a += b;
	if(a < 0)
		a += MOD;
	else if(a >= MOD)
		a -= MOD;
	return a;
}

void _sum(int &a, int b) {
	a = sum(a, b);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> s >> d;
	s = "#" + s;
	dp[1][0][0] = 1;
	for (int i = 0; i < s.length() - 1; i++)
		for (int j = 0; j < d; j++)
			for (int k = 0; k <= 9; k++) {
				int digit = s[i + 1] - '0', mod = (j + k) % d;
				_sum(dp[0][i + 1][mod], dp[0][i][j]);
				if(k < digit)
					_sum(dp[0][i + 1][mod], dp[1][i][j]);
				else if(k == digit)
					_sum(dp[1][i + 1][mod], dp[1][i][j]);
			}
	cout << sum(dp[0][s.length() - 1][0], dp[1][s.length() - 1][0] - 1);
	return 0;
}