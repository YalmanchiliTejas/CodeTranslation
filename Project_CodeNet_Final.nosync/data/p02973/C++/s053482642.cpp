#define MOD 10007

#if 1
//------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Entry { static void Run() { T().Run(); } };
struct MyMain;

//------------------------------------------------------------
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
	arr(ll n, T v = T()) : vector<T>(n, v) {}
	T& operator()(int i) { return (*this)[i]; }
	T const& operator()(int i) const { (*this)[i]; }
	void init(ll n, T v = T()) {
		this->clear();
		this->resize(n, v);
	}
	ll sz() const { return (ll)this->size(); }
	void pb(T v) { this->push_back(v); }
	void sort() { std::sort(this->begin(), this->end()); }
	template <class PREDICATE> void sort(PREDICATE p) { std::sort(this->begin(), this->end(), p); }
	void rsort() { std::sort(this->begin(), this->end(), greater<T>()); }
	void unique_erase() { this->erase(std::unique(this->begin(), this->end()), this->end()); }
	bool next_permutation() { return std::next_permutation(this->begin(), this->end()); }

	// これ以下はソート済み前提
	template <class P>
	int lower_bound(T const& v, P p) { return std::lower_bound(this->begin(), this->end(), v, p) - this->begin(); }
	int lower_bound(T const& v) { return std::lower_bound(this->begin(), this->end(), v) - this->begin(); }

	template <class P>
	int upper_bound(T const& v, P p) { return std::upper_bound(this->begin(), this->end(), v, p) - this->begin(); }
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
using intss = arr<arr<ll>>;

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

// 6角形グリッド用
const pints around6[2] = {
	{ pint(0, -1), pint(1, -1), pint(-1, 0), pint(1, 0), pint(0, 1), pint(1, 1) },
	{ pint(-1, -1), pint(0, -1), pint(-1, 0), pint(1, 0), pint(-1, 1), pint(0, 1) }
};

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

struct bfs {
	ints froms;
	ints steps;

	bfs(int N, intss const& adjacency) {
		froms.init(N, -1);
		steps.init(N, -1);

		que<ll> queue;
		queue.push(0);
		froms[0] = 0;
		steps[0] = 0;

		while (queue.empty() == false) {
			ll p = queue.popfront();

			for (ll n : adjacency[p]) {
				if (froms[n] != -1) {
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

template <class T, class F>
BfsResult bfs2(arr2<T> const& field, pint start, F canMove) {
	BfsResult result;
	result.froms.init(field.size(), pint(-1, -1));
	result.steps.init(field.size(), -1);

	que<pint> queue;
	queue.push(start);
	result.froms(start) = start;
	result.steps(start) = 0;

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

template <class PREDICATE>
int bsearch(int l, int r, PREDICATE p) {
	while (l < r) {
		int c = (l + r) / 2;

		if (p(c)) {
			r = c;
		}
		else {
			l = c + 1;
		}
	}

	return r;
}

// func(x)の極値となるxを返す
double num_analyze(function<double(double)> func, double l, double r, int step = 10000, double delta = 0.000001) {
	auto diff = [&](double x) {
		double a = func(x);
		double b = func(x + delta);
		return (b * b - a * a);
	};

	REP(i, step) {
		double c = (l + r) / 2.0;
		double d = diff(c);
		if (d < 0) {
			l = c;
		}
		else {
			r = c;
		}
	}
	return l;
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
struct LoopIndex {
	int const N;
	LoopIndex(int N_) : N(N_) { }

	int left(int i) {
		return (i - 1 + N) % N;
	}
	int right(int i) {
		return (i + 1) % N;
	}
};

//------------------------------------------------------------
#if defined(TEST)
extern istream& myInputStream;
extern ostream& myOutputStream;
#else
istream& myInputStream = cin;
ostream& myOutputStream = cout;
#endif

struct input_base {
	template <class T>
	static T exec() {
		T var;
		myInputStream >> var;
		return var;
	}

	operator char() { return input_base::exec<char>(); }
	operator int() { return input_base::exec<int>(); }
	operator double() { return input_base::exec<double>(); }
	operator string() { return input_base::exec<string>(); }

	template <class K, class V>
	operator pr<K, V>() { return input_base::exec<pr<K, V>>(); }

	template <class K, class V>
	operator pair<K, V>() {
		pair<K, V> p;
		p.first = input_base::exec<K>();
		p.second = input_base::exec<V>();
		return p;
	}
};

struct inputs {
	ll n;
	inputs(ll n_) : n(n_) {}

	template <class T>
	operator arr<T>() {
		arr<T> var(n);
		REP(i, n) {
			var[i] = input_base();
		};
		return var;
	}

	template <class K, class V>
	operator dic<K, V>() {
		dic<K, V> var;
		REP(i, n) {
			pair<K, V> p = input_base();
			var.insert(p);
		};
		return var;
	}
};

struct inputss {
	ll H;
	ll W;
	inputss(int H_, int W_) : H(H_), W(W_) {}

	template <class T>
	operator arr2<T>() {
		arr2<T> var(W, H);
		REP(y, H) {
			REP(x, W) {
				var(x, y) = input_base();
			};
		}
		return var;
	}
};

struct input {
	operator int() { return input_base(); }
	operator double() { return input_base(); }
	operator string() { return input_base(); }
	template <class K, class V> operator pr<K, V>() { return input_base(); }
	template <class K, class V> operator pair<K, V>() { return input_base(); }
	inputs operator()(int n) { return inputs(n); }
	inputss operator()(int H, int W) { return inputss(H, W); }
} input;

template <class T>
auto output(T var) -> decltype(myOutputStream << var) {
	myOutputStream << var << '\n';
	return myOutputStream;
}

template <class H, class... T>
auto output(H&& head, T&&... tail) -> decltype(myOutputStream << head)
{
	myOutputStream << head << " ";
	output(forward<T>(tail)...);
	return myOutputStream;
}

template <class T>
auto output(arr<T> const& var) -> ostream& {
	for (int i = 0; i < var.sz() - 1; ++i) {
		myOutputStream << var[i] << ' ';
	}
	if (var.sz() > 0) {
		myOutputStream << var[var.sz() - 1] << '\n';
	}
	else {
		myOutputStream << '\n';
	}
	return myOutputStream;
}

//------------------------------------------------------------

template <class T, bool = is_class<T>::value> struct inputvar;
template <class T>
struct inputvar<T, false> {
	T var;
	inputvar() { var = input; }
	operator T() const { return var; }
};
template <class T>
struct inputvar<T, true> : public T {
	inputvar() : T(input.operator T()) { }
	inputvar(int a) : T(input(a).operator T()) {}
	inputvar(int a, int b) : T(input(a, b).operator T()) {}
};

struct i_int : public inputvar<int> {
	i_int() {}
	i_int(int add) { var += add; }
};

struct i_pint : public inputvar<pint> {
	i_pint() {}
	i_pint(int add) {
		x += add;
		y += add;
	}
	i_pint(int add, bool flip) {
		x += add;
		y += add;
		if (flip) {
			swap(x, y);
		}
	}
};

struct i_ints : public inputvar<ints> {
	i_ints(int N) : inputvar<ints>(N) {}
	i_ints(int N, int add) : inputvar<ints>(N) {
		REP(i, this->sz()) {
			(*this)[i] += add;
		}
	}
};

struct i_pints : public inputvar<pints> {
	i_pints(int N) : inputvar<pints>(N) {}
	i_pints(int N, int add) : inputvar<pints>(N) {
		REP(i, this->sz()) {
			(*this)[i].a += add;
			(*this)[i].b += add;
		}
	}
	i_pints(int N, int add, bool flip) : inputvar<pints>(N) {
		REP(i, this->sz()) {
			(*this)[i].a += add;
			(*this)[i].b += add;
			if (flip) {
				::swap((*this)[i].a, (*this)[i].b);
			}
		}
	}
};

template <class K, class V>
struct i_dic : public inputvar<dic<K, V>> {
	i_dic(int N) : inputvar<dic<K, V>>(N) {}
};

template <class T>
struct i_arr2 : public inputvar<arr2<T>> {
	i_arr2(int H, int W) : inputvar<arr2<T>>(H, W) {}
};

struct i_string : public inputvar<string> {
	i_string() {}
};

//------------------------------------------------------------
#endif

struct MyMain {
	i_int N;
	i_ints A{ N };

	void Run() {
		ints CV(N, INT64_MAX);

		int maxC = 0;
		RREP(i, N) {
			int c = CV.upper_bound(A[i]);
			CV[c] = A[i];
			chmax(maxC, c);
		}

		int ans = maxC + 1;
		output(ans);
	}
};

