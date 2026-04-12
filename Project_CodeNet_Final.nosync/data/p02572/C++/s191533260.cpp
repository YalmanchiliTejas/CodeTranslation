#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI acos(-1.0)
#define test() int t; cin>>t; while(t--)
#define ll long long int
int mod = 1e9 + 7;
int main()
{
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> pref(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		pref[i] = (pref[i + 1] + a[i]) % mod;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = (ans + (a[i] * pref[i + 1]) % mod) % mod;
	}

	cout << ans % mod << endl;
	return 0;
}
