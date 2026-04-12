#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>
#include<set>
#include<map>
#include<stack>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

struct SegT {
private:
	int n; vector<vec> node;
	vector<vec> lazy;
	vec e;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		vec t(10, 0);
		node.resize(2 * n - 1, t);
		e.resize(10);
		rep(i, 10) {
			e[i] = i;
		}
		lazy.resize(2 * n - 1, e);
		rep(i, sz) {
			node[i + n - 1][0]++;
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	vec f(vec &a, vec &b) {
		vec ret(10,0);
		rep(i, 10) {
			ret[i] = a[i] + b[i];
		}
		return ret;
	}
	//lazy & lazy
	vec g(vec &a, vec &b) {
		vec ret(10);
		rep(i, 10) {
			ret[i] = a[b[i]];
		}
		return ret;
	}
	void eval(int k, int l, int r) {
		vec nex(10, 0);
		rep(i, 10) {
			nex[lazy[k][i]] += node[k][i];
		}
		node[k] = nex;
		if (r - l > 1) {
			lazy[2 * k + 1] = g(lazy[k], lazy[2 * k + 1]);
			lazy[2 * k + 2] = g(lazy[k], lazy[2 * k + 2]);
		}
		lazy[k] = e;
	}
	void update(int fr, int to, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			rep(i, 10) {
				if (lazy[k][i] == fr)lazy[k][i] = to;
			}
			eval(k, l, r);
		}
		else {
			update(fr, to, a, b, k * 2 + 1, l, (l + r) / 2);
			update(fr, to, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int le,int ri,int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return 0;
		if (a <= l && r <= b) {
			int ret = 0;
			Rep(i, le, ri+1) {
				ret += node[k][i];
			}
			return ret;
		}
		else {
			int vl = query(le,ri,a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(le,ri,a, b, k * 2 + 2, (l + r) / 2, r);
			return vl + vr;
		}
	}
	void call() {
		rep(i, 7) {
			query(0, 9, i, i + 1);
			cout << i << endl;
			rep(j, 10) {
				cout << node[i+n-1][j];
			}
			cout << endl;
		}
	}
};

int trans[1 << 17];
int ri[1 << 17];
vector<int> G[1 << 17];

int cur = 0;
void dfs(int id, int fr) {
	trans[id] = cur; cur++;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		dfs(to, id);
	}
	ri[trans[id]] = cur;
}

void solve() {
	int n, q; cin >> n >> q;
	rep(i, n-1) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0, -1);
	SegT st(n);
	rep(i, q) {
		int t, r, x, y; cin >> t >> r >> x >> y;
		if (t == 1) {
			r = trans[r];
			int ans = st.query(x, y, r, ri[r]);
			cout << ans << endl;
		}
		else {
			r = trans[r];
			st.update(x, y, r, ri[r]);
		}
		//st.call();
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	solve();
	//stop
		return 0;
}
