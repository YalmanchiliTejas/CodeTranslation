#include <bits/stdc++.h>
#define sz(a) (int)a.size()
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;
ll dp[10000][100][2];
int d;
string k;
ll f(int currPos, int currSum, int isSmaller) {
	if(currPos == k.size()) {
		return currSum == 0;
	}
	ll &ret = dp[currPos][currSum][isSmaller];
	if(ret != -1) return ret;
	int limit = 9;
	if(!isSmaller) limit = k[currPos] - '0';
	ll ans = 0;
	for(int digit = 0; digit <= limit; ++digit) {
		int newCurrSum = (currSum + digit) % d;
		int newIsSmaller = isSmaller;
		if(isSmaller == 0 && digit < limit) newIsSmaller = 1;
		ans += f(currPos + 1, newCurrSum, newIsSmaller);
		ans %= MOD;
	}
	return ret = ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	memset(dp, -1, sizeof dp);
	cin >> k >> d;
	cout << (f(0, 0, 0) + MOD - 1) % MOD;
	return 0;
}