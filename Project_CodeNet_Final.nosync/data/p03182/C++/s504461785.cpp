
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
	os << "[ "; for(auto v : V) os << v << " "; return os << "]";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1> void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << endl;
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1<<" | ";
	__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mems(x, y) memset(x, y, sizeof(x))
#define rep(i, n) for (int i = 0; i < n; ++i)
#define irep(i, n) for (int i = 1; i <= n; ++i)
#define print(x) cout << x << '\n'
#define err(x) clog << x << '\n'
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;
const int mod = (119<<23)+1;
const int M = 1e9+7;
const int N = 2e5+5;

int n;
int t[4*N], z[4*N];

void apply(int v, int x) {
	t[v] += x;
	z[v] += x;
}

void push(int v) {
	apply(v*2, z[v]);
	apply(v*2+1, z[v]);
	z[v] = 0;
}

void upd(int v, int l, int r, int ql, int qr, int x) {
	if (ql >= r || qr <= l) return;
	else if (l >= ql && r <= qr) apply(v, x);
	else {
		push(v);
		int m = (l+r)/2;
		upd(v*2, l, m, ql, qr, x);
		upd(v*2+1, m, r, ql, qr, x);
		t[v] = min(t[v*2], t[v*2+1]);
	}
}

int qry(int v, int l, int r, int ql, int qr) {
	if (ql >= r || qr <= l) return INF;
	else if (l >= ql && r <= qr) return t[v];
	else {
		push(v);
		int m = (l+r)/2;
		return min(qry(v*2, l, m, ql, qr), qry(v*2+1, m, r, ql, qr));
	}
}

inline void update(int ql, int qr, int x) { upd(1, 0, n+1, ql, qr, x); }

inline int query(int ql, int qr) { return qry(1, 0, n+1, ql, qr); }

vpii v[N];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed << setprecision(15);
	
	int m; cin >> n >> m;
	int s = 0;
	rep(i, m) {
		int l, r, a; cin >> l >> r >> a;
		v[r].pb({l, a});
		s += a;
	}

	irep(i, n) {
		update(i, i+1, query(0, i));
		for (auto p: v[i]) update(0, p.F, p.S);
	}

	print(s-query(0, n+1));
}
