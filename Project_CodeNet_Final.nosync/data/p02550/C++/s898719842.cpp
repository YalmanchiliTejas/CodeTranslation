#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, x, m;
	cin >> n >> x >> m;
	long long N = min(n + 1, m + 2);
	vector<long long> a(N);
	vector<int> vis(m);
	a[1] = x;
	vis[x] = 1;
	long long ans = 0;
	for (int i = 2; i < N; i++) {
		a[i] = a[i - 1] * a[i - 1] % m;
		if (vis[a[i]]) {
			long long sum1 = accumulate(a.begin() + 1, a.begin() + vis[a[i]], 0LL);
			vector<long long> cycle;
			for (int j = vis[a[i]]; j < i; j++) {
				cycle.push_back(a[j]);
			}
			n -= vis[a[i]] - 1;
			long long sum2 = accumulate(cycle.begin(), cycle.end(), 0LL);
			long long sum3 = accumulate(cycle.begin(), cycle.begin() + n % cycle.size(), 0LL);
			cout << sum1 + sum2 * (n / cycle.size()) + sum3 << "\n";
			return 0;
		} else {
			vis[a[i]] = i;
		}
	}
	ans = accumulate(a.begin(), a.end(), 0LL);
	cout << ans << "\n";
	return 0;
}