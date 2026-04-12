//Pantyhose(black) + glasses = infinity

#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " = " << x << '\n';
#define BP() cerr << "OK!\n";
#define PR(A, n) {cerr << #A << " = "; for (int _=1; _<=n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; for (int _=0; _<n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define FILE_NAME "data"

const int MAX_N = 200007;
const int64_t INF = 1e18;

class segmentTree {
public:

	struct node {
		int64_t val, lazy;

		node() {
			val = lazy = 0;
		}
	};

	int n;
	vector<node> st;

	segmentTree(int n): n(n) {
		st.resize(4*n);
	}

	void down(int id) {
		int64_t tmp = st[id].lazy;
		st[id].lazy = 0;
		st[id*2].val += tmp;
		st[id*2].lazy += tmp;
		st[id*2+1].val += tmp;
		st[id*2+1].lazy += tmp;
	}

	void upd(int u, int v, int64_t delta, int l, int r, int id) {
		if (v<l || u>r)
			return;
		if (u<=l && r<=v) {
			st[id].val += delta;
			st[id].lazy += delta;
			return;
		}
		down(id);
		int mid = (l + r) / 2;
		upd(u, v, delta, l, mid, id*2);
		upd(u, v, delta, mid+1, r, id*2+1);
		st[id].val = min(st[id*2].val, st[id*2+1].val);
	}

	int64_t get(int u, int v, int l, int r, int id) {
		if (v<l || u>r)
			return INF;
		if (u<=l && r<=v)
			return st[id].val;
		down(id);
		int mid = (l + r) / 2;
		return min(get(u, v, l, mid, id*2), get(u, v, mid+1, r, id*2+1));
	}

	void upd(int u, int v, int64_t delta) {
		upd(u, v, delta, 1, n, 1);
	}

	int64_t get(int u, int v) {
		if (u>v)
			return 0;
		return get(u, v, 1, n, 1);
	}
};

int n, m;
vector<pair<int, int> > L[MAX_N];
int64_t s, ps[MAX_N];

void readInput() {
	cin >> n >> m;
	for (int i=1; i<=m; ++i) {
		int l, r, w;
		cin >> l >> r >> w;
		L[l].push_back({r, w});
		s += w;
	}
}

void solve() {
	for (int i=1; i<=n; ++i)
		sort(L[i].begin(), L[i].end());
	int64_t res = s;
	segmentTree tr(n);
	for (int i=n; i>=1; --i) {
		for (auto v : L[i]) {
			tr.upd(v.first, n, v.second);
			// cerr << v.first << ' ' << n << ' ' << v.second << '\n';
		}
		tr.upd(i, i, ps[i+2]);
		int64_t tmp = tr.get(i, n);
		res = max(res, s - tmp);
		ps[i] = min(ps[i+1], tmp);
	}
	cout << res;
}

int main() {
	#ifdef GLASSES_GIRL
		freopen(FILE_NAME".inp", "r", stdin);
		freopen(FILE_NAME".out", "w", stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0);
	readInput();
	solve();
}