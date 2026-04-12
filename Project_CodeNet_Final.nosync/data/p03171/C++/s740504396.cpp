#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int N;
ll dp[3300][3300];
int a[3300];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int w = 1; w <= N; w++) {
		for (int l = 0; w + l <= N; l++) {
			int r = l + w;
			if (w % 2 == N % 2) dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1]);
			else dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1]);
		}
	}
	cout << dp[0][N] << '\n';
	return 0;
}