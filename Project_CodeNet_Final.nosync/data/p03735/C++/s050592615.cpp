#include <cstdio>
#include <algorithm>
#include <vector>
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

inline int read()
{
	int data = 0, w = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
	return data * w;
}

const int maxn(2e5 + 10);
std::pair<int, int> t[maxn]; long long ans;
int n, lx[maxn], ly[maxn], rx[maxn], ry[maxn];

int main()
{
	scanf("%d", &n), ly[0] = ry[n + 1] = 1e9;
	for (int i = 1; i <= n; i++)
	{
	    scanf("%d%d", &t[i].first, &t[i].second);
	    if (t[i].first > t[i].second) std::swap(t[i].first, t[i].second);
	}
	std::sort(t + 1, t + n + 1);
	for (int i = 1; i <= n; i++) lx[i] = std::max(lx[i - 1], t[i].second);
	for (int i = 1; i <= n; i++) ly[i] = std::min(ly[i - 1], t[i].second);
	for (int i = n; i; i--) rx[i] = std::max(rx[i + 1], t[i].second);
	for (int i = n; i; i--) ry[i] = std::min(ry[i + 1], t[i].second);
	ans = 1ll * (t[n].first - t[1].first) * (lx[n] - ly[n]);
	for (int i = 1; i < n; i++)
	{
		int ax = std::max(t[n].first, lx[i]), ay = std::min(t[i + 1].first, ly[i]);
		int bx = std::max(rx[i + 1], t[i].first), by = std::min(ry[i + 1], t[1].first);
		ans = std::min(ans, 1ll * (ax - ay) * (bx - by));
	}
	printf("%lld\n", ans);
	return 0;
}
