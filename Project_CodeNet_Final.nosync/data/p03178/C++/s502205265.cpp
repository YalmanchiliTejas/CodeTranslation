#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 100001;
string k;
int d;
long long dp[N][100][2];
long long calc(int idx, int sum, bool sml) {
	if (idx >= (int)k.size()) {
		if (sum % d == 0)
			return 1;
		return 0;
	}
	long long &ret = dp[idx][sum][sml];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i <= 9; ++i) {
		int num = k[idx] - '0';
		if (!sml && i > num)
			break;
		ret = (ret + calc(idx + 1, (sum + i) % d, sml || (i < num))) % MOD;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k >> d;
	memset(dp, -1, sizeof(dp));
	long long ans = (calc(0, 0, false) + MOD - 1) % MOD;
	cout << ans << endl;
	return 0;
}