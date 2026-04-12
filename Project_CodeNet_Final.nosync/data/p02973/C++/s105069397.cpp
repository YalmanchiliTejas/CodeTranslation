#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <random>
#include <iomanip>
#include <bitset>
                        
using namespace std;
                        
template<typename T> void uin(T &a, T b) {
    if (b < a) {
        a = b;
    }
}
                        
template<typename T> void uax(T &a, T b) {
    if (b > a) {
        a = b;
    }
}

#define int long long
#define ghost signed
#define left left228
#define right right228
#define prev prev228
#define list list228
#define complex complex228

const int N = 100 * 1000 + 228;

int n;
int a[N];

struct node
{
	int mx;
	int l, r;
	node() {
		mx = l = r = 0;
	}
};

vector< node > d;

void build(int l, int r, int v = 1) {
	d[v].l = l;
	d[v].r = r;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(l, m, v << 1);
	build(m + 1, r, v << 1 | 1);
}

void init() {
	int ss = 1;
	while (ss < n) ss <<= 1;
	ss <<= 1;
	d.resize(ss + 3, node());
	build(1, n);
}

void update(int i, int x, int v = 1) {
	if (d[v].l == d[v].r) uax(d[v].mx, x);
	else {
		int m = (d[v].l + d[v].r) >> 1;
		if (i <= m) update(i, x, v << 1);
		else update(i, x, v << 1 | 1);
		d[v].mx = max(d[v << 1].mx, d[v << 1 | 1].mx);
	}
}

int get(int l, int r, int v = 1) {
	if (l > r || d[v].l > r || d[v].r < l) return 0;
	if (l <= d[v].l && d[v].r <= r) return d[v].mx;
	return max(get(l, r, v << 1), get(l, r, v << 1 | 1));
}

ghost main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<int> crd;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		crd.push_back(a[i]);
	}
	sort(crd.begin(), crd.end());
	crd.erase(unique(crd.begin(), crd.end()), crd.end());
	for (int i = 1; i <= n; ++i) a[i] = lower_bound(crd.begin(), crd.end(), a[i]) - crd.begin() + 1;
	init();
	update(a[1], 1);
	int res = 1;
	for (int i = 2; i <= n; ++i) {
		int nup = get(a[i], n) + 1;
		update(a[i], nup);
		uax(res, nup);
	}
	cout << res << '\n';
	return 0;
} // kek ;
// Ого! Кажетсья это $#@!








