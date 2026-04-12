#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;

const int MAXN = 3003;
long long dp[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	for (int i = 0; i < n; ++i) dp[i][i] = a[i];
	for (int d = 1; d < n; d++) {
		for (int i = 0; i + d < n; ++i) {
			dp[i][i+d] = max(a[i] - dp[i+1][i+d], a[i+d] - dp[i][i+d-1]);
		}
	}
	
	//~ for (int i = 0; i < n; i++) {
		//~ for (int j = 0; j < n; j++) cout << dp[i][j] << ' ';
		//~ cout << '\n';
	//~ }
	cout << dp[0][n-1] << endl;
}
