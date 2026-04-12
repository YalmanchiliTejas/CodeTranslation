#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200005;
const ll OO = 1e18;

int n, m;
int a[N];
vector<pii> v[N];
ll val[1 << 20], lazy[1 << 20];

void push(int id) {
	val[id] += lazy[id];
	lazy[id * 2 + 1] += lazy[id];
	lazy[id * 2 + 2] += lazy[id];
	lazy[id] = 0;
}

void update(int ql, int qr, ll x, int id = 0, int l = 0, int r = n - 1) {
	push(id);
	if (ql > r || qr < l)
		return;
	if (ql <= l && r <= qr) {
		lazy[id] += x;
		push(id);
		return;
	}
	int mid = (l + r) / 2;
	update(ql, qr, x, id * 2 + 1, l, mid);
	update(ql, qr, x, id * 2 + 2, mid + 1, r);
	val[id] = max(val[id * 2 + 1], val[id * 2 + 2]);
}

ll query(int ql, int qr, int id = 0, int l = 0, int r = n - 1) {
	push(id);
	if (ql > r || qr < l)
		return -OO;
	if (ql <= l && r <= qr)
		return val[id];
	int mid = (l + r) / 2;
	return max(query(ql, qr, id * 2 + 1, l, mid), query(ql, qr, id * 2 + 2, mid + 1, r));
}

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		l--, r--;
		v[r].emplace_back(l, x);
	}
	for (int i = 0; i < n; i++) {
		ll cur = 0;
		if (i) {
			cur = max(cur, query(0, i - 1));
		}
		update(i, i, cur);
		for (auto p : v[i]) {
			update(p.first, i, p.second);
		}
	}
	cout << max(0LL, query(0, n - 1)) << endl;
	return 0;
}
