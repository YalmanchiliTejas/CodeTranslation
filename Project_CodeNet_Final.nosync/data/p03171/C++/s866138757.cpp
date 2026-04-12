#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
using namespace std;

typedef long long ll;

ll a[3005];
ll dp[3005][3005];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int w = 1; w <= n; w++) {
		for (int i = 0; i + w <= n; i++) {
			if (w % 2 == n % 2) dp[i][i + w] = max(dp[i + 1][i + w] + a[i], dp[i][i + w - 1] + a[i + w - 1]);
			else dp[i][i + w] = min(dp[i + 1][i + w] - a[i], dp[i][i + w - 1] - a[i + w - 1]);
		}
	}
	cout << dp[0][n] << endl;
	return 0;
}