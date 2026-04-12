#include <cassert>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<(DUMP(),__VA_ARGS__).str()<<endl)

struct DUMP : ostringstream {
	template<class T> DUMP &operator,(const T &t) {
		if(this->tellp()) *this << ", ";
		*this << t;
		return *this; 
	}
};

template<class Iterator>
ostream &dump_range(ostream &os, Iterator first, const Iterator &last) {
	os << '[';
	for(int i = 0; first != last; ++i, ++first) {
		if(i) os << ", ";
		os << *first;
	}
	return os << ']';
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &c) {
	return dump_range(os, c.cbegin(), c.cend());
}

typedef int type;
constexpr type INIT = (1 << 28);

class segment_tree {
private:
	int n;
	vector<type> value;
	vector<type> lazy;

	type function(type a, type b) {
		return min(a, b);
	}

	void evaluate(int k, int number_of_children) {
		if(lazy[k] == 0) return;
		if(number_of_children > 1) {
			lazy[k * 2 + 1] += lazy[k];
			lazy[k * 2 + 2] += lazy[k];
		}

		value[k] += lazy[k];
		lazy[k] = 0;
	}

	// [a, b)にvを加える
	void add(int a, int b, type v, int k, int l, int r) {
		if(r <= a || b <= l) return;
		if(a <= l && r <= b) {
			lazy[k] += v;
		}
		else {
			const int m = (l + r) / 2;
			evaluate(k, r - l);
			add(a, b, v, k * 2 + 1, l, m);
			add(a, b, v, k * 2 + 2, m, r);
			value[k] = function(query(l, m, k * 2 + 1, l, m), query(m, r, k * 2 + 2, m, r));
		}
	}

	type query(int a, int b, int k, int l, int r) {
		if(r <= a || b <= l) return INIT;
		evaluate(k, r - l);
		if(a <= l && r <= b) return value[k];

		const int m = (l + r) / 2;
		const type vl = query(a, b, k * 2 + 1, l, m);
		const type vr = query(a, b, k * 2 + 2, m, r);
		return function(vl, vr);
	}

public:
	segment_tree(int n_):n(1) {
		while(n < n_) n <<= 1;
		value.resize(2 * n - 1, INIT);
		lazy.resize(2 * n - 1, 0);
	}

	segment_tree(const vector<int> &a):n(1) {
		const int n_ = a.size();
		while(n < n_) n <<= 1;
		value.resize(2 * n - 1, INIT);
		lazy.resize(2 * n - 1, 0);

		for(int i = 0; i < n_; ++i) {
			value[i + n - 1] = a[i];
		}

		for(int i = n - 2; i >= 0; --i) {
			value[i] = function(value[2 * i + 1], value[2 * i + 2]);
		}
	}

	void add(int a, int b, type v) {
		add(a, b, v, 0, 0, n);
	}

	type query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	void print() {
		for(const auto &e : value) {
			cout << e << " ";
		}
		cout << endl;
	}
};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	set<int> S;

	int sum = 0;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		if(s[i] == '(') {
			++sum;
		}
		else {
			--sum;
			S.insert(i);
		}

		a[i] = sum;
	}

	segment_tree seg(a);

	while(q--) {
		int p;
		cin >> p;
		--p;

		if(s[p] == '(') {
			s[p] = ')';
			S.insert(p);
			seg.add(p, n, -2);

 			const int res = *S.begin();

			assert(s[res] == ')');

			s[res] = '(';
			S.erase(res);
			seg.add(res, n, 2);

			cout << res + 1 << endl;
		}
		else {
			s[p] = '(';
			S.erase(p);
			seg.add(p, n, 2);

			int L = 0, R = p;
			while(L + 1 < R) {
				const int M = (L + R) / 2;

				if(seg.query(M, p) <= 1) {
					L = M;
				}
				else {
					R = M;
				}
			}

			s[R] = ')';
			S.insert(R);
			seg.add(R, n, -2);

			cout << R + 1 << endl;
		}
	}

	return EXIT_SUCCESS;
}