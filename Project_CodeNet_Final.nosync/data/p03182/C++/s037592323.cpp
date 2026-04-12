#include <bits/stdc++.h>
using namespace std;

#define int ll

#define pb push_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define fs first
#define sd second

typedef long long ll;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}

void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef LOCAL
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

double get_time() {
	return 1.0 * clock() / CLOCKS_PER_SEC;
}

const int MAXN = 2E5 + 100, INF = 1E17 + 5;
int val[MAXN], t[4*MAXN], lazy[4*MAXN];

void push(int v) {
	t[2*v + 1] += lazy[v];
	lazy[2*v + 1] += lazy[v];
	t[2*v + 2] += lazy[v];
	lazy[2*v + 2] += lazy[v];
	lazy[v] = 0;
}

void build_tree(int v, int l, int r) {
	if(r < l)
		return;
	if(l == r) {
		t[v] = val[l];
		return;
	}
	int mid = (l + r)/2;
	build_tree(2*v + 1, l, mid);
	build_tree(2*v + 2, mid + 1, r);
	t[v] = max(t[2*v + 1], t[2*v + 2]);
}

void update(int v, int l, int r, int tl, int tr, int val) {
	if(tr < tl)
		return;
	if(tr == r && tl == l) {
		lazy[v] += val;
		t[v] += val;
		return;
	}
	push(v);
	int mid = (l + r)/2;
	update(2*v + 1, l, mid, tl, min(tr, mid), val);
	update(2*v + 2, mid + 1, r, max(tl, mid + 1), tr, val);
	t[v] = max(t[2*v + 2], t[2*v + 1]);
}

int query(int v, int l, int r, int tl, int tr) {
	if(tr < tl)
		return -INF;
	if(tl == l && tr == r)
		return t[v];
	push(v);
	int mid = (l + r)/2;
	return max(query(2*v + 1, l, mid, tl, min(mid, tr)), 
			query(2*v + 2, mid + 1, r, max(tl, mid + 1), tr));
}

int32_t main() {
	int n, m;
	cin >> n >> m;
	vi l(m), r(m), a(m);
	vi v(m);
	vvi ends(n + 1), begins(n + 1);
	iota(all(v), 0);
	build_tree(0, 0, n);
	for(int i = 0; i < m; i++) {
		cin >> l[i] >> r[i] >> a[i];
		ends[r[i]].pb(i);
		begins[l[i]].pb(i);
	}
	vi dp(n + 1, -INF);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int pos : begins[i]) {
			update(0, 0, n, 0, l[pos] - 1, a[pos]);
		}
		dp[i] = query(0, 0, n, 0, i - 1);
		update(0, 0, n, i, i, dp[i]);
		for(int pos : ends[i])
			update(0, 0, n, 0, l[pos] - 1, -a[pos]);
	}
	int res = 0;
	for(int i = 0; i <= n; i++)
		res = max(res, dp[i]);
	cout << res << '\n';
}
