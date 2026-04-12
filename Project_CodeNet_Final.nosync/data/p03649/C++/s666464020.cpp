#include <bits/stdc++.h>

typedef long long LL;
const int N = 55;

LL ans = 0, a[N]; int n;
void solve() {
	LL sum = 0;
	for (int i = 0; i < n; ++i) sum += a[i] / n;
	ans += sum;
	for (int i = 0; i < n; ++i) a[i] = a[i] % n + sum - a[i] / n;
}
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	while (*std::max_element(a, a + n) >= n) solve();
	std::cout << ans << '\n';
	return 0;
}