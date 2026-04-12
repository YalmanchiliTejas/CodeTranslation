#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	LL n, r = 0;
	int x, m;
	std::cin >> n >> x >> m;
	std::vector<LL> s;
	std::vector<int> mp(m, -1);
	int d, id = 0, now = x;
	while (1) {
		if (mp[now] != -1) {
			d = id - mp[now];
			id = mp[now];
			break;
		}
		mp[now] = id;
		s.emplace_back(now);
		now = LL(now) * now % m;
		++id;
	}
	if (id >= n) {
		for (int i = 0; i < n; ++i) r += s[i];
		std::cout << r << std::endl;
		return 0;
	}
	for (int i = 0; i < id; ++i) r += s[i];
	n -= id;
	LL sd = 0;
	for (int i = 0; i < d; ++i) sd += s[id + i];
	r += (n / d) * sd;
	n %= d;
	for (int i = 0; i < n; ++i) r += s[id + i];
	std::cout << r << std::endl;
	return 0;
}