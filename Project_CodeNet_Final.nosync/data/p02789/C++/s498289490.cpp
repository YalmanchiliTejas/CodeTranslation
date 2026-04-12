#include <bits/stdc++.h>

#define IMPL_SERIALIZE_2(type, e0, e1) \
	inline ostream& operator<<(ostream& out, type const& obj) { \
		return out << #type " { " #e0 " = " << obj.e0 << ", " #e1 " = " << obj.e1 << " }"; \
	} \
	inline istream& operator>>(istream& in, type& obj) { \
		return in >> obj.e0 >> obj.e1; \
	}

#define IMPL_SERIALIZE_3(type, e0, e1, e2) \
	inline ostream& operator<<(ostream& out, type const& obj) { \
		return out << #type " { " #e0 " = " << obj.e0 << ", " #e1 " = " << obj.e1 << ", " #e2 " = " << obj.e2 << " }"; \
	} \
	inline istream& operator>>(istream& in, type& obj) { \
		return in >> obj.e0 >> obj.e1 >> obj.e2; \
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
T pow_int(T const a, sint const n) {
	if (n == 0) {
		return T(1);
	}
	T const h = pow_int(a, n / 2);
	T const f = h * h;
	return n % 2 == 1 ?  a * f : f;
}

template<sint P>
struct ModInt {
	explicit ModInt(sint const m): n(mod(m, P)) {
	}

	explicit operator sint() const {
		return n;
	}

	sint const n;
};

template<sint P>
ostream& operator<<(ostream& out, ModInt<P> const rhs) {
	return out << rhs.n;
}

template<sint P>
istream& operator>>(istream& in, ModInt<P>& rhs) {
	sint tmp;
	in >> tmp;
	rhs = ModInt<P>(tmp);
	return in;
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
	return lhs * pow_int(rhs, P - 2);
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
struct array2 {
	array2() = default;

	explicit array2(sint const sx_, sint const sy_):
		sx(sx_), sy(sy_), data(make_unique<T[]>(sx_ * sy_))
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

	unique_ptr<T[]> const data;
	sint const sx = 0;
	sint const sy = 0;
};

template<class T>
ostream& operator<<(ostream& out, array2<T> const& arr) {
	for (sint y = 0; y < arr.sy; ++y) {
		for (sint x = 0; x < arr.sx; ++x) {
			out << ' ' << arr(x, y);
		}
		out << '\n';
	}
	return out;
}

template<class T>
istream& operator>>(istream& in, array2<T> const& arr) {
	for (sint y = 0; y < arr.sy; ++y) {
		for (sint x = 0; x < arr.sx; ++x) {
			in >> arr(x, y);
		}
	}
	return in;
}

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
	sint N; cin >> N;
	sint M; cin >> M;
	if (N == M) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}