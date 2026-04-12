#include <bits/stdc++.h>
using namespace std;

int n;
int a[3055];

long long dp[3055][3055][2];

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			for (int player = 0; player < 2; player++) {
				long long &res = dp[i][j][player];
				
				if (i == j) {
					if (player == 0) res = a[i];
					else res = -a[i];
					continue;
				}
				
				if (player == 0) {
					// maximize
					
					res = max(dp[i + 1][j][1] + a[i], dp[i][j - 1][1] + a[j]);
				} else {
					res = min(dp[i + 1][j][0] - a[i], dp[i][j - 1][0] - a[j]);
				}
			}
		}
	}
	
	cout << dp[0][n - 1][0];
}
