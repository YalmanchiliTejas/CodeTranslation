#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

signed main(void)
{
	int n;
	ll sum, ans;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	sum = 0;
	if (n % 2 == 1)
	{
		sum = a[n / 2] + a[n / 2 + 1];
		rep(i, n / 2)
			sum += 2 * a[i];
		for (int i = n / 2; i < n; i++)
			sum -= 2 * a[i];
		ans = sum;
		sum = a[n / 2 - 1] + a[n / 2];
		rep(i, n / 2 - 1)
			sum += 2 * a[i];
		for (int i = n / 2 + 1; i < n; i++)
			sum -= 2 * a[i];
		ans = max(sum, ans);
	}
	else
	{
		sum = a[n / 2 - 1] - a[n / 2];
		rep(i, n / 2 - 1)
			sum += 2 * a[i];
		for (int i = n / 2 + 1; i < n; i++)
			sum -= 2 * a[i];
		ans = sum;
	}
	cout << ans << endl;
	return 0;
}
