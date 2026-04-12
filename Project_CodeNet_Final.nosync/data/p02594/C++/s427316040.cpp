#define MOD 1000000007

#if 1
//------------------------------------------------------------
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Entry { static void Run() { T().Run(); } };
struct MyMain;

#if defined(TEST)
#include "test.hpp"
#else
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(16);
	Entry<MyMain>::Run();
	return 0;
}
#endif

//------------------------------------------------------------
using ll = long long;
#define int ll

#define FOR(i, s, e) for (ll i = ll(s); i < ll(e); ++i)
#define RFOR(i, s, e) for (ll i = ll(e) - 1; i >= ll(s); --i)
#define REP(i, n) for (ll i = 0, i##_size = ll(n); i < i##_size; ++i)
#define RREP(i, n) for (ll i = ll(n) - 1; i >= 0; --i)

#define INF INT64_MAX

//------------------------------------------------------------
template <class T>
struct ContainerHolder {
	bool flag = true;
	T& var;
	ContainerHolder(T& v) : var(v) {}
	operator bool() const { return flag; }
	T* operator->() { return &var; }
};
template <class T> ContainerHolder<T> ContainerHold(T& v) { return ContainerHolder<T>(v); }

#define CFOR(it, container) \
	for (auto holder = ContainerHold(container); holder; holder.flag = false) \
	for (auto it = holder->begin(), endIt = holder->end(); it != endIt; ++it)

//------------------------------------------------------------
template <class T>
struct arr : public vector<T> {
	arr() {}
	arr(initializer_list<T> il) : vector<T>(il) {}
	explicit arr(ll n, T v = T()) : vector<T>(n, v) {}

	T& operator()(int i) { return (*this)[i]; }
	T const& operator()(int i) const { return (*this)[i]; }
	void init(ll n, T v = T()) {
		this->clear();
		this->resize(n, v);
	}
	ll sz() const { return (ll)this->size(); }
	void pb(T v) { this->push_back(v); }
	void sort() { std::sort(this->begin(), this->end()); }
	void sort(function<bool(T, T)> p) { std::sort(this->begin(), this->end(), p); }
	void rsort() { std::sort(this->begin(), this->end(), greater<T>()); }
	void reverse() { std::reverse(this->begin(), this->end()); }
	void unique_erase() { this->erase(std::unique(this->begin(), this->end()), this->end()); }
	bool next_permutation() { return std::next_permutation(this->begin(), this->end()); }

	// これ以下はソート済み前提
	int lower_bound(T const& v, function<bool(T, T)> p) { return std::lower_bound(this->begin(), this->end(), v, p) - this->begin(); }
	int lower_bound(T const& v) { return std::lower_bound(this->begin(), this->end(), v) - this->begin(); }

	int upper_bound(T const& v, function<bool(T, T)> p) { return std::upper_bound(this->begin(), this->end(), v, p) - this->begin(); }
	int upper_bound(T const& v) { return std::upper_bound(this->begin(), this->end(), v) - this->begin(); }

	int find_nearest(T const& v) {
		int i = this->lower_bound(v);
		if (i >= sz()) {
			--i;
		}
		else if ((*this)[i] != v) {
			int p = i - 1;
			if (p >= 0) {
				int id = abs((*this)[i] - v);
				int pd = abs((*this)[p] - v);
				if (pd < id) {
					i = p;
				}
			}
		}
		return i;
	}

	// 見つからなければ-1
	int find(T const& v) {
		int i = this->lower_bound(v);
		if (i >= sz()) {
			return -1;
		}
		if ((*this)[i] != v) {
			return -1;
		}
		return i;
	}

};
using ints = arr<ll>;

template <class T>
struct que : public queue<T> {
	ll sz() const { return (ll)this->size(); }
	T popfront() {
		T v = this->front();
		this->pop();
		return v;
	}
};

template <class A, class B>
struct pr {
	union {
		A a;
		A key;
		A first;
		A x;
	};
	union {
		B b;
		B value;
		B second;
		B y;
	};

	pr() : a(A()), b(B()) {};
	pr(A a_, B b_) : a(a_), b(b_) {}
	pr(pr const& r) : a(r.a), b(r.b) {};
	pr(pair<A, B> const& r) : a(r.first), b(r.second) {};

	bool operator == (pr const& r) const { return a == r.a && b == r.b; }
	bool operator != (pr const& r) const { return !((*this) == r); }
	bool operator < (pr const& r) const {
		if (a == r.a) {
			return b < r.b;
		}
		return a < r.a;
	}

	pr operator + (pr v) const { return pr(x, y) += v; }
	pr operator - (pr v) const { return pr(x, y) -= v; }

	pr& operator += (pr v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	pr& operator -= (pr v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	void flip() { swap(x, y); }

	friend istream& operator>>(istream& is, pr& p) {
		is >> p.a >> p.b;
		return is;
	}
	friend ostream& operator<<(ostream& os, pr const& p) {
		os << p.a << " " << p.b;
		return os;
	}
};
using pint = pr<ll, ll>;
using pints = arr<pint>;

template <class K, class V>
struct dic : public map<K, V> {
	bool get(K const& k, V* v) {
		auto it = this->find(k);
		if (it != this->end()) {
			*v = it->second;
			return true;
		}
		return false;
	}
};

template <class T>
struct arr2 {
	vector<T>	m_vec;
	int			m_width;
	int			m_height;

	arr2() : m_width(0), m_height(0) {}
	arr2(int w, int h, T const& value = T()) : m_width(w), m_height(h) {
		m_vec.resize(w * h, value);
	}
	arr2(arr2 const& r) {
		m_vec = r.m_vec;
		m_width = r.m_width;
		m_height = r.m_height;
	}
	arr2(arr2&& r) {
		m_vec = move(r.m_vec);
		m_width = r.m_width;
		m_height = r.m_height;
	}
	arr2& operator=(arr2 const& r) {
		m_vec = r.m_vec;
		m_width = r.m_width;
		m_height = r.m_height;
		return *this;
	}
	arr2& operator=(arr2&& r) {
		m_vec = move(r.m_vec);
		m_width = r.m_width;
		m_height = r.m_height;
		return *this;
	}

	bool operator ==(arr2 const& r) const {
		return m_vec = r.m_vec;
	}

	bool operator <(arr2 const& r) const {
		if (m_width != r.m_width) {
			return m_width < r.m_width;
		}
		if (m_height != r.m_height) {
			return m_height < r.m_height;
		}
		REP(i, m_vec.size()) {
			if (m_vec[i] != r.m_vec[i]) {
				return m_vec[i] < r.m_vec[i];
			}
		}
		return false;
	}

	pint size() const { return pint(m_width, m_height); }
	int width() const { return m_width; }
	int height() const { return m_height; }

	void init(int w, int h, T const& value = T()) {
		m_vec.clear();
		m_vec.resize(w * h, value);
		m_width = w;
		m_height = h;
	}
	void init(pint size, T const& value = T()) {
		init(size.x, size.y, value);
	}
	T& operator()(int x, int y) { return m_vec[y * m_width + x]; }
	T const& operator()(int x, int y) const { return m_vec[y * m_width + x]; }

	T& operator()(pint p) { return m_vec[p.y * m_width + p.x]; }
	T const& operator()(pint p) const { return m_vec[p.y * m_width + p.x]; }

	T& operator[](pint p) { return m_vec[p.y * m_width + p.x]; }
	T const& operator[](pint p) const { return m_vec[p.y * m_width + p.x]; }

	bool isIn(int x, int y) const {
		return
			x >= 0 && x < m_width &&
			y >= 0 && y < m_height;
	}
	bool isIn(pint p) const { return isIn(p.x, p.y); }
	bool isOut(int x, int y) const {
		return
			x < 0 || x >= m_width ||
			y < 0 || y >= m_height;
	}
	bool isOut(pint p) const { return isOut(p.x, p.y); }

	struct iterator {
	private:
		arr2<T>* owner;

	public:
		pint pt;

		iterator(arr2<T>* owner_, pint pt_) : owner(owner_), pt(pt_) {}

		bool operator ==(iterator const& r) const {
			return pt == r.pt;
		}
		bool operator !=(iterator const& r) const {
			return !((*this) == r);
		}
		void operator++() {
			++pt.x;
			if (pt.x >= owner->width()) {
				++pt.y;
				pt.x = 0;
			}
		}
		T& operator*() {
			return (*owner)(pt);
		}
	};
	iterator begin() {
		return iterator(this, pint(0, 0));
	}
	iterator end() {
		return iterator(this, pint(0, height()));
	}

	void disp(ostream& os) {
		REP(y, m_height) {
			REP(x, m_width) {
				os << setw(2) << (*this)(x, y) << " ";
			}
			os << endl;
		}
		os << endl;
	}
};

const pints around4 = { pint(-1, 0), pint(0, -1), pint(1, 0), pint(0, 1) };

//------------------------------------------------------------
template <class T> void chmin(T& a, T b) { if (b < a) { a = b; } }
template <class T> void chmax(T& a, T b) { if (b > a) { a = b; } }

constexpr int gcd(int a, int b) {
	if (a < 0) { a = -a; }
	if (b < 0) { b = -b; }
	if (a == 0) { return b; }
	if (b == 0) { return a; }

	while (int c = a % b) {
		a = b;
		b = c;
	}
	return b;
}

constexpr int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

//------------------------------------------------------------
struct bfs {
	ints froms;
	ints steps;

	bfs(int N, int start, function<ints(int)> getAround) {
		froms.init(N, -1);
		steps.init(N, -1);

		que<ll> queue;
		queue.push(start);
		froms[start] = start;
		steps[start] = 0;

		while (queue.empty() == false) {
			ll p = queue.popfront();

			for (ll n : getAround(p)) {
				if (steps[n] != -1) {
					continue;
				}

				froms[n] = p;
				steps[n] = steps[p] + 1;
				queue.push(n);
			}
		}
	}
};

struct BfsResult {
	arr2<pint> froms;
	arr2<int> steps;
};

template <class T>
BfsResult bfs2(arr2<T> const& field, pints const& starts, function<bool(T)> canMove) {
	BfsResult result;
	result.froms.init(field.size(), pint(-1, -1));
	result.steps.init(field.size(), -1);

	que<pint> queue;
	for (auto const& start : starts) {
		queue.push(start);
		result.froms(start) = start;
		result.steps(start) = 0;
	}

	while (queue.empty() == false) {
		auto p = queue.popfront();

		for (auto a : around4) {
			pint n = p + a;
			if (field.isOut(n)) {
				continue;
			}
			if (result.steps(n) != -1) {
				continue;
			}
			if (!canMove(field(n))) {
				continue;
			}

			result.froms(n) = p;
			result.steps(n) = result.steps(p) + 1;
			queue.push(n);
		}
	}

	return result;
}

//------------------------------------------------------------
template <int M>
struct modint {
	int raw;

	modint() { raw = 0; }
	modint(int v) {
		if (v < 0) {
			raw = (v % M) + M;
		}
		else if (v >= M) {
			raw = v % M;
		}
		else {
			raw = v;
		}
	}
	modint operator + (modint v) const { return modint(raw) += v; }
	modint operator - (modint v) const { return modint(raw) -= v; }
	modint operator * (modint v) const { return modint(raw) *= v; }

	modint& operator += (modint v) {
		raw += v.raw;
		if (raw >= M) { raw -= M; }
		return *this;
	}
	modint& operator -= (modint v) {
		raw -= v.raw;
		if (raw < 0) { raw += M; }
		return *this;
	}
	modint& operator *= (modint v) {
		raw = (raw * v.raw) % M;
		return *this;
	}
	modint pow(int n) const {
		return modint::pow(raw, n);
	}
	static modint pow(int a, int n) {
		if (n < 0) {
			// not support
			abort();
		}

		int r = 1;
		while (n) {
			if (n & 1) {
				r = (r * a) % M;
			}
			a = (a * a) % M;
			n >>= 1;
		}
		return modint(r);
	}

	modint inv() const {
		int a = raw;
		int b = M;
		int u = 1;
		int v = 0;
		while (b) {
			int t = a / b;
			a -= t * b;
			u -= t * v;
			swap(a, b);
			swap(u, v);
		}
		u %= M;
		if (u < 0) {
			u += M;
		}
		return u;
	}

	friend istream& operator>>(istream& is, modint& m) {
		int v;
		is >> v;
		m = modint(v);
		return is;
	}
	friend ostream& operator<<(ostream& os, modint const& m) {
		return os << m.raw;
	}
};

using mint = modint<MOD>;
using mints = arr<mint>;

//------------------------------------------------------------
struct UnionFind {
	struct Node {
		Node*	parent = nullptr;
		int		count = 1;

		Node* Root() {
			if (parent == nullptr) {
				return this;
			}
			return parent = parent->Root();
		}
	};
	vector<Node> nodes;

	UnionFind(int count) {
		nodes.resize(count);
	}

	void Join(int a, int b) {
		Node* rootA = nodes[a].Root();
		Node* rootB = nodes[b].Root();
		if (rootA == rootB) {
			return;
		}

		if (rootA->count > rootB->count) {
			swap(rootA, rootB);
		}

		rootB->count += rootA->count;
		rootA->parent = rootB;
		rootA->count = 0;
	}

	bool IsReachable(int a, int b) {
		Node* rootA = nodes[a].Root();
		Node* rootB = nodes[b].Root();
		return rootA == rootB;
	}

	int Count(int a) {
		return nodes[a].Root()->count;
	}
};

//------------------------------------------------------------
template <class T>
struct SumsImpl {
private:
	int N;
	arr<T> S;
public:

	SumsImpl(int N_) : N(N_), S(N + 1, 0) {}
	void Set(int i, T const& value) { S(i + 1) = S(i) + value; }

	// l <= x < r
	T Get(int l, int r) const { return S(r) - S(l); }
};
using Sums = SumsImpl<int>;

template <class T>
struct ImosImpl {
private:
	int N;
	arr<T> S;
public:
	ImosImpl() { }
	ImosImpl(int N_) : N(N_), S(N + 1, 0) {
	}

	void init(int N_) {
		N = N_;
		S.init(N + 1, 0);
	}

	void Add(int i, T const& value) {
		S(i + 1) += value;
	}

	void Calc() {
		REP(i, N) {
			S(i + 1) += S(i);
		}
	}

	// l <= x < r
	T Get(int l, int r) const { return S(r) - S(l); }

	T Get(int i) const { return S(i); }
};
using Imos = ImosImpl<int>;


template <class T>
struct Sums2Impl {
private:
	arr2<T> sums;
public:

	Sums2Impl(int W, int H) : sums(W + 1, H + 1) {}

	void Set(int x, int y, T const& value) {
		T s = value;
		s += sums(x + 1, y);
		s += sums(x, y + 1);
		s -= sums(x, y);
		sums(x + 1, y + 1) = s;
	}

	// l <= x < r
	// t <= y < b
	T Get(int l, int t, int r, int b) const {
		int s = sums(r, b);
		s -= sums(r, t);
		s -= sums(l, b);
		s += sums(l, t);
		return s;
	}
};
using Sums2 = Sums2Impl<int>;

template <class T>
struct Imos2Impl {
private:
	arr2<T> sums;
public:

	Imos2Impl(int W, int H) : sums(W + 1, H + 1) {}

	void Add(int x, int y, T const& value) {
		sums(x + 1, y + 1) += value;
	}

	void Calc() {
		REP(y, sums.height() - 1) {
			REP(x, sums.width() - 1) {
				T s = 0;
				s += sums(x + 1, y);
				s += sums(x, y + 1);
				s -= sums(x, y);
				sums(x + 1, y + 1) += s;
			}
		}
	}

	// l <= x < r
	// t <= y < b
	T Get(int l, int t, int r, int b) const {
		int s = sums(r, b);
		s -= sums(r, t);
		s -= sums(l, b);
		s += sums(l, t);
		return s;
	}
};
using Imos2 = Imos2Impl<int>;

//------------------------------------------------------------
struct CombiTbl {
	mints fac;
	mints ifac;

	// 重複組み合わせを使う場合は N*2 を指定しないといけない
	CombiTbl(int N) : fac(N), ifac(N) {
		fac[0] = 1;
		ifac[0] = 1;
		FOR(i, 1, N) {
			fac[i] = fac[i - 1] * i;
			ifac[i] = fac[i].inv();
		}
	}

	// a!
	mint Fac(int a) const {
		return fac(a);
	}

	// aPb
	mint Perm(int a, int b) const {
		return fac(a) * ifac(a - b);
	}

	// aCb
	mint Combi(int a, int b) const {
		return fac(a) * ifac(b) * ifac(a - b);
	}

	// aHb（重複組み合わせ）
	mint RepCombi(int a, int b) const {
		return Combi(a + b - 1, b);
	}
};

//------------------------------------------------------------
#if defined(TEST)
extern istream& mis;
extern ostream& mos;
#else
istream& mis = cin;
ostream& mos = cout;
#endif

//------------------------------------------------------------

struct OutputStream {
	template <class T>
	friend OutputStream& operator<<(OutputStream& s, T const& v) {
		mos << v << '\n';
		return s;
	}
} out;

struct PrintStream {
	stringstream ss;

	template <class T>
	friend PrintStream& operator<<(PrintStream& s, T&& v) {
		s.ss << v << ' ';
		return s;
	}

	PrintStream& operator <<(PrintStream& (*manip)(PrintStream&)) {
		return (*manip)(*this);
	}
} prn;

PrintStream& en(PrintStream& s) {
	string str = s.ss.str();
	s.ss = stringstream();
	if (str.empty() == false) {
		str.pop_back();
	}
	mos << str << '\n';
	return s;
}

//------------------------------------------------------------

template <class T>
struct in_base {
	T value;
	in_base() { mis >> value; }
	operator T() { return value; }
};

struct in_int {
	int value;

	in_int() {
		mis >> value;
	}
	in_int(int add) {
		mis >> value;
		value += add;
	}
	operator int() {
		return value;
	}
};

template <class A, class B>
struct in_pr {
	pr<A, B> value;

	in_pr() {
		mis >> value.a >> value.b;
	}
	in_pr(int addA, int addB) {
		mis >> value.a >> value.b;
		value.a += addA;
		value.b += addB;
	}
	in_pr(bool flip) {
		mis >> value.b >> value.a;
	}
	in_pr(int addA, int addB, bool flip) {
		mis >> value.b >> value.a;
		value.a += addB;
		value.b += addA;
	}
	operator pr<A, B>() {
		return value;
	}
};

template <class T>
struct in_arr {
	arr<T> value;

	in_arr(int N) {
		value.init(N);
		REP(i, N) {
			mis >> value[i];
		}
	}
	in_arr(int N, int add) {
		value.init(N);
		REP(i, N) {
			mis >> value[i];
			value[i] += add;
		}
	}
	operator arr<T>() {
		return value;
	}
};

template <>
struct in_arr<pint> {
	arr<pint> value;

	in_arr(int N) {
		value.init(N);
		REP(i, N) {
			mis >> value[i];
		}
	}
	in_arr(int N, int addA, int addB) {
		value.init(N);
		REP(i, N) {
			mis >> value[i].a >> value[i].b;
			value[i].a += addA;
			value[i].b += addB;
		}
	}
	in_arr(int N, bool flip) {
		value.init(N);
		REP(i, N) {
			mis >> value[i].b >> value[i].a;
		}
	}
	in_arr(int N, int addA, int addB, bool flip) {
		value.init(N);
		REP(i, N) {
			mis >> value[i].b >> value[i].a;
			value[i].a += addB;
			value[i].b += addA;
		}
	}
	operator arr<pint>() {
		return value;
	}
};

template <class A, class B>
struct in_dic {
	dic<A, B> value;

	in_dic(int N) {
		REP(i, N) {
			pair<A, B> pr;
			mis >> pr.first >> pr.second;
			value.insert(pr);
		}
	}
	in_dic(int N, int addA, int addB) {
		REP(i, N) {
			pair<A, B> pr;
			mis >> pr.first >> pr.second;
			pr.first += addA;
			pr.second += addB;
			value.insert(pr);
		}
	}
	in_dic(int N, bool flip) {
		REP(i, N) {
			pair<A, B> pr;
			mis >> pr.second >> pr.first;
			value.insert(pr);
		}
	}
	in_dic(int N, int addA, int addB, bool flip) {
		REP(i, N) {
			pair<A, B> pr;
			mis >> pr.second >> pr.first;
			pr.first += addB;
			pr.second += addA;
			value.insert(pr);
		}
	}
	operator dic<A, B>() {
		return value;
	}
};

template <class T>
	struct in_arr2 {
	arr2<T> value;

	in_arr2(int H, int W) {
		value.init(W, H);
		REP(y, H) {
			REP(x, W) {
				mis >> value(x, y);
			}
		}
	}
	in_arr2(int H, int W, int add) {
		value.init(W, H);
		REP(y, H) {
			REP(x, W) {
				mis >> value(x, y);
				value(x, y) += add;
			}
		}
	}

	operator arr2<T>() {
		return value;
	}
};

template<class T, class Tuple, size_t... Index>
T MakeFromTupleImpl(Tuple&& t, index_sequence<Index...>) {
	return T(get<Index>(forward<Tuple>(t))...);
}

template <class T, class Tuple>
T MakeFromTuple(Tuple&& t) {
	return MakeFromTupleImpl<T>(forward<Tuple>(t), make_index_sequence<tuple_size<remove_reference_t<Tuple>>::value>{});
}

template <class... ARGS>
struct inputWithParam {
	tuple<ARGS...> param;
	inputWithParam() {}
	explicit inputWithParam(tuple<ARGS...>&& param_) : param(param_) { }

	operator int() { return MakeFromTuple<in_int>(param); }
	operator double() { return MakeFromTuple<in_base<double>>(param); }
	operator string() { return MakeFromTuple<in_base<string>>(param); }
	operator char() { return MakeFromTuple<in_base<char>>(param); }

	template <class A, class B>
	operator pr<A, B>() { return MakeFromTuple<in_pr<A, B>>(param); }

	template <class T>
	operator arr<T>() { return MakeFromTuple<in_arr<T>>(param); }

	template <class A, class B>
	operator dic<A, B>() { return MakeFromTuple<in_dic<A, B>>(param); }

	template <class T>
	operator arr2<T>() { return MakeFromTuple<in_arr2<T>>(param); }

};

struct input {
	operator int() { return inputWithParam<>(); }
	operator double() { return inputWithParam<>(); }
	operator string() { return inputWithParam<>(); }
	operator char() { return inputWithParam<>(); }

	template <class A, class B>
	operator pr<A, B>() { return inputWithParam<>(); }

	template <class... ARGS>
	inputWithParam<ARGS...> operator()(ARGS&&... args) {
		inputWithParam<ARGS...> withParam(forward_as_tuple(args...));
		return withParam;
	}
} in;

//------------------------------------------------------------
#endif

struct MyMain {
	int A = in;
	void Run() {
		if (A >= 30) {
			out << "Yes";
		}
		else {
			out << "No";
		}
	}
};
