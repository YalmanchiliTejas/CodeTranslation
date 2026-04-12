#include "bits/stdc++.h"
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int64_t> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}

	int64_t ans = 0;

	// nが２～４は例外
	if (n == 2) {
		ans = max(a.at(0), a.at(1));
		cout << ans << endl;
		return 0;
	}
	if (n == 3) {
		ans = max(max(a.at(0), a.at(1)), a.at(2));
		cout << ans << endl;
		return 0;
	}
	if (n == 4) {
		ans = max(max(a.at(0) + a.at(2), a.at(0) + a.at(3)), a.at(1) + a.at(3));
		cout << ans << endl;
		return 0;
	}

	// それ以外
	vector<map<int, int64_t>> dp(n);
	map<int, int64_t> dp0;
	dp0[1] = a.at(0);
	dp.at(0) = dp0;
	map<int, int64_t> dp1;
	dp1[1] = max(a.at(0), a.at(1));
	dp.at(1) = dp1;
	map<int, int64_t> dp2;
	dp2[1] = max(dp1.at(1), a.at(2));
	dp2[2] = a.at(0) + a.at(2);
	dp.at(2) = dp2;
	map<int, int64_t> dp3;
	dp3[1] = max(dp2.at(1), a.at(3));
	dp3[2] = max(max(dp2.at(2), a.at(0) + a.at(3)), a.at(1) + a.at(3));
	dp.at(3) = dp3;

	for (int i = 4; i < n; i++) {
		map<int, int64_t> dpi;
		int num = (i + 1) / 2;
		if (i % 2 == 0) {
			// 奇数個の時
			if (i != 4) {
				dpi[num - 1] = max(dp.at(i - 2).at(num - 2) + a.at(i), dp.at(i - 1).at(num - 1));
			} else {
				dpi[num - 1] = max(dp.at(i - 1).at(1), a.at(i));
			}
			dpi[num] = max(dp.at(i - 2).at(num - 1) + a.at(i), dp.at(i - 1).at(num));
			dpi[num + 1] = dp.at(i - 2).at(num) + a.at(i);
			dp.at(i) = dpi;
		} else {
			// 偶数個の時
			dpi[num - 1] = max(dp.at(i - 2).at(num - 2) + a.at(i), dp.at(i - 1).at(num - 1));
			dpi[num] = max(dp.at(i - 2).at(num - 1) + a.at(i), dp.at(i - 1).at(num));
			dp.at(i) = dpi;
		}
	}

	ans = dp.at(n - 1).at(n / 2);
	cout << ans << endl;
}