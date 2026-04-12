#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007LL
#define all(x) x.begin() , x.end()
#define ld long double
void solve();
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1; //cin >> t;
	while (t--)
		solve();
	return 0;
}
void solve()
{
	ll n; cin >> n;
	ll arr[n]; for (auto &x : arr) cin >> x;
	ll psum[n + 1];
	psum[0] = 0;
	for (int i = 0; i < n; i++) psum[i + 1] = (psum[i] + arr[i]) % mod;
	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		ll tp = (psum[i] * arr[i]) % mod;
		(res += tp) %= mod;
	}
	cout << res;
	cout << "\n";
	return ;
}