#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define maxN 200005



int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
	ll n, sum = 0;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		sum = sum % mod;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		sum -= v[i];
		if (sum < 0) {
			sum += mod;
		}
		ans += (v[i] * sum);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}