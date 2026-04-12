#include <bits/stdc++.h>
#define fir first
#define sec second
#define MAX_N 200000
#define mid ((s+t)>>1)
using namespace std;
typedef long long lnt;
typedef pair<int,int> pii;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, m; vector <pii> p[MAX_N+5];
lnt tr[(MAX_N<<2)+5], tag[(MAX_N<<2)+5];
void modify(int v, int s, int t, int l, int r, lnt x) {
	if (s >= l && t <= r) {tr[v] += x, tag[v] += x; return;}
	if (l <= mid) modify(v<<1, s, mid, l, r, x);
	if (r >= mid+1) modify(v<<1|1, mid+1, t, l, r, x);
	tr[v] = max(tr[v<<1], tr[v<<1|1])+tag[v];
}
int main() {
	read(n), read(m);
	for (int i = 1, l, r, c; i <= m; i++)
		read(l), read(r), read(c), p[r].push_back(pii(l, c));
	for (int i = 1; i <= n; i++) {
		modify(1, 1, n, i, i, tr[1]);
		for (pii q : p[i]) modify(1, 1, n, q.fir, i, q.sec);
	}
	return printf("%lld\n", max(tr[1], 0LL)), 0;
}
