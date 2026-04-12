#include<bits/stdc++.h>
using namespace std;
#define MAXN	400005
#define INF	1e18
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct info {long long num; int type; };
bool operator < (info a, info b) {return a.num < b.num; }
info a[MAXN]; int n, tot;
long long x[MAXN], y[MAXN];
long long solve1() {
	long long mn = INF, mx = 0;
	for (int i = 1; i <= n; i++) {
		mn = min(mn, max(x[i], y[i]));
		mx = max(mx, min(x[i], y[i]));
	}
	return (a[tot].num - mn) * (mx - a[1].num);
}
int Cnt[MAXN];
long long solve2() {
	if (a[1].type == a[tot].type) return INF;
	int l = 1, r = 0, cnt = 0;
	long long ans = INF;
	while (r <= tot) {
		Cnt[a[++r].type]++;
		if (Cnt[a[r].type] == 1) cnt++;
		if (cnt != n) continue;
		while (Cnt[a[l].type] == 2)
			Cnt[a[l++].type]--;
		ans = min(ans, (a[tot].num - a[1].num) * (a[r].num - a[l].num));
	}
	return ans;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(x[i]), read(y[i]);
		a[++tot] = (info) {x[i], i};
		a[++tot] = (info) {y[i], i};
	}
	sort(a + 1, a + tot + 1);
	cout << min(solve1(), solve2()) << endl;
	return 0;
}