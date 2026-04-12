#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("tune=native")
using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007LL;
const int MAX_N = 200005;

int n;
ll a[MAX_N];

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	ll suffSum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		suffSum += a[i];
		while (suffSum >= MOD)
			suffSum -= MOD;
	}

	ll result = 0;
	for (int i = 0; i < n; i++)
	{
		suffSum -= a[i];
		while (suffSum < 0)
			suffSum += MOD;
		result += (a[i] * suffSum) % MOD;
		while (result >= MOD)
			result -= MOD;
	}
	cout << result << '\n';

	return 0;
}