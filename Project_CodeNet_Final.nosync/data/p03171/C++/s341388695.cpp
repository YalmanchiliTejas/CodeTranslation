#include <bits/stdc++.h>

using namespace std;

long long n, a[3010];
pair<long long, long long> memo[3010][3010];

pair<long long, long long> dp(long long l, long long r) {
	if(l > r) {
		return make_pair(0, 0);
	}
	if(memo[l][r] != make_pair((long long)-1, (long long)-1)) {
		return memo[l][r];
	}
	memo[l][r] = make_pair(0, 0);
	if((n - (r - l + 1)) % 2 == 0) {
		pair<long long, long long> ret, temp;
		ret = make_pair(0, 0);
		temp = dp(l + 1, r);
		ret.first = ret.first + a[l] + temp.first;
		ret.second = ret.second + temp.second;
		memo[l][r] = ret;
		ret = make_pair(0, 0);
		temp = dp(l, r - 1);
		ret.first = ret.first + a[r] + temp.first;
		ret.second = ret.second + temp.second;
		if(ret.first - ret.second > memo[l][r].first - memo[l][r].second) {
			memo[l][r] = ret;
		}
	}
	else {
		pair<long long, long long> ret, temp;
		ret = make_pair(0, 0);
		temp = dp(l + 1, r);
		ret.first = ret.first + temp.first;
		ret.second = ret.second + a[l] + temp.second;
		memo[l][r] = ret;
		ret = make_pair(0, 0);
		temp = dp(l, r - 1);
		ret.first = ret.first + temp.first;
		ret.second = ret.second + a[r] + temp.second;
		if(ret.first - ret.second < memo[l][r].first - memo[l][r].second) {
			memo[l][r] = ret;
		}
	}
	return memo[l][r];
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for(long long i = 0; i < 3010; i++) {
		for(long long j = 0; j < 3010; j++) {
			memo[i][j] = make_pair(-1, -1);
		}
	}
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	pair<long long, long long> ans = dp(1, n);
	cout << ans.first - ans.second << endl;
}