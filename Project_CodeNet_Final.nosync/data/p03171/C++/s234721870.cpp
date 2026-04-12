#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <string>

#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

long long arr[3005];
long long dp[3005][3005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) dp[i][i] = arr[i];

	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n-k; i++) {
			int j = i + k;
			dp[i][j] = max(arr[j] - dp[i][j-1],
							arr[i] - dp[i+1][j]);
		}
	}

	cout << dp[0][n-1] << endl;

	return 0;
}
