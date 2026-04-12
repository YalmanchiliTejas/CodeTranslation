// in the name of Allah

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define ll long long
#define double long double
#define sz(x) ((int) (x.size()))

#define fr first
#define se second

#define inf 1e18
#define max_n 200002
#define mod 1000000007

ll add(ll a, ll b) {
	a += b;
	if(a >= mod) return a - mod;
	return a;
}

ll mul(ll a, ll b) {
	a *= b;
	if(a >= mod) return a % mod;
	return a;
}

ll power(ll a, ll b) {
	ll p = 1;
	while(b) {
		if(b&1) p = mul(p, a);
		a = mul(a, a);
		b /= 2;
	}
	return p;
}

/*

const int _N = 1234567;

ll F[_N];
ll IF[_N];

void init() {
	F[0] = 1;
	for(int i=1; i<_N; i++) F[i] = mul(F[i-1], i);
	IF[_N-1] = power(F[_N-1], mod-2);
	for(int i=_N-2; i>=0; i--) IF[i] = mul(IF[i+1], i+1);
}

ll ncr(ll x, ll y) {
	if(y > x || y < 0) return 0;
	return mul(F[x], mul(IF[x-y], IF[y]));
}

/**/

class mxLazySegTree {
public:
	int sz;
	vector <ll> tree, lazy;
	mxLazySegTree(int _sz) {
		sz = _sz;
		tree.assign(sz*4, 0);
		lazy.assign(sz*4, 0);
	}
	// update
	void update(int p, int L, int R, int l, int r, ll val) {
		if(lazy[p] != 0) {
			tree[p] += lazy[p];
			if(L != R) {
				lazy[2*p] += lazy[p];
				lazy[2*p+1] += lazy[p];
			}
			lazy[p] = 0;
		}
		if(R < l || r < L) return;
		if(l <= L && R <= r) {
			tree[p] += val;
			lazy[2*p] += val;
			lazy[2*p+1] += val;
			return;
		}
		int M = (L+R)/2;
		update(2*p, L, M, l, r, val);
		update(2*p+1, M+1, R, l, r, val);
		tree[p] = max(tree[2*p], tree[2*p+1]);
	}
	void update(int l, int r, ll val) {
		update(1, 0, sz-1, l, r, val);
	}
	// query
	ll query(int p, int L, int R, int l, int r) {
		if(R < l || r < L) return -1e18;
		if(lazy[p] != 0) {
			tree[p] += lazy[p];
			if(L != R) {
				lazy[2*p] += lazy[p];
				lazy[2*p+1] += lazy[p];
			}
			lazy[p] = 0;
		}
		if(l <= L && R <= r) return tree[p];
		int M = (L+R)/2;
		return max(query(2*p, L, M, l, r), query(2*p+1, M+1, R, l, r));
	}
	ll query(int l, int r) {
		return query(1, 0, sz-1, l, r);
	}
};

class segment_tree {
 
	private:
 
		vector <ll> tree;
		ll lazy[4*max_n];
		void build(int node, int start, int end) {
			if(start == end) tree[node] = A[start];
			else {
				int mid = (start + end) / 2;
				build(2*node, start, mid);
				build(2*node+1, mid+1, end);
				tree[node] = max(tree[2*node], tree[2*node+1]);
			}
		}
		void updateRange(int node, int start, int end, int l, int r, ll val) {
			if(lazy[node] != 0) {
				tree[node] += lazy[node];
				if(start != end) {
					lazy[node*2] += lazy[node];
					lazy[node*2+1] += lazy[node];
				}
				lazy[node] = 0;
			}
			if(start > end || start > r || end < l) return;
			if(start >= l && end <= r) {
				tree[node] += val;
				if(start != end) {
					lazy[node*2] += val;
					lazy[node*2+1] += val;
				}
				return;
			}
			int mid = (start + end) / 2;
			updateRange(node*2, start, mid, l, r, val);
			updateRange(node*2 + 1, mid + 1, end, l, r, val);
			tree[node] = max(tree[node*2], tree[node*2+1]);
		}
		ll queryRange(int node, int start, int end, int l, int r) {
			if(start > end || start > r || end < l) return -inf;
			if(lazy[node] != 0) {
				tree[node] += lazy[node];
				if(start != end) {
					lazy[node*2] += lazy[node];
					lazy[node*2+1] += lazy[node];
				}
				lazy[node] = 0;
			}
			if(start >= l && end <= r) return tree[node];
			int mid = (start + end) / 2;
			ll p1 = queryRange(node*2, start, mid, l, r);
			ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
			return max(p1, p2);
		}
 
	public:
 
		int n;
		vector <ll> A;
		segment_tree(int sz) {
			A.assign(sz, 0);
			n = A.size();
			tree.assign(4*n, 0);
			memset(lazy, 0, sizeof lazy);
		}
		segment_tree(const vector <ll> &v) {
			A = v;
			n = A.size();
			tree.assign(4*n, 0);
			memset(lazy, -1, sizeof lazy);
			build(1, 0, n-1);
		}
		ll query(int l, int r) {
			return queryRange(1, 0, n-1, l, r);
		}
		void update(int l, int r, ll val) {
			updateRange(1, 0, n-1, l, r, val);
		}
 
};

int n, m;
ll a[max_n];
int l[max_n], r[max_n];
vector <int> s[max_n];
vector <int> e[max_n];

int main() {
	// ll start = clock();
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> l[i] >> r[i] >> a[i];
		s[l[i]].pb(i);
		e[r[i]].pb(i);
	}
	ll res = 0, ans;
	segment_tree st(n+1);
	for(int i=1; i<=n; i++) {
		for(int id : s[i]) st.update(0, i-1, a[id]);
		ans = st.query(0, i-1);
		res = max(res, ans);
		st.update(i, i, ans);
		for(int id : e[i]) st.update(0, l[id]-1, -a[id]);
	}
	cout << res << endl;
	// cerr << (clock() - start) / (CLOCKS_PER_SEC*1.0) << endl;
	return 0;
}