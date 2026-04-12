#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct SegT {
private:
	int n; vector<int> node, lazy;
	const int init_c = mod;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, 0);
		lazy.resize(2 * n - 1, 0);
	}
	SegT(vector<int> v) {
		int sz = v.size();
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, mod);
		lazy.resize(2 * n - 1, 0);
		rep(i, sz) {
			node[i + n - 1] = v[i];
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	ll f(ll a, ll b) {
		return min(a, b);
	}
	void eval(int k, int l, int r) {
		node[k] += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}
	void add(int x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x; eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	int search_id() {
		int k = 0, l = 0, r = n;
		while (k < n - 1) {
			int mid = (l + r) / 2;
			eval(2 * k + 1, l, mid);
			eval(2 * k + 2, mid, r);
			if (node[2 * k + 2] < 2) {
				k = 2 * k + 2; l = mid;
			}
			else {
				k = 2 * k + 1, r = mid;
			}
		}
		return k - (n - 1) + 1;
	}
};

void solve() {
	int n, q; cin >> n >> q;
	string s; cin >> s;
	vector<int> c;
	int tmp = 0;
	set<int> sr;
	rep(i, s.length()) {
		if (s[i] == '(')tmp++;
		else {
			tmp--; sr.insert(i);
		}
		c.push_back(tmp);
	}
	SegT st(c);
	rep(i, q) {
		int x; cin >> x; x--;
		if (s[x] == '(') {
			s[x] = ')';
			st.add(-2, x, n); sr.insert(x);
			int z = *sr.begin();
			cout << z + 1 << endl;
			s[z] = '(';
			st.add(2, z, n);
			sr.erase(z);
		}
		else {
			s[x] = '(';
			sr.erase(x);
			st.add(2, x, n);
			int z = st.search_id();
			cout << z + 1 << endl;
			s[z] = ')';
			sr.insert(z);
			st.add(-2, z, n);
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}

