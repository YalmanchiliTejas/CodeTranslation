#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 100005;
inline int getint() {
	register int r = 0; register bool b = true; register char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') b = false; c = getchar(); }
	while (c >= '0' && c <= '9') { r = (r<<1)+(r<<3) + c - '0'; c = getchar(); }
	return b ? r : -r;
}
struct edge_t { int u, v; LL w; } e[maxn * 2];
struct data_t { int x, y, id; } a[maxn];
bool cmpxy(data_t a, data_t b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
bool cmpyx(data_t a, data_t b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
LL ans;
int f[maxn], n, cnte;
int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]); }
void ins(int x, int y, LL w) { ++cnte; e[cnte].u = x; e[cnte].v = y; e[cnte].w = w; }
bool mer(int x, int y) {
	int a = Find(x), b = Find(y);
	if (a == b) return false;
	f[a] = b; return true;
}
bool cmpw(edge_t a, edge_t b) { return a.w < b.w; }
int main() {
	n = getint();
	for (int i = 1; i <= n; ++i) { a[i].x = getint(); a[i].y = getint(); a[i].id = i; f[i] = i; }
	sort(a + 1, a + n + 1, cmpxy); for (int i = 1; i < n; ++i) ins(a[i].id, a[i+1].id, min(abs(a[i].x - a[i+1].x), abs(a[i].y - a[i+1].y)));
	sort(a + 1, a + n + 1, cmpyx); for (int i = 1; i < n; ++i) ins(a[i].id, a[i+1].id, min(abs(a[i].x - a[i+1].x), abs(a[i].y - a[i+1].y)));
	sort(e + 1, e + cnte + 1, cmpw);
	for (int i = 1; i <= cnte; ++i) if (mer(e[i].u, e[i].v)) ans += e[i].w;
	printf("%lld\n", ans);
}
