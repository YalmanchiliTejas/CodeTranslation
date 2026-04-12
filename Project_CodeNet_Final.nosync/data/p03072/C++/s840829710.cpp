#include <bits/stdc++.h>

using ll = long long;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

int n, h[25];
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> h[i];

	int ans = 0;
	int m = 0;
	for (int i = 0; i < n; ++i) {
		if (m <= h[i])
			++ans;
		m = std::max(h[i], m);
	}

	std::cout << ans << std::endl;
	return 0;
}
