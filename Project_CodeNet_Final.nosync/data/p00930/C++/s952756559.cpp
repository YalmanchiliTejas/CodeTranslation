#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template<typename Type> class StarrySkyTree {
public:
	unsigned size_; std::vector<Type> dat1, dat2, dat;
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
	//StarrySkyTree() : size_(0), dat(std::vector<Type>()) {};
	StarrySkyTree(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat1.resize(size_ << 1, 0);
		dat2.resize(size_ << 1, 0);
		dat.resize(size_ << 1, 0);
	}
	template<class T>
	StarrySkyTree(T begin_, T end_) {
		unsigned n = (end_ - begin_);
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, std::numeric_limits<Type>::max());
		for (unsigned i = 0; i < n; i++) dat[i + size_] = *(begin_ + i);
		for (unsigned i = size_ - 1; i > 0; i--) dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
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

string S; int N, Q, P;
StarrySkyTree<int> X(1);

int solve(int pos) {
	int I1 = X.query(pos, pos + 1); // pos の depth
	int I2 = X.query(pos + 1, pos + 2); // pos + 1 の depth

	if (I1 > I2) {
		// もともと ')' だった : ')' -> '('
		X.add(pos + 1, N + 1, 2);
		int L = 0, R = N + 1, M, minx = N + 1;
		for (int i = 0; i < 20; i++) {
			M = (L + R) / 2;
			int B = X.query(M, N + 1);
			if (B >= 2) { minx = min(minx, M); R = M; }
			else { L = M; }
		}
		X.add(minx, N + 1, -2);
		return minx - 1;
	}
	else {
		// もともと '(' だった : '(' -> ')'
		X.add(pos + 1, N + 1, -2);
		int L = 0, R = N + 1, M, minx = N + 1;
		for (int i = 0; i < 20; i++) {
			M = (L + R) / 2;
			int B = X.query(M, M + 1);
			if (M != B) { minx = min(minx, M); R = M; }
			else { L = M; }
		}
		X.add(minx, N + 1, 2);
		return minx - 1;
	}
}

int main() {
	cin >> N >> Q >> S;
	X = StarrySkyTree<int>(N + 1);
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') X.add(i + 1, N + 1, 1);
		if (S[i] == ')') X.add(i + 1, N + 1, -1);
	}
	for (int i = 1; i <= Q; i++) {
		cin >> P; P--;
		cout << solve(P) + 1 << endl;
	}
	return 0;
}
