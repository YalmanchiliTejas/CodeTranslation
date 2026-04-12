#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100005;
int N, M;
struct Node {
	int x, y, id;
} p[maxn];
bool cmpx(const Node &x, const Node &y) {
	return x.x < y.x;
}
bool cmpy(const Node &x, const Node &y) {
	return x.y < y.y;
}
struct Edge {
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0) : 
		u(u), v(v), w(w) {}
	bool operator < (const Edge &x) const {
		return w < x.w;
	}
} e[maxn << 1];
int f[maxn];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].id = i;
	}
	sort(p + 1, p + N + 1, cmpx);
	for(int i = 1; i < N; ++i)
		e[++M] = Edge(p[i].id, p[i + 1].id, p[i + 1].x - p[i].x);
	sort(p + 1, p + N + 1, cmpy);
	for(int i = 1; i < N; ++i)
		e[++M] = Edge(p[i].id, p[i + 1].id, p[i + 1].y - p[i].y);
	sort(e + 1, e + M + 1);
	for(int i = 1; i <= N; ++i) f[i] = i;
	long long ans = 0;
	for(int i = 1; i <= M; ++i) {
		int fa = find(e[i].u), fb = find(e[i].v);
		if(fa == fb) continue;
		ans += e[i].w;
		f[fb] = fa;
	}
	printf("%lld\n", ans);
	return 0;
}