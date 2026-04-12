#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define INF 1000000000

void test_case()
{
	int n;
	cin >> n;
	ll a[n], mod = 1e9 + 7;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll suffix[n] = {};
	suffix[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suffix[i] = (suffix[i + 1] + a[i]) % mod;
	}
	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans = (ans + a[i] * suffix[i + 1]) % mod;
	}
	cout << ans;
}


int main()
{
	fastio
	// int t;
	// cin >> t;
	// while (t--)
	test_case();
}
