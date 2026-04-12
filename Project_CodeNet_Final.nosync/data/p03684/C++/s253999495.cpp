#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;
const int MAXN = 100010;
int n, en, fa[MAXN];
struct Point {
	int x, y, id;
}P[MAXN];
struct Edge {
	int from, to, w;
	Edge(int from = 0, int to = 0, int w = 0) : from(from), to(to), w(w) {}
	bool operator < (const Edge &rhs) const {
		return w < rhs.w;
	}
}E[MAXN<<1];
ll ans;

bool cmp1(Point a, Point b) {
	return a.x < b.x;
}

bool cmp2(Point a, Point b) {
	return a.y < b.y;
}

inline int dis(int a, int b) {
	return min(abs(P[a].x-P[b].x), abs(P[a].y-P[b].y));
}

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch=='-') f=-1;
	for(; isdigit(ch); ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x * f;
}

int find(int x) {
	return fa[x] = fa[x] == x ? x : find(fa[x]);
}

int main() {
	int i;
	n = read();
	for(i = 1; i <= n; i++) 
		P[i].x = read(), P[i].y = read(), P[i].id = i;
	sort(P+1, P+n+1, cmp1);
	for(i = 1; i < n; i++) E[++en] = Edge(P[i].id, P[i+1].id, dis(i, i+1));
	sort(P+1, P+n+1, cmp2);
	for(i = 1; i < n; i++) E[++en] = Edge(P[i].id, P[i+1].id, dis(i, i+1));
	sort(E+1, E+en+1);
	for(i = 1; i <= n; i++) fa[i] = i;
	for(i = 1; i <= en; i++) {
		int a = E[i].from, b = E[i].to;
		int x = find(a), y = find(b);
		if(x == y) continue;
		fa[x] = y, ans += E[i].w;
	}
	printf("%lld\n", ans);
	return 0;
}
