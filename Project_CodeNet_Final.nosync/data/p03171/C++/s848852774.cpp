#include <bits/stdc++.h>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

using namespace std;
using namespace boost;
using namespace boost::algorithm;

int main() {
	int n;
	vector<long long> s = {};
	long long temp_s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp_s;
		s.push_back(temp_s);	
	}

	vector<vector<long long>> dp;
	dp.assign(n, vector<long long>(n,0));

	for (int i = 0; i < n; i++) {
		dp[i][i] = s[i];
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j <= n - 1; j++) {
			auto a = s[i] - dp[i + 1][j];
			auto b = s[j] - dp[i][j - 1];
			if (a > b) {
				dp[i][j] = a;
			} else {
				dp[i][j] = b;
			}
		}
	}

	cout << dp[0][n - 1];

	return 0;
}
