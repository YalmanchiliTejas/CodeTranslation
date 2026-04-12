#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int n;
vector<int> v;

long long solve(void)
{
	long long sum, i;

	sum = 0;
	i = 0;
	while(i < (n - 2) / 2)
	{
		sum += 2 * v[i];
		i++;
	}
	sum += v[i];
	i++;
	if (n % 2 == 0)
		sum -= v[i];
	else
		sum += v[i];
	i++;
	while(i < n)
	{
		sum -= 2 * v[i];
		i++;
	}
	return abs(sum);
}

signed main(void)
{
	cin >> n;
	long long ans;

	v = vector<int>(n);
	rep(i, n) cin >> v[i];
	sort(v.rbegin(), v.rend());
	ans = solve();
	reverse(v.begin(), v.end());
	ans = max(ans, solve());
	cout << ans << endl;
	return 0;
}
