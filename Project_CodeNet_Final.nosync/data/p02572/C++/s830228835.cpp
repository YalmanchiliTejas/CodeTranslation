#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

int main()
{
	fastIO;
	ll mod = 1e9 + 7;
	ll ans = 0;
	ll sum = 0;
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		sum += a[i];
		sum %= mod;
	}
	for (int i=0; i<n; i++) {
		sum -= a[i];
		if (sum < 0) sum += mod;
		ans = ans + (a[i]*sum)%mod;
		ans %= mod;
	}
	cout << ans << '\n';
}