#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
const int maxn = 2e5 + 10;
typedef std::pair<long long, int> PLI;

std::priority_queue<PLI> q;
int n, m, pre[maxn], nxt[maxn];
long long ans, s[maxn];
bool del[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	std::cin >> n; m = n >> 1;
	for (int i = 1; i <= n; ++i) {
		std::cin >> s[i];
		q.push(std::make_pair(s[i], i));
		pre[i] = i - 1, nxt[i] = i + 1;
	}
	nxt[n + 1] = n + 1;
	for (int i = 0; i < m; ++i) {
		while (del[q.top().second]) q.pop();
		ans += q.top().first;
		if (i == m - 1) std::cout << ans << '\n';
		int p = q.top().second, l = pre[p], r = nxt[p];
		q.pop(), del[l] = del[r] = true;
		if (l > 0 && r <= n) {
			s[p] = s[l] + s[r] - s[p];
			q.push(std::make_pair(s[p], p));
			nxt[pre[p] = pre[l]] = pre[nxt[p] = nxt[r]] = p;
		} else if (l == 0) pre[nxt[r]] = 0;
		else nxt[pre[l]] = n + 1;
	}
	return 0;
}
