#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[3010];
ll dp[3010][3010] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t != 0) {
        int n;
        ll total = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            total += arr[i];
        }
        for(int i = 1; i <= n; i++) {
            dp[i][i] = arr[i];
        }
        for(int i = 1; i <= n-1; i++) {
            dp[i][i+1] = max(arr[i], arr[i+1]);
        }

        for(int len = 3; len <= n; len++) {
            for(int i = 1; i <= n-len+1; i++) {
                int j = i + len - 1;

                dp[i][j] = max(arr[i] + min(dp[i+1][j-1], dp[i+2][j]), arr[j] + min(dp[i+1][j-1], dp[i][j-2]));
            }
        }
        // cout << "\n";
        // for(int i = 1; i <= n; i++) {
        //     for(int j = 1; j <= n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        cout << 2*dp[1][n] - total << "\n";
	    t--;
	}
	return 0;
}
