#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, 0, n) cin >> a[i];
	ll ans = 0;
	while(1){
		sort(a.begin(), a.end());
		if (a[n - 1] < n) break;
		ll add = a[n - 1] / n;
		ans += add;
		rep(i, 0, n - 1) a[i] += add;
		a[n - 1] %= n;
	}
	printf("%lld", ans);
 	return 0;
}
