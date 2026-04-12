#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>numbers;
ll dp[3005][3005][2];
ll solve(int idx, int idy, int turn) {
	if (idx > idy) { return 0; }
	if (dp[idx][idy][turn] != -1) { return dp[idx][idy][turn]; }
	else {
		if (turn == 1) {
			return dp[idx][idy][turn] = min(solve(idx + 1, idy, turn ^ 1), solve(idx, idy - 1, turn ^ 1));
		}
		else {
			return dp[idx][idy][turn] = max(solve(idx + 1, idy, turn ^ 1) + numbers[idx], solve(idx, idy - 1, turn ^ 1) + numbers[idy]);
		}

		
	}
}

int main() {
	ll n,tmp=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll e;
		cin >> e;
		numbers.push_back(e);
		tmp += e;
	}
	memset(dp, -1, sizeof(dp));
	ll sum1 = solve(0, numbers.size() - 1, 0);
	ll sum2 = abs(tmp - sum1);
	cout << sum1-sum2 << "\n";
	
	return 0;
}