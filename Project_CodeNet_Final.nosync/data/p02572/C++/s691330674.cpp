#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

ll mod = 1'000'000'007;

int		main(void)
{
	ll n;
	cin >> n;

	ll sum = 0;
	vector<ll> A(n);
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		sum += a;
		A[i] = a;
	}
	ll ans = 0;
	for (int i = 0; i < n-1; i++)
	{
		sum -= A[i];
		ans += A[i] * (sum % mod);
		ans %= mod;
	}
	cout << ans << endl;
}

