#include <bits/stdc++.h>
using namespace std;
#define EQ(x, y) (abs(x - y) < 1e-9)
typedef long long ll;

ll dp[3010][3010];
int arr[3010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> arr[i];
	}

	for (int i = 1; i <= n; ++i){
		dp[i][i] = n & 1 ? arr[i] : -arr[i];
	}

	for (int l = n; l >= 1; --l){
		for (int r = l; r <= n; ++r){
			if ((n - l + r) & 1){ //positive
				dp[l][r] = max(arr[l] + dp[l + 1][r], arr[r] + dp[l][r - 1]);
			}
			else { //negative
				dp[l][r] = min(-arr[l] + dp[l + 1][r], -arr[r] + dp[l][r - 1]);
			}
		}
	}
	
	cout << dp[1][n] << '\n';
	return 0;
}