#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//need

ll solve(ll n, ll x)
{
	if (x == 0)
		return 0;
	if (n == 0)
		return 1;
	ll p = 1LL << n;
	if (x >= 2 * p - 1)
	{
		return p + solve(n - 1, x + 1 - 2 * p);
	}
	return solve(n - 1, x - 1);
}

int main()
{
	ll n, k;
	cin >> n >> k;
	cout << solve(n, k) << endl;
	;
}