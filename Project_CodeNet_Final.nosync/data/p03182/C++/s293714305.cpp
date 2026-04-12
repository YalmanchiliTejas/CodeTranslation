#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

// [a -> b-1]
#define reps(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
// [0 -> a-1]
#define rep(i, a) reps(i, 0, (a))
// [a-1 -> b]
#define rreps(i, a, b) for (int i = (int)((a)-1); i >= (int)(b); i--)
// [a-1 -> 0]
#define rrep(i, a) rreps(i, a, 0)
#define all(v) (v).begin(), (v).end()
// next_permutation(all(v))
#define PERM(v) next_permutation(all(v))
/*sort(all(v));
 * (v).erase(unique(all(v)), v.end())*/
#define UNIQUE(v)\
	sort(all(v));\
	(v).erase(unique(all(v)), v.end())
// b is [a, c)
#define RANGE(a, b, c) ((a) <= (b) && (b) < (c))
// c is [a, e) && d is [b, f)
#define RANGE2D(a, b, c, d, e, f) (RANGE((a), (c), (e)) && RANGE((b), (d), (f)))
#define chmin(a, b) a = min(a, (b))
#define chmax(a, b) a = max(a, (b))
#define fcout cout << fixed << setprecision(15)
#define YES(f) cout << ((f) ? YES_STR : NO_STR) << endl;

#ifdef LOCAL_DEBUG_OPTION
namespace debug_print_n{
struct DebugPrint {
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_integral<U>::value && !is_same<U, bool>::value && !is_same<U, char>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << x;
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_same<U, bool>::value> DUMP_SUB_FUNCTION(T x) {
		if (x) cerr << "True";
		else cerr << "False";
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_same<U, char>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << '\'' << x << '\'';
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_same<U, string>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << '\"' << x << '\"';
	}
	template<class T>
	static enable_if_t<is_same<T, const char*>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << string(x);
	}
	template<class T>
	static enable_if_t<true> DUMP_SUB_FUNCTION(vector<T> x) {
		cerr << '{';
		for (size_t i = 0; i < x.size(); i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(x[i]);
		}
		cerr << '}';
	}
	template<class T, size_t N>
	static enable_if_t<true> DUMP_SUB_FUNCTION(array<T, N> x) {
		cerr << '{';
		for (size_t i = 0; i < x.size(); i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(x[i]);
		}
		cerr << '}';
	}
	template<class T>
	static enable_if_t<true> DUMP_SUB_FUNCTION(set<T> x) {
		cerr << '[';
		size_t i = 0;
		for (auto itr = x.begin(); itr != x.end(); itr++, i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(*itr);
		}
		cerr << ']';
	}
	template<class T, class U>
	static enable_if_t<true> DUMP_SUB_FUNCTION(map<T, U> x) {
		cerr << '[';
		size_t i = 0;
		for (auto itr = x.begin(); itr != x.end(); itr++, i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(itr->first);
			cerr << " : ";
			DUMP_SUB_FUNCTION(itr->second);
		}
		cerr << ']';
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_floating_point<U>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << fixed << setprecision(5) << x;
	}
	template<class T, class U>
	static enable_if_t<true> DUMP_SUB_FUNCTION(pair<T, U> p) {
		cerr << '(';
		DUMP_SUB_FUNCTION(p.first);
		cerr << ", ";
		DUMP_SUB_FUNCTION(p.second);
		cerr << ')';
	}
	template<int num = 0, class... Args>
	static enable_if_t<num == sizeof...(Args)> DUMP_SUB_FUNCTION(tuple<Args...> t) {
		if (num) cerr << ')';
	}
	template<int num = 0, class... Args>
	static enable_if_t<num < sizeof...(Args)> DUMP_SUB_FUNCTION(tuple<Args...> t) {
		if (num == 0) cerr << '(';
		DUMP_SUB_FUNCTION(get<num>(t));
		if (num + 1 < sizeof...(Args)) cerr << ", ";
		DUMP_SUB_FUNCTION<num+1>(t);
	}
	template<long unsigned N>
	static enable_if_t<true> DUMP_SUB_FUNCTION(bitset<N> x) {
		cerr << x;
	}
};
void dump() {
	cerr << endl;
}
template<class Head, class... Tail>
void dump(Head&& head, Tail&&... tail) {
	DebugPrint::DUMP_SUB_FUNCTION(head);
	if (sizeof...(Tail) != 0) {
		cerr << ' ';
	}
	dump(forward<Tail>(tail)...);
}
} // namespace debug_print_n
using debug_print_n::dump;
#else
template<class... Args> void dump(Args&&... args) { }
#endif

/**
 * @title 遅延伝播セグメント木
 * @brief 0-indexed 半開区間
 * @brief MonoidPair はクラス Node と クラス Lazy を持つ。
 * @brief クラス Node と Lazy は Monoid であり、{型(monoid_type), 演算(operator+), 単位元(default constructor), constructor(monoid_type)} の4つを持つ。
 * @brief クラス Lazy は {operator*(int), is_unity()} も持つ。
 * @brief クラス Node は operator+(const Lazy&) も持つ。
 * @brief MonoidPair の具体例は monoid/pair/ にある。
 */
template<class MonoidPair>
struct LazySegmentTree {
	int n;
	using Node = typename MonoidPair::Node; using Node_T = typename MonoidPair::Node::monoid_type;
	using Lazy = typename MonoidPair::Lazy; using Lazy_T = typename MonoidPair::Lazy::monoid_type;
	vector<Node> node;
	vector<Lazy> lazy;
	// @brief サイズ N で初期化(初期値は単位元) O(N)$
	LazySegmentTree (int N) {build(N);}
	// @brief vector で初期化 O(N)$
	LazySegmentTree (const vector<Node_T>& v) {build(v);}
	LazySegmentTree () {}
	// @brief (a, b] に x を遅延伝播 O(\log N)$
	void set(int a, int b, Lazy_T x) {set(a, b, x, 0, 0, n);}
	// @brief (a, b] を取得 O(\log N)$
	Node_T get(int a, int b) {return get(a, b, 0, 0, n).val;}
	// @brief index i を取得 O(\log N)$
	Node_T operator[](int i) {
		return get(i, i+1);
	}
	// @brief サイズ N で再構築(初期値は単位元) O(N)$
	void build(int n_) {
		n = calc_n(n_);
		node.clear(); node.resize(2*n-1);
		lazy.clear(); lazy.resize(2*n-1);
	}
	// @brief vector で再構築 O(N)$
	void build(const vector<Node_T>& v) {
		build(v.size());
		for (size_t i = 0; i < v.size(); i++) {
			node[i+n-1].val = v[i];
		}
		for (int i = n - 2; i >= 0; i--){
			node[i] = node[i*2+1] + node[i*2+2];
		}
	}
private:
	void eval(int len, int k) {
		if (lazy[k].is_unity()) return;
		if (2*k+1 < 2*n-1) {
			lazy[2*k+1] = lazy[2*k+1] + lazy[k];
			lazy[2*k+2] = lazy[2*k+2] + lazy[k];
		}
		node[k] = node[k] + lazy[k] * len;
		lazy[k] = Lazy();
	}
	Node set(int a, int b, Lazy_T x, int k, int l, int r) {
		eval(r-l, k);
		if (r <= a || b <= l) return node[k];
		if (a <= l && r <= b) {
			lazy[k] = lazy[k] + Lazy(x);
			return node[k] + lazy[k] * (r-l);
		}
		return node[k] = set(a, b, x, 2*k+1, l, (l+r) / 2) + set(a, b, x, 2*k+2, (l+r) / 2, r);
	}
	Node get(int a, int b, int k, int l, int r) {
		eval(r-l, k);
		if (a <= l && r <= b) {
			return node[k];
		} else if (b <= l || r <= a) {
			return Node();
		}
		return get(a, b, 2*k+1, l, (l+r) / 2) + get(a, b, 2*k+2, (l+r) / 2, r);
	}
	int calc_n(int n_, int t = 1) {return n_ > t ? calc_n(n_, t << 1) : t;}
};

template<class T>
struct max_monoid {
	using mono = max_monoid;
	max_monoid() : max_monoid(numeric_limits<T>::min()) {}
	explicit max_monoid(T x) : val(x) {}
	T val;
	mono operator+(const mono& rhs) const {
		return mono(max(val, rhs.val));
	}
	friend istream& operator>>(istream& lhs, mono& rhs) {
		lhs >> rhs.val;
		return lhs;
	}
	friend ostream& operator<<(ostream& lhs, mono& rhs) {
		lhs << rhs.val;
		return lhs;
	}
	using monoid_type = T;
};
template<class T>
struct plus_monoid {
	using mono = plus_monoid;
	plus_monoid() : plus_monoid(T()) {}
	explicit plus_monoid(T x) : val(x) {}
	T val;
	mono operator+(const mono& rhs) const {
		return mono(val + rhs.val);
	}
	friend istream& operator>>(istream& lhs, mono& rhs) {
		lhs >> rhs.val;
		return lhs;
	}
	friend ostream& operator<<(ostream& lhs, mono& rhs) {
		lhs << rhs.val;
		return lhs;
	}
	using monoid_type = T;
};

template<class T, class U = T>
struct max_plus_monoid {
	template<class TT> using lazy_monoid = plus_monoid<TT>;
	template<class TT> using node_monoid = max_monoid<TT>;
	struct Lazy : public lazy_monoid<U> {
		using lazy_monoid<U>::lazy_monoid;
		using lazy_monoid<U>::operator+;
		using lazy_monoid<U>::operator=;
		Lazy(lazy_monoid<U> x) : lazy_monoid<U>(x) {}
		Lazy() : lazy_monoid<U>() {}
		inline Lazy operator*(int len) const {
			return Lazy(this->val);
		}
		inline bool is_unity() const {
			return this->val == T();
		}
	};
	struct Node : public node_monoid<T> {
		using node_monoid<T>::node_monoid;
		using node_monoid<T>::operator+;
		using node_monoid<T>::operator=;
		Node(node_monoid<T> x) : node_monoid<T>(x) {}
		Node() : node_monoid<T>() {}
		inline Node operator+(const Lazy& rhs) const {
			return Node(this->val + rhs.val);
		}
	};
};

signed main(){
	int N, M; cin >> N >> M;
	vector<vector<int>> L(N+1), A(N+1);
	rep(i, M) {
		int l, r, a; cin >> l >> r >> a;
		L[r].push_back(l);
		A[r].push_back(a);
	}
	// LazySegmentTree<max_plus_monoid<ll>> seg(N);
	LazySegmentTree<max_plus_monoid<ll>> seg(vector<ll>(N+1));
	reps(i, 1, N+1) {
		ll v = seg[i];
		seg.set(i, i+1, seg.get(0, i) - v);
		rep(j, L[i].size()) {
			seg.set(L[i][j], i+1, A[i][j]);
		}
	}
	cout << seg.get(0, N+1) << endl;
}
