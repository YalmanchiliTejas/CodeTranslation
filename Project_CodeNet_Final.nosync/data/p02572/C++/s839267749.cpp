#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
constexpr int MOD = 1e9+7;

int main()
{
	int n; cin >> n;
	ll pre = 0;
	ll num;
	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> num;
		ans = (ans + (pre * num)% MOD ) % MOD;
		pre += num;
		pre %= MOD;
	}
	cout << ans;
	return 0;
}