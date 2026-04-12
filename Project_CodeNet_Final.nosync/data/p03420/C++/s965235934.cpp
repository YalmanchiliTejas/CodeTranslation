#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	long long n, k;
	cin >> n >> k;
	long long ans = 0;
	for (long long b = k+1; b <= n; b++) {
		long long tmp0 = (n-k)/b;
		long long tmp1 = tmp0 * b;
		long long y = n - tmp1;
		if (k <= y && y < b) {
			if (y-k+1 >= 1)
				ans += (tmp0) * (y-k+1);
			if (b-1-(y+1)+1 >= 1)
				ans += (tmp0-1) * (b-1-(y+1)+1);
			ans += (b-k);
		} else {
			ans += tmp0*(b-1 -k+1);
			ans += (b-k);
		}
	}
	if (k == 0)
		cout << ans - (n-k) << endl;
	else
		cout << ans << endl;

	return 0;
}