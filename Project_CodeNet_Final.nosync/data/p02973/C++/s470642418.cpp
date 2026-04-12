#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void nibutan(vector<int> &dp, int le,int ri, int c) {
	if (ri - le==1) {
		dp[ri] = c;
		return;
	}
	if (dp[(ri+le) / 2] < c) {
		nibutan(dp, le, (le + ri) / 2, c);
	}
	else {
		nibutan(dp, (le + ri) / 2, ri, c);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> da(n);
	for (int i = 0;i < n;i++) {
		cin >> da[i];
	}
	vector<int> dp(1);
	dp[0] = da[0];
	int ans = 1;
	for (int i = 1;i < n;i++) {
		if (dp[ans - 1] >= da[i]) {
			dp.push_back(da[i]);
			ans++;
		}
		else {
			nibutan(dp, -1, ans-1, da[i]);
		}
	}
	cout << ans << endl;
}