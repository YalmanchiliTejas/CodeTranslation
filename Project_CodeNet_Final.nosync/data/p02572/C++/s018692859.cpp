#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;

int n;
ll a[200001];
ll psum[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
		psum[i];
	}

	ll ans = 0;
	for (int i = 1; i < n; i++)
	{
		ans += a[i] * ((psum[n] - psum[i]) % MOD) % MOD;
		ans %= MOD;
	}

	cout << ans;
}