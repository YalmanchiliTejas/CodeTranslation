#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
const int N = 3e5;
int n, m, l[N], r[N], a[N];
vector<int> L[N], R[N];
ll ans;
ll f[N * 4], lazy[N * 4], mx[N * 4];
void pushdown(int k) {
	if (lazy[k]) {
		lazy[k << 1] += lazy[k];
		mx[k << 1] += lazy[k];
		lazy[k << 1 | 1] += lazy[k];
		mx[k << 1 | 1] += lazy[k];
		lazy[k] = 0;
	}
}
void Ins(int k, int l, int r, int p, ll v) {
	if (l != r) pushdown(k);
	if (l == r) {
		mx[k] = v;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)
		Ins(k << 1, l, mid, p, v);
	else 
		Ins(k << 1 | 1, mid + 1, r, p, v);
	mx[k] = max(mx[k << 1], mx[k << 1 | 1]);
}
void Add(int k, int l, int r, int p, int q, ll v) {// cout << k << ",";
	if (l != r) pushdown(k);
	if (l > q || r < p) return;
	if (r <= q && l >= p) {
		lazy[k] = v;
		mx[k] += v;
		return;
	}
	int mid = l + r >> 1;
	Add(k << 1, l, mid, p, q, v);
	Add(k << 1 | 1, mid + 1, r, p, q, v);
	mx[k] = max(mx[k << 1], mx[k << 1 | 1]);
}
ll Query(int k, int l, int r, int p, int q) {
	if (l != r) pushdown(k);
	if (l > q || r < p) return -1e18;
	if (r <= q && l >= p) return mx[k];
	int mid = l + r >> 1;
	return max(Query(k << 1, l, mid, p, q), Query(k << 1 | 1, mid + 1, r, p, q));
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d", l + i, r + i, a + i);
		L[l[i]].push_back(i);
		R[r[i] + 1].push_back(i);
	}
	Ins(1, 0, n, 0, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j: L[i]) Add(1, 0, n, 0, l[j] - 1, a[j]);
		for (int j: R[i]) Add(1, 0, n, 0, l[j] - 1, -a[j]);
		//cout << i << ":" << endl;
		//for (int j = 0; j < i; ++j) cout << Query(1, 0, n, j, j) << "/"; cout << endl;
		ll tmp = Query(1, 0, n, 0, i - 1);
		Ins(1, 0, n, i, tmp);
		ans = max(ans, tmp);
		//cout << tmp << "/";
	}
	cout << ans;
}

