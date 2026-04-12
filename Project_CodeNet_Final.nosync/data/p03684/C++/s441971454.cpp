#include <bits/stdc++.h>

/*
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
*/

using namespace std;

typedef long long LL;
typedef double DB;
typedef unsigned int UI;
typedef pair<int, int> PII;

const int inf = 0x7f7f7f7f;

#define rdi() read<int>()
#define rdl() read<LL>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define pb push_back
#define fi first
#define se second
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int i = j; i >= k; i --)
#define Edge(i, u) for (int i = head[u]; i; i = e[i].nxt)

template<typename t> t read() {
	t x = 0; int f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

template<typename t> void write(t x) {
	if (x < 0){
		putchar('-'), write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int N = 100010;
struct pp {
	int x, y, i;
} p[N];
struct aa {
	int x, y, z;
} a[N * 2];

int f[N];
long long ans;

int i, n, cnt, x, y, fx, fy;

bool cmp1(pp a, pp b) {
	return a.x < b.x;
}
bool cmp2(pp a, pp b) {
	return a.y < b.y;
}
void add(int x, int y, int z) {
	a[++cnt].x = x, a[cnt].y = y, a[cnt].z = z;
}
bool cmp(aa a, aa b) {
	return a.z < b.z;
}
int getf(int x) {
	return f[x] == x ? x : f[x] = getf(f[x]);
}
int main() {
	n = rdi();
	for (i = 1; i <= n; i++) p[i].x = rdi(), p[i].y = rdi(), p[i].i = f[i] = i;
	sort(p + 1, p + n + 1, cmp1);
	for (i = 1; i < n; i++) add(p[i].i, p[i + 1].i, abs(p[i].x - p[i + 1].x));
	sort(p + 1, p + n + 1, cmp2);
	for (i = 1; i < n; i++) add(p[i].i, p[i + 1].i, abs(p[i].y - p[i + 1].y));
	sort(a + 1, a + cnt + 1, cmp);
	for (i = 1; i <= cnt; i++) {
		x = a[i].x, y = a[i].y;
		fx = getf(x), fy = getf(y);
		if (fx == fy) continue;
		ans += a[i].z;
		f[fx] = fy;
	}
	printf("%d\n", ans);
	return 0; 
}
