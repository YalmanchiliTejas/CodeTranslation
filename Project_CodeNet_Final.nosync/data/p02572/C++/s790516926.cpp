#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5 , mod = 1e9 + 7;

typedef long long ll;

ll sum[maxn] , a[maxn];

int main() {
	int n;
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)cin >> a[i];
	sum[n] = a[n] % mod;
	for(int i = n - 1 ; i >= 1 ; i--) {
		sum[i] = ( sum[i + 1] + a[i] ) % mod;
	}
	ll ans = 0;
	for(int i = 1 ; i < n ; i++) {
		ans = ( ans +  ( a[i] % mod ) * ( sum[i + 1] % mod) ) % mod;
	}
	cout << ans << "\n";
	return 0;
}