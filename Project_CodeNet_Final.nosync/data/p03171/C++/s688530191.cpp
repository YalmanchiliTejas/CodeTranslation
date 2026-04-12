#include<stdio.h>
#include<utility>
using namespace std;
typedef long long int LL;

LL dp[3001][3001][2];

class solution {
private:
	LL ar[3001];
	int n;
	LL serc(int l, int r, int m) {
		if (l > r) return 0;
		if (m == 0) {
			if (dp[l][r][m] != (1ll << 63)) return dp[l][r][m];
			dp[l][r][m] = max(dp[l][r][m], ar[r] + serc(l, r - 1, m ^ 1));
			dp[l][r][m] = max(dp[l][r][m], ar[l] + serc(l + 1, r, m ^ 1));
		}
		else {
			if (dp[l][r][m] != (~(1ll << 63))) return dp[l][r][m];
			dp[l][r][m] = min(dp[l][r][m], serc(l, r - 1, m ^ 1) - ar[r]);
			dp[l][r][m] = min(dp[l][r][m], serc(l + 1, r, m ^ 1) - ar[l]);
		}
		return dp[l][r][m];
	}
	LL max(LL a, LL b) {
		if (a > b) return a;
		return b;
	}
	LL min(LL a, LL b) {
		if (a < b) return a;
		return b;
	}
	void reset() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j][1] = ~(1ll << 63);
				dp[i][j][0] = (1ll << 63);
			}
		}
	}
public:
	solution() {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &ar[i]);
		}
		reset();
		printf("%lld\n", serc(0, n - 1, 0));
	}
};

#ifndef L0C4L
int main() {
	solution();
	return 0;
}
#endif