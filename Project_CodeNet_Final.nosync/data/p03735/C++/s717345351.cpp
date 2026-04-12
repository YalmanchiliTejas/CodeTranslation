#include<bits/stdc++.h>

#define LL long long
#define RG register

using namespace std;
template<class T> inline void read(T &x) {
	x = 0; RG char c = getchar(); bool f = 0;
	while (c != '-' && (c < '0' || c > '9')) c = getchar(); if (c == '-') c = getchar(), f = 1;
	while (c >= '0' && c <= '9') x = x*10+c-48, c = getchar();
	x = f ? -x : x;
	return ;
}
template<class T> inline void write(T x) {
	if (!x) {putchar(48);return ;}
	if (x < 0) x = -x, putchar('-');
	int len = -1, z[20]; while (x > 0) z[++len] = x%10, x /= 10;
	for (RG int i = len; i >= 0; i--) putchar(z[i]+48);return ;
}
const int N = 2e5 + 10, inf = 1e9;
int n;
struct node {
	int x, y;
} a[N];
bool cmp(node a, node b) {
	return a.x < b.x;
}
int lmx1[N], rmx1[N], lmn1[N], rmn1[N];
int lmx2[N], rmx2[N], lmn2[N], rmn2[N];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].x); read(a[i].y);
		if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
	}
	sort(a + 1, a + 1 + n, cmp);
	int Rmax = -inf, Rmin = inf, Lmax = -inf, Lmin = inf;
	for (int i = 1; i <= n; i++) {
		lmx1[i] = Lmax = max(Lmax, a[i].x); lmn1[i] = Lmin = min(Lmin, a[i].x);
		rmx1[i] = Rmax = max(Rmax, a[i].y); rmn1[i] = Rmin = min(Rmin, a[i].y);
	}
	Rmax = -inf, Rmin = inf, Lmax = -inf, Lmin = inf;
	for (int i = n; i >= 1; i--) {
		lmx2[i] = Lmax = max(Lmax, a[i].x); lmn2[i] = Lmin = min(Lmin, a[i].x);
		rmx2[i] = Rmax = max(Rmax, a[i].y); rmn2[i] = Rmin = min(Rmin, a[i].y);
	}
	LL ans = 1ll * (Rmax - Rmin) * (Lmax - Lmin);
	for (int i = 2; i <= n; i++) {
		Lmax = max(lmx2[i], rmx1[i - 1]); Lmin = min(lmn2[i], rmn1[i - 1]);
		Rmax = max(rmx2[i], lmx1[i - 1]); Rmin = min(rmn2[i], lmn1[i - 1]);
		ans = min(ans, 1ll * (Rmax - Rmin) * (Lmax - Lmin));
	}
	printf("%lld\n", ans);
	return 0;
}
