#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define D(x) cerr << #x << " = " << (x) << '\n'
using ll = long long;
const int maxn = 3123;
ll dp[2][maxn][maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	for(int i = n; i >= 0; --i) {
		for(int j = i; j <= n; ++ j) {
			dp[0][i][j] = max(dp[1][i + 1][j] + a[i], dp[1][i][j - 1] + a[j]);
			dp[1][i][j] = min(dp[0][i + 1][j] - a[i], dp[0][i][j - 1] - a[j]);
		}
	}
	cout << dp[0][1][n] << '\n';
}
