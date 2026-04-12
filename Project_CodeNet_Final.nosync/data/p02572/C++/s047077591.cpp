#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t n;
	cin >> n;
	vector<int64_t> as(n);
	for (auto &&a : as)
	{
		cin >> a;
	}

	int64_t mod = 1000000007;

	vector<int64_t> bs(n + 1, 0);
	for (int64_t i = 0; i < n; i++)
	{
		bs[i + 1] = (bs[i] + as[i]) % mod;
	}

	int64_t ans = 0;
	for (int64_t i = 0; i < n; i++)
	{
		(ans += as[i] * ((bs[n] - bs[i + 1] + mod) % mod) % mod) %= mod;
	}

	cout << ans << endl;

	return 0;
}