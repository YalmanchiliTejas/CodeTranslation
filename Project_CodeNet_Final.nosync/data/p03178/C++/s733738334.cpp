#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = (int)1e4 + 7;
const int mod = (int)1e9 + 7;

int dp[N][100][2];
int n, d;
int ans = 0;
string k;

int add(int a, int b) {
	return (a + b) % mod;
}

int go(int pos, int sum, int pref) {
	if (pos == n) return sum == 0;
	int &res = dp[pos][sum][pref];
	if (res != -1) return res;
	res = 0;
	if (pref) {
		for (int i = 0; i < min(10, k[pos] - '0' + 1); i++) {
			res = add(res, go(pos + 1, (sum + i) % d, (i == k[pos] - '0')));
		}
	} else {
		for (int i = 0; i < 10; i++) {
			res = add(res, go(pos + 1, (sum + i) % d, 0));
		}
	}
	return res;
}

main() {
	memset(dp, -1, sizeof dp);
	cin >> k;
	scanf("%d", &d);
	n = k.size();
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 1; j < k[i - 1] - '0' + 1; j++) {
				ans = add(ans, go(i, j % d, (j == k[i - 1] - '0')));
				//cout << go(i, j % d, (j == k[i - 1] - '0')) << ' ' << i << ' ' << j << ' ' << (j == k[i - 1] - '0') << endl;
			}
		} else {
			for (int j = 1; j < 10; j++) {
				ans = add(ans, go(i, j % d, 0));
				//cout << go(i, j % d, 0) << ' ' << i << ' ' << j << ' ' << 0 << endl;
			}
		}
	}
	printf("%d", ans);
}
