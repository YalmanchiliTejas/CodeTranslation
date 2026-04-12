#include<bits/stdc++.h>
#define int long long
#define out(x) cerr << #x << " = " << x << "\n"
using namespace std;
// by piano
template<typename tp> inline void read(tp &x) {
	x = 0;char c = getchar();bool f = 0;
	for(; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
	for(; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
	if(f) x = -x;
}
const int N = 1e6 + 10 ;
int n, ans = 0 ,now = 0;
struct E {
	int u, v, w;
}e[N << 2];
int cnt = 0;
inline void add(int u, int v, int w) {
	e[++ cnt] = (E) {u, v, w};
}
struct P {
	int F, S, id;
}p[N];
int pre[N];
inline bool cmp_x(P a, P b) {
	return a.F < b.F || a.F == b.F && a.S < b.S;
}
inline bool cmp_y(P a, P b) {
	return a.S < b.S || a.S == b.S && a.F < b.F;
}
inline bool cmp_edge(E a, E b) {
	return a.w < b.w;
}
inline int find(int u) {
	return pre[u] == u ? u : pre[u] = find(pre[u]);
}
main() {
	read(n);	
	for(int i = 1; i <= n; i ++) {
		read(p[i].F), read(p[i].S);
		p[i].id = i;
	}	
	sort(p + 1, p + n + 1, cmp_x);
	for(int i = 2; i <= n; i  ++) {
		add(p[i].id, p[i - 1].id, min(abs(p[i].F - p[i - 1]. F), abs(p[i].S - p[i - 1]. S)));
	}
	sort(p + 1, p + n + 1, cmp_y);
	for(int i = 2; i <= n; i  ++) {
		add(p[i].id, p[i - 1].id, min(abs(p[i].F - p[i - 1]. F), abs(p[i].S - p[i - 1]. S)));
	}
	sort(e + 1, e + cnt + 1, cmp_edge);
	for(int i = 1; i <= n; i ++) pre[i] = i;
	for(int i = 1; i <= cnt; i ++) {
		int fx = find(e[i].u), fy = find(e[i].v) ;
		if(fx != fy) pre[fx] = fy, ans += e[i].w;
	}
	cout << ans << "\n";
	return 0;
}