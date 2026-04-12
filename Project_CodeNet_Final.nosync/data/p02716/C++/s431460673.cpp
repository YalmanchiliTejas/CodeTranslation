#include "bits/stdc++.h"

using namespace std;
using ll = long long int;

template<typename T>
constexpr T Inf = numeric_limits<T>::max() / 1024;

ll Solve(const vector<ll> &a, int index, int skip, vector<vector<ll>> &memo)
{
	if (index + (1 + a.size() % 2 - skip) >= a.size())
	{
		return 0;
	}

	if (memo[index][skip] != -Inf<ll>)
	{
		return memo[index][skip];
	}

	ll ans = Solve(a, index + 2, skip, memo) + a[index];
	if (skip < 1 + a.size() % 2)
	{
		ans = max(ans, Solve(a, index + 1, skip + 1, memo));
	}

	return memo[index][skip] = ans;
}

int main()
{
	int n;
	cin >> n;

	vector<ll> A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	vector<vector<ll>> memo(n + 5, vector<ll>(5, -Inf<ll>));
	ll ans = Solve(A, 0, 0, memo);

	cout << ans << endl;
}