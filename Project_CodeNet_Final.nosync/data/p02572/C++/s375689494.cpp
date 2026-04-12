#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main()
{
	int n;
	scanf("%d", &n);
	vector<ll> a(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	ll ans = 0, sum = a[0];
	for (int i = 1; i < n; ++i) {
		ans = (ans+sum*a[i]%MOD)%MOD;
		sum = (sum+a[i])%MOD;
	}
	printf("%lld\n", ans);
}