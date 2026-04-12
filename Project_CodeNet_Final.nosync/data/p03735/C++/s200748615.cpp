#include <bits/stdc++.h>

typedef long long LL;
const int inf = 0x3f3f3f3f, N = 200005;
int n;
LL ans = (LL) inf * inf;

std::vector<std::pair<int, int>> v;

void solve0() {
	static bool vis[N];
	int l = v.begin()->first, r = v.rbegin()->first;
	int L = -inf, R = inf;
	for (auto p : v) {
		if (vis[p.second])
			R = std::min(R, p.first);
		else
			L = std::max(L, p.first);
		vis[p.second] = 1;
	}
	ans = std::min(ans, (LL) (L - l) * (r - R));
}
void solve1() {
	static int cnt[N], now = 0;
	int a = v.rbegin()->first - v.begin()->first, b = inf;
	int l = 1;
	for (int r = 1; r < v.size() - 1; ++r) {
		now += !cnt[v[r].second]++;
		while (now == n) {
			b = std::min(b, v[r].first - v[l].first);
			now -= !--cnt[v[l++].second];
		}
	}
	ans = std::min(ans, (LL) a * b);
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 0, l, r; i < n; ++i)
		std::cin >> l >> r, v.emplace_back(l, i), v.emplace_back(r, i);
	std::sort(v.begin(), v.end());
	solve0(); if (v.begin()->second != v.rbegin()->second) solve1();
	std::cout << ans << '\n';
	return 0;
}