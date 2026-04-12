#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
const ll mod = 1000000007;
int main()
{
	SPEED
	int n;
	cin >> n;
	ll arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	ll suffix_arr[n];
	suffix_arr[n-1] = arr[n-1];
	for (int i = n-2; i >= 0; --i)
	{
		suffix_arr[i] = suffix_arr[i+1] + arr[i];
		suffix_arr[i] = (suffix_arr[i])%mod;
	}

	ll ans = 0;

	for (int i = 0; i < n-1; ++i)
	{
		ll temp = (arr[i]*(suffix_arr[i+1]))%mod;
		ans += temp;
		ans = ans%mod;
	}

	cout << ans;
	return 0;
}