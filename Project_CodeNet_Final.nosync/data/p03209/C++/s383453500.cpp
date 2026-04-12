#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(x))
#define even(x) x % 2 == 0
#define odd(x) x % 2 != 0
#define all(x) x.begin(), x.end()
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define IN1(type, x) type x; cin >> x;
#define inll(x) ll x; cin >> x;

// these functions return the position of result of Binary Search.
#define LB(s, t, x) (int) (lower_bound(s, t, x) - s)
#define UB(s, t, x) (int) (upper_bound(s, t, x) - s)

ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1) ans = 1ll * ans * a % mo; a = 1ll * a * a % mo; } while (b >>= 1); return ans; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll temp = gcd(a, b); return temp ? (a / temp * b) : 0; }
int mDays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx8[] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dy8[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts>
auto make_v(size_t a, size_t b, Ts... ts) { return vector<decltype(make_v<T>(b, ts...))>(a, make_v<T>(b, ts...)); }
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) { for (auto &e : t) fill_v(e, v); }
// auto dp = make_v<int>(4, h, w);
// fill_v(dp, 0);

const ll INF_LL = (1ll << 60);
const int INF_INT = (int)1e9;
const ll MOD_CONST = (ll)(1e9 + 7);

template <typename T>
vector<T> pows(int b, int n) {
    vector<T> ret;
    T x = 1;
    while (ret.size() < n) {
        ret.push_back(x);
        x *= b;
    }
    return ret;
}
// find string "from" in "str", and replace them to "to"
void strReplace(std::string& str, const std::string& from, const std::string& to) {
	std::string::size_type pos = 0;
	while (pos = str.find(from, pos), pos != std::string::npos) {
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
}
template <class T>
bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

inline tuple<ll, ll> rotate45(tuple<ll, ll> point) { ll x = get<0>(point), y = get<1>(point); return tuple<ll, ll>(x + y, x - y); }
inline bool rangeCheck2D(int nx, int ny, int Width, int Height) { return nx >= 0 and nx < Width and ny >= 0 and ny < Height; }

template <typename T>
vector<T> INPA(ll n) {
	vector<T> x;
	REP(i, n) {
		T tmp; cin >> tmp;
		x.push_back(tmp);
	}
	return move(x);
}
template <typename T>
void out(T o) { cout << o << endl; }
template <typename T>
void out(vector<T> &out) { REP(i, (int)out.size()) { cout << out[i]; if (i == (int)out.size() - 1) cout << endl; else cout << " "; } }
template <typename T>
void out(vector<vector<T>> o) { REP(i, o.size()) out(o[i]); }
void YesNo(bool f) { cout << (f?"Yes":"No") << endl; }
void YESNO(bool f) { cout << (f?"YES":"NO") << endl; }

// use " for (const auto& e : V)

string longestCommonPrefix(vector<string>& strs) {
    int n = INT_MAX;
    if (strs.size() <= 0) {
        return "";
    }
    if (strs.size() == 1) {
        return strs[0];
    }
    // get the min length
    for (int i = 0; i < strs.size(); i ++) {
        n = strs[i].length() < n ? strs[i].length() : n ;
    }
    for (int i = 0; i < n; i ++) { // check each character
        for (int j = 1; j < strs.size(); j ++) {
            if (strs[j][i] != strs[j - 1][i]) { // we find a mis-match
                return strs[0].substr(0, i);
            }
        }
    }
    // prefix is n-length
    return strs[0].substr(0, n);
}

ll p_base(ll base, ll x) {
	ll ans = 1;
	REP(i, x) {
		ans *= base;
		ans %= MOD_CONST;
	}
	return ans;
}

class ListG {
public:
	// there's directed edge between A and B
	// if to[A] has element B
	vector<vector<int>> to; 

	map<pair<int, int>, ll> cost;
	void setCost(int u, int v, ll c) { 
		cost[{min(u, v), max(u, v)}] = c;
	}
	ll getCost(int u, int v) {
		return cost[{min(u, v), max(u, v)}];
	}

	ListG(int s) : root(-1) {
		size = s;
		to = make_v<vector<int>>(size);
	}

	void setDirectedEdge(int f, int t) {
		to[f].push_back(t);
	}
	void setIndirectedEdge(int v1, int v2) {
		setDirectedEdge(v1, v2);
		setDirectedEdge(v2, v1);
	}

	void dfs(int x) {
		// do something
	}

	void makeTree(int r) {
		root = r;
		p = make_v<int>(size);
		p[root] = -1;
		depth = make_v<int>(size);
		mtdfs(root, 0);
		// count leaf node
		auto idxs = make_v<int>(size);
		iota(all(idxs), 0);
		leaf_idx = set<int>(all(idxs));
		FOR(i, 1, size)
			leaf_idx.erase(p[i]);
	}

	void makeEulerTour() {
		assert(root >= 0);
		et_begin = make_v<int>(size);
		et_end = make_v<int>(size);
		tmp_k = 0;
		etdfs(root, -1);
	}

	int size, root;
	vector<int> p; // parent for each node. parent of root = -1
	vector<int> depth; // for each node. depth of root node = 0
	vector<int> euler_tour;
	vector<int> et_begin, et_end;
	set<int> leaf_idx;

	int tmp_k;
private:	
	void mtdfs(int c, int d) {
		depth[c] = d;
		REP(i, to[c].size()) {
			int next = to[c][i];
			if (p[c] == next) continue;
			p[next] = c;
			mtdfs(next, d + 1);
		}
	}
	void etdfs(int vidx, int pidx) {
		et_begin[vidx] = tmp_k;
		euler_tour.push_back(vidx);
		tmp_k++;
		REP(i, to[vidx].size()) {
			if (to[vidx][i] != pidx) {
				etdfs(to[vidx][i], vidx);
				euler_tour.push_back(vidx);
				tmp_k++;
			}
		}
		et_end[vidx] = tmp_k;
	}
};

template <typename T>
class BinaryIndexedTree {
public:
	int size;
	vector<T> data;

	BinaryIndexedTree(int s, T initial_value = T(0)) {
		size = s;
		data = make_v<T>(size+1);
		fill_v(data, initial_value);
	}
	
	void add(int idx, T value) {
		while (idx <= size) {
			data[idx] += value;
			idx += idx & -idx;
		}
	}

	T sum(int idx) {
		T s = 0;
		while (idx > 0) {
			s += data[idx];
			idx -= idx & -idx;
		}
		return s;
	}
};

ll num(vector<ll> &a, vector<ll> &p, ll n, ll x) {
	if (n == 0)
		return (x <= 0) ? 0 : 1;
	else if (x <= (a[n-1] + 1))
		return num(a, p, n-1, x-1);
	else
		return p[n-1] + 1 + num(a, p, n-1, x - 2 - a[n-1]);
};

int main(void)
{
    cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(20);

	inll(N);
	auto a = make_v<ll>(N+1);
	a[0] = 1;
	FOR(i, 1, N+1) a[i] = 2 * a[i-1] + 3;
	auto p = make_v<ll>(N+1);
	p[0] = 1;
	FOR(i, 1, N+1) p[i] = 2 * p[i-1] + 1;

	inll(X);
	out(num(a, p, N, X));

	return 0;
}
