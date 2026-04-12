#ifndef ___Class_BIT
#define ___Class_BIT

// ------ Includes ------ //
#include <vector>
#pragma warning(disable : 4146)

// ------ Class ------ //
template <typename Type>
class BIT {
private:
	unsigned size_; std::vector<Type> v;
	Type sum(unsigned r) {
		Type ret = 0;
		while (r > 0) {
			ret += v[r];
			r -= r & (-r);
		}
		return ret;
	}
public:
	BIT() {};
	BIT(unsigned size__) {
		for (size_ = 1; size_ < size__;) size_ <<= 1;
		v.resize(size_ + 1, 0);
	}
	inline void add(unsigned i, Type x) {
		i++;
		while (i <= size_) {
			v[i] += x;
			i += i & -i;
		}
	}
	inline Type sum(unsigned l, unsigned r) {
		return sum(r) - sum(l);
	}
	bool operator[](unsigned x) {
		return sum(x, x + 1);
	}
};

#endif

#ifndef ___Class_StarrySkyTree
#define ___Class_StarrySkyTree

// ------ Includes ------ //
#include <limits>
#include <vector>
#include <algorithm>

// ------ Starry Sky Tree Class ------ //
template<typename Type> class StarrySkyTree {
private:
	unsigned size_; std::vector<Type> dat1, dat2;
	inline void update_(unsigned a, unsigned b, Type x, unsigned k, unsigned l, unsigned r) {
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			dat2[k] += x; return;
		}
		update_(a, b, x, (k << 1), l, (l + r) >> 1);
		update_(a, b, x, (k << 1) + 1, (l + r) >> 1, r);
		dat1[k] = std::min(dat1[k << 1] + dat2[k << 1], dat1[(k << 1) + 1] + dat2[(k << 1) + 1]);
	}
	inline Type query_(unsigned a, unsigned b, unsigned k, unsigned l, unsigned r) {
		if (r <= a || b <= l) return std::numeric_limits<Type>::max();
		if (a <= l && r <= b) return dat1[k] + dat2[k];
		Type lc = query_(a, b, (k << 1), l, (l + r) >> 1);
		Type rc = query_(a, b, (k << 1) + 1, (l + r) >> 1, r);
		return std::min(lc, rc) + dat2[k];
	}
public:
	StarrySkyTree() : size_(0), dat1(std::vector<Type>()), dat2(std::vector<Type>()) {};
	StarrySkyTree(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat1.resize(size_ << 1, 0);
		dat2.resize(size_ << 1, 0);
	}
	inline unsigned size() { return size_; }
	inline void add(unsigned i, Type x) {
		update_(i, i + 1, x, 1, 0, size_);
	}
	inline void add(unsigned l, unsigned r, Type x) {
		update_(l, r, x, 1, 0, size_);
	}
	inline Type query(unsigned l, unsigned r) {
		return query_(l, r, 1, 0, size_);
	}
};

#endif

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Q, x; string s;
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> Q >> s;
	BIT<int> r1(N);
	StarrySkyTree<int> r2(N);
	for (int i = 0; i < N; i++) {
		r1.add(i, s[i] == '(' ? 1 : -1);
		r2.add(i, N, s[i] == '(' ? 1 : -1);
	}
	for (int i = 0; i < Q; i++) {
		cin >> x; x--;
		if (s[x] == '(') {
			r1.add(x, -2); s[x] = ')';
			r2.add(x, N, -2);
			int l = 0, r = N + 1;
			while (r - l > 1) {
				int m = (l + r) / 2;
				int res = r1.sum(0, m);
				if (res != m) r = m;
				else l = m;
			}
			r1.add(l, 2); s[l] = '(';
			r2.add(l, N, 2);
			cout << l + 1 << endl;
		}
		else {
			r1.add(x, 2); s[x] = '(';
			r2.add(x, N, 2);
			int l = 0, r = N;
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (r2.query(m, N) >= 2) r = m;
				else l = m;
			}
			r1.add(r, -2); s[r] = ')';
			r2.add(r, N, -2);
			cout << r + 1 << endl;
		}
	}
	return 0;
}