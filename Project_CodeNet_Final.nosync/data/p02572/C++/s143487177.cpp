#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fi first
#define sec second
#define pr priority_queue
ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n; cin >> n;
	vector<ll> vec(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> vec[i];
		sum = (sum + vec[i] + mod) % mod;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ll v = (sum - vec[i] + mod) % mod;
		ll d = (vec[i] * v) % mod;
		ans = (ans + d + mod) % mod;
		sum = (sum - vec[i] + mod) % mod;
	}
	cout << ans << "\n";
	return 0;
}