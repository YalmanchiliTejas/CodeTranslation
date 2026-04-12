#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define ff first
#define ss second
#define prec(y,x) fixed<<setprecision(y)<<x
#define inf 1e18
#define pi 3.1415926535

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin >> n;
	ll arr[n] = {0};
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	ll sfx[n];
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1)
			sfx[i] = arr[n - 1];
		else
		{sfx[i] = sfx[i + 1] + arr[i]; sfx[i] %= mod;}
	}
	ll ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		ll ans1 = arr[i] * sfx[i + 1];
		ans1 %= mod;
		ans += ans1;
		ans %= mod;
	}
	cout << ans;
	return 0;
}

