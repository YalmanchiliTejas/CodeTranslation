#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


long long dp[3005][3005];

int main() {
        int n;
		cin >> n;
	    long long a[3005];
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		for (int i = n - 1; i >= 0; i--) {
			bool OK = false;
			for (int j = i; j < n;j++) {
				if (i == j) {
				    dp[i][j] = a[i];
				}
				else{ 
					dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
				}
			}
		}
        cout << dp[0][n - 1] << endl;
		return 0;
}