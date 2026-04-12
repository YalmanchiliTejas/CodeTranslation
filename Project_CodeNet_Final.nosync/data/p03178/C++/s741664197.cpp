#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

string k;
int d, n;
int dp[10001][101][2];

int calc(int i, int m, int roof) {
	if (i == n) return (m == 0 ? 1 : 0);
	if (dp[i][m][roof] != -1) return dp[i][m][roof];
	int &x = dp[i][m][roof];
	x = 0;
	if (roof) {
		for (int put = 0; put < k[i] - '0'; put++)
			x = (x + calc(i + 1, (m - put + 10 * d) % d, 0)) % md;
		x = (x + calc(i + 1, (m - (k[i] - '0') + d) % d, 1)) % md;
	}
	else {
		for (int put = 0; put < 10; put++)
			x = (x + calc(i + 1, (m - put + 10 * d) % d, 0)) % md;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> k >> d;
	n = k.size();
	for (int i = 0; i < n; i++) for (int j = 0; j < d; j++)
		dp[i][j][0] = dp[i][j][1] = -1;
	int ans = (calc(0, 0, 1) - 1 + md) % md;
	finish(ans);
}