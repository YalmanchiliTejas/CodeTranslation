#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	vector<ll> a(n); {
		rep(i, n) cin >> a[i];
	}

	ll ans = 0;
	while(1) {
		sort(a.begin(), a.end());
		if (a.back() < n) break;
		ll k = a.back() / n;
		a.back() %= n;
		rep(i, n - 1) a[i] += k;
		ans += k;
	}
	printf("%lld\n", ans);
	return 0;
}