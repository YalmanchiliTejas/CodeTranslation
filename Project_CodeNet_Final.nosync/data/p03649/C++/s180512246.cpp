#include <bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n; lnt a[55], s, tot;
bool chk(lnt x) {
	lnt cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] > x) cnt += (a[i]-x)/(n+1);
	return cnt <= s-n*n;
}
lnt bi_solve(lnt l, lnt r) {
	lnt ret = r;
	while (l <= r)
		if (!chk(mid)) l = mid+1;
		else ret = mid, r = mid-1;
	return ret;
}
void solve() {
	if (s >= n*n) {
		lnt mx = 0;
		for (int i = 1; i <= n; i++)
			a[i] += s-n*n, mx = max(mx, a[i]);
		lnt x = bi_solve(0, mx);
		for (int i = 1; i <= n; i++) if (a[i] > x)
			tot += (a[i]-x)/(n+1), a[i] -= (a[i]-x)/(n+1)*(n+1);
		for (int p = 1; tot < s-n*n; p = 1, tot++) {
			for (int i = 2; i <= n; i++)
				if (a[i] > a[p]) p = i;
			a[p] -= n+1;
		}
	}
	for (int p = 1; ; p = 1, tot++) {
		for (int i = 2; i <= n; i++)
			if (a[i] > a[p]) p = i;
		if (a[p] < n) break;
		for (int i = 1; i <= n; i++)
			if (i == p) a[i] -= n; else a[i]++;
	}
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), s += a[i];
	return solve(), printf("%lld\n", tot), 0;
}
