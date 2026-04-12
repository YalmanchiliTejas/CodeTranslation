#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;
const long long INF = 1e18;

int n, m;
vector<pair<int,int>> add[N];
vector<pair<int,int>> del[N];
long long T[N << 2], lz[N << 2];

void push(int v,int l,int r) {
	if (lz[v]) {
		T[v] += lz[v];
		if (l < r) {
			lz[v << 1] += lz[v];
			lz[v << 1 | 1] += lz[v]; 
		}
		lz[v] = 0;
	}
}

void upd(int v,int l,int r,int L,int R,int x) {
	push(v, l, r);
	if (L > r || R < l) {
		return;
	}
	if (L <= l && R >= r) {
		lz[v] = 1LL * x; 
		push(v, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	upd(v << 1, l, mid, L, R, x);
	upd(v << 1 | 1, mid + 1, r, L, R, x);
	T[v] = max(T[v << 1], T[v << 1 | 1]);
}

long long get(int v,int l,int r,int L,int R) {
	push(v, l, r);
	if (L > r || R < l) {
		return -INF;
	}
	if (L <= l && R >= r) {
		return T[v];
	}
	int mid = (l + r) >> 1;
	return max(get(v << 1, l, mid, L, R), get(v << 1 | 1, mid + 1, r, L, R));
}

int32_t main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int l, r, x; 
		scanf("%lld %lld %lld", &l, &r, &x);
		add[l].push_back(make_pair(l - 1, x));
		del[r].push_back(make_pair(l - 1, x));
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (auto q : add[i]) {
			upd(1, 0, n, 0, q.first, q.second);
		}
		long long now = get(1, 0, n, 0, i - 1);
		ans = max(ans, now);
		upd(1, 0, n, i, i, now);
		for (auto q : del[i]) {
			upd(1, 0, n, 0, q.first, -q.second);
		}
	}
	printf("%lld\n", ans);
}