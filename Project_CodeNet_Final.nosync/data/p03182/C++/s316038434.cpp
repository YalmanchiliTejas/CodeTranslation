#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
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

long long N, M, L[1 << 18], R[1 << 18], A[1 << 18], dp[1 << 18], sum;
vector<pair<long long, long long>>G[1 << 18];

int main() {
	cin >> N >> M;
	StarrySkyTree<long long>X(N + 5);
	for (int i = 0; i < M; i++) { cin >> L[i] >> R[i] >> A[i]; sum += A[i]; G[R[i]].push_back(make_pair(L[i], A[i])); }

	X.add(0, 0);
	for (int i = 1; i <= N; i++) {
		dp[i] = X.query(0, i); X.add(i, dp[i]);
		for (int j = 0; j < G[i].size(); j++) {
			X.add(0, G[i][j].first, G[i][j].second);
		}
	}
	long long minx = 0; for (int i = 0; i <= N; i++) minx = min(minx, X.query(i, i + 1));
	cout << sum - minx << endl;
	return 0;
}