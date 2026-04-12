#include <bits/stdc++.h>
using namespace std;

int64_t a[63][100010];
int64_t sum[63][100010];

int main() {
	int64_t n, x, m; cin >> n >> x >> m;
	for(int64_t i = 0; i < m; ++i) {
		a[0][i] = (i * i) % m;
		sum[0][i] = (i * i) % m;
	}
	for(int64_t i = 0; i < 60; ++i) {
		for(int64_t j = 0; j < m; ++j) {
			a[i + 1][j] = a[i][a[i][j]];
			sum[i + 1][j] = sum[i][j] + sum[i][a[i][j]];
		}
	}
	int now = x;
	int64_t ans = x;
	--n;
	for(int64_t i = 0; i < 60; ++i) {
		if(n >> i & 1) {
			ans += sum[i][now];
			now = a[i][now];
		}
	}
	cout << ans << '\n';
	return 0;
}
