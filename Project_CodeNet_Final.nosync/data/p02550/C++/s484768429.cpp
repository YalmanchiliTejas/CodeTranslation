#define MOD 998244353
//#include <atcoder/all>

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
extern istream& mis;
extern ostream& mos;
#else
istream& mis = cin;
ostream& mos = cout;
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

template <class A, class B, class C>
struct tr {
	union {
		A a;
		A first;
		A x;
	};
	union {
		B b;
		B second;
		B y;
	};
	union {
		C c;
		C third;
		C z;
	};

	tr() : a(A()), b(B()), c(C()) {};
	tr(A a_, B b_, C c_) : a(a_), b(b_), c(c_) {}
	tr(tr const& r) : a(r.a), b(r.b), c(r.c) {};

	bool operator == (tr const& r) const { return a == r.a && b == r.b && c == r.c; }
	bool operator != (tr const& r) const { return !((*this) == r); }
	bool operator < (tr const& r) const {
		if (a == r.a) {
			if (b == r.b) {
				return c < r.c;
			}
			return b < r.b;
		}
		return a < r.a;
	}

	tr operator + (tr v) const { return tr(x, y, z) += v; }
	tr operator - (tr v) const { return tr(x, y, z) -= v; }

	tr& operator += (tr v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	tr& operator -= (tr v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	friend istream& operator>>(istream& is, tr& p) {
		is >> p.a >> p.b >> p.c;
		return is;
	}
	friend ostream& operator<<(ostream& os, tr const& p) {
		os << p.a << " " << p.b << " " << p.c;
		return os;
	}
};
using tint = tr<ll, ll, ll>;
using tints = arr<tint>;

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
	vector<vector<T>>	m_vec;
	int			m_width;
	int			m_height;

	arr2() : m_width(0), m_height(0) {}
	arr2(int w, int h, T const& value = T()) : m_width(w), m_height(h) {
		m_vec.resize(h, vector<T>(w, value));
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
		REP(y, m_height) {
			REP(x, m_width) {
				if ((*this)(x, y) != r(x, y)) {
					return (*this)(x, y) < r(x, y);
				}
			}
		}
		return false;
	}

	pint size() const { return pint(m_width, m_height); }
	int width() const { return m_width; }
	int height() const { return m_height; }

	void init(int w, int h, T const& value = T()) {
		m_vec.clear();
		m_vec.resize(h, vector<T>(w, value));
		m_width = w;
		m_height = h;
	}
	void init(pint size, T const& value = T()) {
		init(size.x, size.y, value);
	}
	T& operator()(int x, int y) { return m_vec[y][x]; }
	T const& operator()(int x, int y) const { return m_vec[y][x]; }

	T& operator()(pint p) { return m_vec[p.y][p.x]; }
	T const& operator()(pint p) const { return m_vec[p.y][p.x]; }

	T& operator[](pint p) { return m_vec[p.y][p.x]; }
	T const& operator[](pint p) const { return m_vec[p.y][p.x]; }

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
	return a / gcd(a, b) * b;
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

PrintStream& endl(PrintStream& s) {
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
void input(T& value) {
	mis >> value;
}
void input(int& value, int add) {
	mis >> value;
	value += add;
}
template <class A, class B>
void input(pr<A, B>& value) {
	mis >> value.a >> value.b;
}
template <class A, class B>
void input(pr<A, B>& value, int addA, int addB) {
	mis >> value.a >> value.b;
	value.a += addA;
	value.b += addB;
}
template <class A, class B, class C>
void input(tr<A, B, C>& value) {
	mis >> value.a >> value.b >> value.c;
}
template <class A, class B, class C>
void input(tr<A, B, C>& value, int addA, int addB, int addC) {
	mis >> value.a >> value.b >> value.c;
	value.a += addA;
	value.b += addB;
	value.c += addC;
}
template <class T, class... ARGS>
void input(arr<T>& value, int N, ARGS&&... args) {
	value.init(N);
	REP(i, N) {
		input(value[i], forward<ARGS>(args)...);
	}
}
template <class T, class... ARGS>
void input(arr2<T>& value, int H, int W, ARGS&&... args) {
	value.init(W, H);
	REP(y, H) {
		REP(x, W) {
			input(value(x, y), forward<ARGS>(args)...);
		}
	}
}
template <class K, class V, class... ARGS>
void input(dic<K, V>& value, int N, ARGS&&... args) {
	REP(i, N) {
		pair<K, V> pr;
		input(pr.first);
		input(pr.second, forward<ARGS>(args)...);
		value.insert(pr);
	}
}

template <class T>
struct inputHolder {
	T value;
	template <class... ARGS> inputHolder(ARGS&&... args) {
		input(value, forward<ARGS>(args)...);
	}
	operator T() { return value; }
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
	operator int() { return MakeFromTuple<inputHolder<int>>(param); }
	operator double() { return MakeFromTuple<inputHolder<double>>(param); }
	operator string() { return MakeFromTuple<inputHolder<string>>(param); }
	operator char() { return MakeFromTuple<inputHolder<char>>(param); }
	template <class A, class B> operator pr<A, B>() { return MakeFromTuple<inputHolder<pr<A, B>>>(param); }
	template <class A, class B, class C> operator tr<A, B, C>() { return MakeFromTuple<inputHolder<tr<A, B, C>>>(param); }
	template <class T> operator arr<T>() { return MakeFromTuple<inputHolder<arr<T>>>(param); }
	template <class A, class B> operator dic<A, B>() { return MakeFromTuple<inputHolder<dic<A, B>>>(param); }
	template <class T> operator arr2<T>() { return MakeFromTuple<inputHolder<arr2<T>>>(param); }
};
struct inputObject {
	operator int() { return inputWithParam<>(); }
	operator double() { return inputWithParam<>(); }
	operator string() { return inputWithParam<>(); }
	operator char() { return inputWithParam<>(); }
	template <class A, class B> operator pr<A, B>() { return inputWithParam<>(); }
	template <class A, class B, class C> operator tr<A, B, C>() { return inputWithParam<>(); }
	template <class... ARGS> inputWithParam<ARGS...> operator()(ARGS&&... args) {
		inputWithParam<ARGS...> withParam(forward_as_tuple(args...));
		return withParam;
	}
} in;

//------------------------------------------------------------
#endif

struct MyMain {
	int N = in;
	int X = in;
	int M = in;

	void Run() {
		ints memo(M, -1);
		ints preAns(M, -1);
		ints preCnt(M, -1);
		int i = 0;
		int now = X;
		int ans = 0;
		bool end = false;
		while (i < N) {
			if (memo[now] < 0) {
				preAns[now] = ans;
				preCnt[now] = i;

				ans += now;
				i++;

				int next = (now * now) % M;
				memo[now] = next;
				now = next;
			}
			else {
				if (end == false) {
					end = true;
					int oneLoopAns = ans - preAns[now];
					int oneLoopCnt = i - preCnt[now];
					int cnt = (N - i) / oneLoopCnt;
					i += oneLoopCnt * cnt;
					ans += oneLoopAns * cnt;
				}
				else {
					ans += now;
					i++;
					now = memo[now];
				}
			}
		}

		out << ans;
	}
};
