#include <bits/stdc++.h>
typedef long long ll;
#define MX 3000
#define PB push_back
ll MOD = 1e9 + 7;
using namespace std;
ll dp[MX + 5][MX + 5];
ll cum[MX + 3];
int arr[MX + 1];
int main() {
	int n, k;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> arr[i], cum[i] = arr[i] + cum[i - 1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n - i + 1; ++j) {
			dp[i][j] = max(arr[j] + cum[i + j - 1] - cum[j] - dp[i - 1][j + 1], arr[i + j - 1] + cum[i + j - 2] - cum[j - 1] - dp[i - 1][j]);
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	cout << 2 * dp[n][1] - cum[n] << endl;
}