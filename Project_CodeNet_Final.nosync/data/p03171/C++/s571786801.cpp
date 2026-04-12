#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[3003][3003];
ll n, k, arr[3003], sum = 0;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (int l = n - 1; l >= 0; l--) {
		for (int r = l; r <= n - 1; r++) {
			int x = r - l + 1, turn;
			if (((x & 1) && (n & 1)) || ((n % 2 == 0) && (x % 2 == 0))) {
				turn = 0;
			}
			else {
				turn = 1;
			}
			
			if (turn == 0) {
				if (l == r) {
					dp[l][r] = arr[r];
					continue;
				}
				dp[l][r] = max(arr[l] + dp[l + 1][r], arr[r] + dp[l][r - 1]);
			}
			else {
				if (l == r) {
					dp[l][r] = 0;
					continue;
				}
				dp[l][r] = min (dp[l + 1][r], dp[l][r - 1]);
			}
		}
	}

	ll x = dp[0][n - 1];
	ll y = sum - x;
	ll ans = x - y; // 2x - sum
	cout << ans;


	return 0;
}
