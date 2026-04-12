#include <bits/stdc++.h>

#define IMPL_SERIALIZE_2(type, e0, e1) \
	inline ostream& operator<<(ostream& out, type const& obj) { \
		return out << #type " { " #e0 " = " << obj.e0 << ", " #e1 " = " << obj.e1 << " }"; \
	} \
	inline istream& operator>>(istream& in, type& obj) { \
		return in >> obj.e0 >> obj.e1; \
	}

#define IMPL_OP_LESS_2(type, e0, e1) \
	inline istream& operator<(type const& lhs, type const& rhs) { \
		return tie(obj.e0, obj.e1) < tie(obj.e0, obj.e1); \
	}

#define IMPL_SERIALIZE_3(type, e0, e1, e2) \
	inline ostream& operator<<(ostream& out, type const& obj) { \
		return out << #type " { " #e0 " = " << obj.e0 << ", " #e1 " = " << obj.e1 << ", " #e2 " = " << obj.e2 << " }"; \
	} \
	inline istream& operator>>(istream& in, type& obj) { \
		return in >> obj.e0 >> obj.e1 >> obj.e2; \
	}

#define IMPL_OP_LESS_3(type, e0, e1, e2) \
	inline istream& operator<(type const& lhs, type const& rhs) { \
		return tie(obj.e0, obj.e1, obj.e2) < tie(obj.e0, obj.e1, obj.e2); \
	}

using namespace std;
using sint = int64_t;

constexpr sint sint_min = numeric_limits<sint>::min();
constexpr sint sint_max = numeric_limits<sint>::max();

template<class T>
sint isize(T const& obj) {
	return sint(obj.size());
}

template<class T>
ostream& operator<<(ostream& out, vector<T> const& rhs) {
	if (rhs.size() > 0) {
		out << rhs[0];
	}
	for (size_t i = 1; i < rhs.size(); ++i) {
		out << ' ' << rhs[i];
	}
	return out;
}

template<class T>
istream& operator>>(istream& in, vector<T>& rhs) {
	for (T& e: rhs) {
		in >> e;
	}
	return in;
}

inline sint gcd(sint y, sint x) {
	while (x != 0) {
		sint const t = y % x;
		y = x;
		x = t;
	}
	return y;
}

inline sint div_floor(sint const y, sint const x) {
	assert(x > 0);
	sint const r = y / x;
	return r * x <= y ? r : r - 1;
}

inline sint mod(sint const a, sint const p) {
	return a - p * div_floor(a, p);
}

template<class T>
T powi(T const a, sint const n) {
	if (n == 0) {
		return T(1);
	}
	T const h = powi(a, n / 2);
	T const f = h * h;
	return n % 2 == 1 ? a * f : f;
}

template<class T>
T combination(sint n, sint k) {
	T r(1);
	for (sint i = 0; i < k; ++i) {
		r = r * T(n - i) / T(1 + i);
	}
	return r;
}

template<sint P>
struct ModInt {
	ModInt() = default;
	ModInt(ModInt const&) = default;
	ModInt& operator=(ModInt const&) = default;

	explicit ModInt(sint const m): n(mod(m, P)) {
	}

	explicit operator sint() const {
		return n;
	}

	sint n;
};

template<sint P>
ostream& operator<<(ostream& out, ModInt<P> const rhs) {
	return out << rhs.n;
}

template<sint P>
istream& operator>>(istream& in, ModInt<P>& rhs) {
	return in >> rhs.n;
}

template<sint P>
ModInt<P> operator+(ModInt<P> const lhs) {
	return ModInt<P>(+lhs.n);
}

template<sint P>
ModInt<P> operator-(ModInt<P> const lhs) {
	return ModInt<P>(-lhs.n);
}

template<sint P>
ModInt<P> operator+(ModInt<P> const lhs, ModInt<P> const rhs) {
	return ModInt<P>(lhs.n + rhs.n);
}

template<sint P>
ModInt<P> operator-(ModInt<P> const lhs, ModInt<P> const rhs) {
	return ModInt<P>(lhs.n - rhs.n);
}

template<sint P>
ModInt<P> operator*(ModInt<P> const lhs, ModInt<P> const rhs) {
	return ModInt<P>(lhs.n * rhs.n);
}

template<sint P>
ModInt<P> operator/(ModInt<P> const lhs, ModInt<P> const rhs) {
	return lhs * powi(rhs, P - 2);
}

template<class T>
struct Factorial {
	explicit Factorial(sint const n) {
		T r(1);
		_table.push_back(r);
		for (sint i = 1; i < n; ++i) {
			r = r * T(i);
			_table.push_back(r);
		}
	}

	T factorial(sint const n) const {
		assert(0 <= n && n < isize(_table));
		return _table[n];
	}

	T combination(sint const n, sint const k) const {
		return factorial(n) / (factorial(k) * factorial(n - k));
	}

private:
	vector<T> _table;
};

template<class T>
struct Array2 {
	Array2() = default;

	Array2(sint const sx, sint const sy):
		sx(sx), sy(sy), data(make_unique<T[]>(sx * sy))
	{
		assert(0 <= sx);
		assert(0 <= sy);
	}

	T const& operator()(sint const x, sint const y) const {
		assert(0 <= x && x < sx);
		assert(0 <= y && y < sy);
		return data[y * sx + x];
	}

	T& operator()(sint const x, sint const y) {
		assert(0 <= x && x < sx);
		assert(0 <= y && y < sy);
		return data[y * sx + x];
	}

	T* begin() {
		return data.get();
	}

	T* end() {
		return data.get() + sx * sy;
	}

	sint const sx = 0;
	sint const sy = 0;
	unique_ptr<T[]> const data;
};

template<class T>
ostream& operator<<(ostream& out, Array2<T> const& arr) {
	for (sint y = 0; y < arr.sy; ++y) {
		for (sint x = 0; x < arr.sx; ++x) {
			out << ' ' << arr(x, y);
		}
		out << '\n';
	}
	return out;
}

template<class T>
istream& operator>>(istream& in, Array2<T>& arr) {
	for (sint y = 0; y < arr.sy; ++y) {
		for (sint x = 0; x < arr.sx; ++x) {
			in >> arr(x, y);
		}
	}
	return in;
}

struct UnionFind {
	struct Vertex {
		sint parent;
		sint size;
	};

	UnionFind(sint const size) {
		for (sint i = 0; i < size; ++i) {
			vertices.push_back({i, 1});
		}
	}

	void unite(sint const x, sint const y) {
		assert(0 <= x && x < isize(vertices));
		assert(0 <= y && y < isize(vertices));
		sint rx = root(x);
		sint ry = root(y);
		if (rx == ry) {
			return;
		}
		vertices[rx].parent = ry;
		vertices[ry].size += vertices[rx].size;
	}

	bool is_same(sint const x, sint const y) {
		assert(0 <= x && x < isize(vertices));
		assert(0 <= y && y < isize(vertices));
		return root(x) == root(y);
	}

	sint size(sint const x) {
		assert(0 <= x && x < isize(vertices));
		return vertices[root(x)].size;
	}

	sint root(sint const x) {
		assert(0 <= x && x < isize(vertices));
		if (vertices[x].parent == x) {
			return x;
		}
		vertices[x].parent = root(vertices[x].parent);
		return vertices[x].parent;
	}

	vector<Vertex> vertices;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin .exceptions(ios_base::badbit | ios_base::failbit);
	cout.exceptions(ios_base::badbit | ios_base::failbit);
	cin .tie(nullptr);
	cout.tie(nullptr);
	cout.precision(16);
	void run();
	run();
	return 0;
}

void run() {
	string S;
	cin >> S;
	if (S == "AAA" || S == "BBB") {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}
}