#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// p : {0, 1} : {Taro, Jiro}
// find X if both plays optimally

ll dp[3001][3001][2], v[3001];

ll recur(int l, int r, bool p) {
	if(l > r)
		return 0;

	ll &ret = dp[l][r][p];
	if(ret != -1)
		return ret;

	if(p == 0)
		return ret = max(recur(l+1, r, not p) + v[l], recur(l, r-1, not p) + v[r]);
	return ret = min(recur(l+1, r, not p), recur(l, r-1, not p));
}


int main() {
	int n;
	cin >> n;

	ll sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}

	memset(dp, -1, sizeof dp);
	ll x = recur(0, n-1, 0);
	ll y = sum - x;
	cout << x-y << endl;
	return 0;
}