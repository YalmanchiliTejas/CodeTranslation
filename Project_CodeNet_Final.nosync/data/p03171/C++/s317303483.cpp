/*
                                                                                                                                               
8b        d8                           888888888888                                             88b           d88                  ad88888ba   
 Y8,    ,8P                                 88                                        ,d        888b         d888                 d8"     "8b  
  Y8,  ,8P                                  88                                        88        88`8b       d8'88                 ""      a8P  
   "8aa8"  ,adPPYba,   88       88          88  8b,dPPYba,  88       88  ,adPPYba,  MM88MMM     88 `8b     d8' 88   ,adPPYba,          ,a8P"   
    `88'  a8"     "8a  88       88          88  88P'   "Y8  88       88  I8[    ""    88        88  `8b   d8'  88  a8P_____88         d8"      
     88   8b       d8  88       88          88  88          88       88   `"Y8ba,     88        88   `8b d8'   88  8PP"""""""         ""       
     88   "8a,   ,a8"  "8a,   ,a88          88  88          "8a,   ,a88  aa    ]8I    88,       88    `888'    88  "8b,   ,aa         aa       
     88    `"YbbdP"'    `"YbbdP'Y8          88  88           `"YbbdP'Y8  `"YbbdP"'    "Y888     88     `8'     88   `"Ybbd8"'         88       
                                                                                                                                               
*/
#include <bits/stdc++.h>
using namespace std;

int n;
long long total, a[3010], dp[3010][3010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i][i] = a[i];
		total += a[i];
	}

	for (int len = 1; len < n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len;
			long long x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
			long long y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0;
			long long z = (i <= (j - 2)) ? dp[i][j - 2] : 0;

			dp[i][j] = max(a[i] + min(x, y), a[j] + min(y, z));
		}
	}

	cout << 2 * dp[0][n - 1] - total << '\n';

	return 0;
} 