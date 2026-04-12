#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 3000;
ll dp[N][N];
ll vals[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> vals[i];

	for (int len = 1; len <= n; ++len) {
		for (int a = 0; a+len <= n; ++a) {
			int b = a + len - 1;
			if (a == b) dp[a][b] = vals[a];
			else dp[a][b] = max(vals[b] - dp[a][b-1], vals[a] - dp[a+1][b]);
		}
	}
	cout << dp[0][n-1] << '\n';
}
