#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using VI = vector<int>;
using VL = vector<ll>;
using VS = vector<string>;
template<class T> using PQ = priority_queue<T, vector<T>, greater<T>>;
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
#define eFOR(i,a,n) for(int i=(a);i<=(n);++i)
#define rFOR(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define erFOR(i,a,n) for(int i=(n);i>=(a);--i)
#define each(i, a) for(auto &i : a)
#define SORT(a) sort(a.begin(),a.end())
#define rSORT(a) sort(a.rbegin(),a.rend())
#define fSORT(a,f) sort(a.begin(),a.end(),f)
#define all(a) a.begin(),a.end()
#define out(y,x) ((y)<0||h<=(y)||(x)<0||w<=(x))
#define tp(a,i) get<i>(a)
#define line cout << "-----------------------------\n" 
#define ENDL(i,n) ((i) == (n) - 1 ? "\n" : " ")
#define elif else if
#define stop system("pause")
constexpr ll INF = 1000000000;
constexpr ll LLINF = 1LL << 60;
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
constexpr ld eps = 1e-10;
constexpr ld pi = 3.1415926535897932;
template<class T>inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; }return false; }
inline void init() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }
template<class T>inline istream& operator>>(istream& is, vector<T>& v) { for (auto& a : v)is >> a; return is; }
template<class T>inline istream& operator>>(istream& is, deque<T>& v) { for (auto& a : v)is >> a; return is; }
template<class T, class U>inline istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template<class T>inline vector<T> vec(size_t a) { return vector<T>(a); }
template<class T>inline vector<T> defvec(T def, size_t a) { return vector<T>(a, def); }
template<class T, class... Ts>inline auto vec(size_t a, Ts... ts) { return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...)); }
template<class T, class... Ts>inline auto defvec(T def, size_t a, Ts... ts) { return vector<decltype(defvec<T>(def, ts...))>(a, defvec<T>(def, ts...)); }
template<class T>inline void print(const T& a) { cout << a << "\n"; }
template<class T, class... Ts>inline void print(const T& a, const Ts&... ts) { cout << a << " "; print(ts...); }
template<class T>inline void print(const vector<T>& v) { for (int i = 0; i < v.size(); ++i)cout << v[i] << (i == v.size() - 1 ? "\n" : " "); }
template<class T>inline void print(const vector<vector<T>>& v) { for (auto& a : v)print(a); }
inline string reversed(const string& s) { string t = s; reverse(all(t)); return t; }

template<class Op> class SegmentTree {
	using T = typename Op::T;
	int len, n;
	vector<T> dat;
	vector<pair<int, int>> range;
public:
	SegmentTree(const int _n) : n(_n) {
		for (len = 1; len < n; len <<= 1);
		dat.resize(len << 1, Op::unit);
		range.resize(len << 1);
		for (int i = 0; i < len; ++i)
			range[i + len] = make_pair(i, i + 1);
		for (int i = len - 1; 0 < i; --i)
			range[i] = make_pair(range[i << 1].first, range[i << 1 | 1].second);
	}
	SegmentTree(const vector<T>& v) : n(v.size()) {
		for (len = 1; len < n; len <<= 1);
		dat.resize(len << 1, Op::unit);
		range.resize(len << 1);
		for (int i = 0; i < n; ++i)dat[i + len] = v[i];
		for (int i = 0; i < len; ++i)
			range[i + len] = make_pair(i, i + 1);
		for (int i = len - 1; 0 < i; --i) {
			dat[i] = Op::merge(dat[i << 1], dat[i << 1 | 1]);
			range[i] = make_pair(range[i << 1].first, range[i << 1 | 1].second);
		}
	}
	inline void update(int idx, const T a) {
		idx += len;
		dat[idx] = Op::update(dat[idx], a);
		for (idx >>= 1; 0 < idx; idx >>= 1)
			dat[idx] = Op::merge(dat[idx << 1], dat[idx << 1 | 1]);
	}
	inline T value(int l, int r) {
		T vl = Op::unit, vr = Op::unit;
		for (l += len, r += len; l < r; l >>= 1, r >>= 1) {
			if (l & 1)vl = Op::merge(vl, dat[l++]);
			if (r & 1)vr = Op::merge(dat[--r], vr);
		}
		return Op::merge(vl, vr);
	}
	inline int binary_search(const T a) {
		if (!Op::check(dat[1], a))return n;
		T cur = Op::unit;
		int idx = 2;
		for (; idx < len << 1; idx <<= 1) {
			if (!Op::check(Op::merge(cur, dat[idx]), a))
				cur = Op::merge(cur, dat[idx++]);
		}
		return min((idx >> 1) - len, n);
	}
	inline int binary_search(int l, int r, const T a) {
		T cur = Op::unit;
		int ret = l;
		for (int idx = l + len; idx < len << 1 && ret < r;) {
			if (range[idx].second <= r &&
				!Op::check(Op::merge(cur, dat[idx]), a)) {
				cur = Op::merge(cur, dat[idx]);
				ret = range[idx++].second;
				if (~idx & 1)idx >>= 1;
			}
			else idx <<= 1;
		}
		return ret;
	}
	inline T operator[](int idx) { return dat[idx + len]; }
};
template<class Type> struct intMaxAssignUpdate {
	using T = Type;
	inline static T unit = -1;
	inline static T merge(T vl, T vr) { return max(vl, vr); }
	inline static T update(T vl, T vr) { return vr; }
	inline static bool check(T vl, T vr) { return vl >= vr; }
};

int main() {
    init();

    int n, q; cin >> n >> q;
    VI a(n); cin >> a;
	SegmentTree<intMaxAssignUpdate<int>> seg(a);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, v; cin >> x >> v;
            --x;
			seg.update(x, v);
        }
        elif (t == 2) {
            int l, r; cin >> l >> r;
            --l;
			print(seg.value(l, r));
        }
        else {
			int x, v; cin >> x >> v;
			--x;
			print(seg.binary_search(x, n, v) + 1);
        }
    }

    return 0;
}