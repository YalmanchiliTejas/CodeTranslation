#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll INF = 1000000000000000000;

map<pair<int, int>, ll> optTake;

vector<ll> arr;

ll solve(int n, int k) {
	if (n == 0) {
		if (k == 0) return 0;
		else return -INF;
	}
	if (n == 1) {
		if (k == 0) return 0;
		else if (k == 1) return arr[0];
		else return -INF;
	}
	if ((n / 2 + n % 2) < k) return -INF;
	if (optTake.count(make_pair(n, k)) > 0) {
		return optTake[make_pair(n, k)];
	}
	// either we take this element or we don't
	ll ans = solve(n - 1, k);
	if (n >= 2) ans = max(ans, solve(n - 2, k - 1) + arr[n - 1]);
//	printf("solve(%d, %d) = %lld\n", n, k, ans);
	return optTake[make_pair(n, k)] = ans;
}

int main() {
	int n; scanf("%d", &n);
	arr = vector<ll>(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	printf("%lld\n", solve(n, n/2));
	return 0;
}
