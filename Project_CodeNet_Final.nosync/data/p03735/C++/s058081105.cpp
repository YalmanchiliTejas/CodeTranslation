#include <bits/stdc++.h>

const int MAXN = 400010;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef std::pair<int, int> pi;
int n; pi ls[MAXN]; LL ans;
int li[MAXN], bak, rs[MAXN], R[MAXN];
void gma(int & x, int y) { x < y ? x = y : 0; }
int lb(int x) { return std::lower_bound(li + 1, li + 1 + bak, x) - li; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	int lm = INF, la = -INF, rm = INF, ra = -INF;
	for (int i = 1; i <= n; ++i) {
		std::cin >> ls[i].first >> ls[i].second;
		if (ls[i].first > ls[i].second)
			std::swap(ls[i].first, ls[i].second);
		lm = std::min(lm, ls[i].first);
		la = std::max(la, ls[i].first);
		rm = std::min(rm, ls[i].second);
		ra = std::max(ra, ls[i].second);
		li[++bak] = ls[i].first, li[++bak] = ls[i].second;
	}
	ans = (LL) (la - lm) * (ra - rm);
	std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	for (int i = 1; i <= n; ++i)
		gma(R[lb(ls[i].first)], li[lb(ls[i].second)]);
	int r = la;
	for (int i = 1; i <= n && li[i] <= rm; ++i) {
		// std::cout << i << ' ' << r << std::endl;
		ans = std::min(ans, (LL) (r - li[i]) * (ra - lm));
		r = std::max(r, R[i]);
	}
	std::cout << ans << std::endl;
	return 0;
}
