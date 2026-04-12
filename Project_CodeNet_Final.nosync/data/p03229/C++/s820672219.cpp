#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());


	// l s l s l s l (n % 2 == 1)
	// l s l s l s (n % 2 == 0)
	// 全体の和を考えたときに
	ll ans1 = 0, ans2 = 0;
	rep(i, 0, n) {
		if (i < n / 2) 
			ans1 -= a[i] << 1;
		else 
			ans1 += a[i] << 1;

		if (i <= n / 2) 
			ans2 -= a[i] << 1;
		else 
			ans2 += a[i] << 1;
	}
	// ans1 = l s l s l
	// ans2 = s l s l s
	if (n & 1) {
		ans1 -= a[n / 2] + a[n / 2 + 1];
		ans2 += a[n / 2] + a[n / 2 - 1];
	}
	else {
		ans1 += a[n / 2 - 1] - a[n / 2];
		ans2 += a[n / 2 - 1] - a[n / 2];
	}
	cout << max(ans1, ans2);

	return 0;
}
