#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, ans;
	cin >> n;
	vector<long long> a(n);
	for (i = 0; i < n; i++) cin >> a[i];

	vector<vector<long long>> dp(n, vector<long long>(n, -(1LL << 60)));

	for (k = 0; k < n; k++) {
		for (i = 0; i + k < n; i++) {
			j = i + k;

			if (k == 0) dp[i][j] = a[i];
			else {
				dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
			}
		}
	}

	ans = dp[0][n - 1];
	cout << ans << "\n";


	return 0;
}


