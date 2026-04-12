#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200005;

string n;
int k;

ll dp[111][4][2];
ll f(int i, int j, int less) {
	if(j > k) return 0;
	if(i == (int)n.size()) return j == k;
	ll &ans = dp[i][j][less];
	if(~ans) return ans;
	ans = 0;
	if(less) {
		return ans = f(i + 1, j, less) + f(i + 1, j + 1, less) * 9;
	}
	else {
		int dig = int(n[i] - '0');
		for(int d = 0; d <= dig; d++) {
			ans += f(i + 1, j + !!d, d < dig);
		}
	}
	return ans;
}

int main() {
	memset(dp, -1, sizeof dp);

	cin >> n >> k;
	cout << f(0, 0, 0) << endl;
}
