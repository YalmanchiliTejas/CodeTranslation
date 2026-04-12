#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 105;

int n;
int H[Maxn];
vector <int> un;
int dp[Maxn][Maxn];
int res;

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	un.push_back(0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &H[i]);
		un.push_back(H[i]);
	}
	sort(un.begin(), un.end());
	un.erase(unique(un.begin(), un.end()), un.end());
	for (int j = 0; j < un.size() && un[j] <= H[0]; j++) {
		int ways = j == 0? 1: 2;
		if (j + 1 < un.size() && un[j + 1] <= H[0]) {
			ways = ll(ways) * (ll(toPower(2, un[j + 1] - un[j]) - (j == 0? 2: 1) + mod)) % mod;
			ways = ll(ways) * ll(toPower(2, H[0] - un[j + 1])) % mod;
		}
		dp[0][j] = ways;
	}
	for (int i = 0; i + 1 < n; i++)
		for (int j = 0; j < un.size() && un[j] <= H[i]; j++) {
			if (un[j] < H[i + 1])
				if (un[j] < H[i]) {
					int ways = dp[i][j];
					if (H[i + 1] > H[i]) ways = ll(ways) * toPower(2, H[i + 1] - H[i]) % mod;
					dp[i + 1][j] = (dp[i + 1][j] + ways) % mod;
				} else {
					for (int k = j; k < un.size() && un[k] <= H[i + 1]; k++) {
						int ways = 2 * dp[i][j] % mod;
						if (k + 1 < un.size() && un[k + 1] <= H[i + 1]) {
							ways = ll(ways) * (ll(toPower(2, un[k + 1] - un[k]) - 1 + mod)) % mod;
							ways = ll(ways) * ll(toPower(2, H[i + 1] - un[k + 1])) % mod;
						}
						dp[i + 1][k] = (dp[i + 1][k] + ways) % mod;
					}
				}
			else {
				int ind = lower_bound(un.begin(), un.end(), H[i + 1]) - un.begin();
				dp[i + 1][ind] = (dp[i + 1][ind] + 2ll * ll(dp[i][j])) % mod;
			}
		}
	for (int j = 0; j < un.size(); j++)
		res = (res + dp[n - 1][j]) % mod;
	printf("%d\n", res);
	return 0;
}