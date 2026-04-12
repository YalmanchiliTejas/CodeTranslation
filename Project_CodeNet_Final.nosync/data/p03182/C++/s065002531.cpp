#include <limits>
#include <vector>
#include <algorithm>

template<typename Type> class RangeAddMaxSegmentTree {
private:
	unsigned size_; std::vector<Type> dat1, dat2;
	inline void update_(unsigned a, unsigned b, Type x, unsigned k, unsigned l, unsigned r) {
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			dat2[k] += x; return;
		}
		update_(a, b, x, (k << 1), l, (l + r) >> 1);
		update_(a, b, x, (k << 1) + 1, (l + r) >> 1, r);
		dat1[k] = std::max(dat1[k << 1] + dat2[k << 1], dat1[(k << 1) + 1] + dat2[(k << 1) + 1]);
	}
	inline Type query_(unsigned a, unsigned b, unsigned k, unsigned l, unsigned r) {
		if (r <= a || b <= l) return std::numeric_limits<Type>::min();
		if (a <= l && r <= b) return dat1[k] + dat2[k];
		Type lc = query_(a, b, (k << 1), l, (l + r) >> 1);
		Type rc = query_(a, b, (k << 1) + 1, (l + r) >> 1, r);
		return std::max(lc, rc) + dat2[k];
	}
public:
	RangeAddMaxSegmentTree() : size_(0), dat1(std::vector<Type>()), dat2(std::vector<Type>()) {};
	RangeAddMaxSegmentTree(int size__) {
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

#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int> > > G(N);
	for (int i = 0; i < M; ++i) {
		int L, R, A;
		cin >> L >> R >> A;
		G[R - 1].push_back(make_pair(L - 1, A));
	}
	RangeAddMaxSegmentTree<long long> dp(N + 1);
	for (int i = 0; i < N; ++i) {
		dp.add(i + 1, dp.query(0, i + 1));
		for (pair<int, int> j : G[i]) {
			dp.add(j.first + 1, i + 2, j.second);
		}
	}
	long long ans = dp.query(0, N + 1);
	cout << ans << '\n';
	return 0;
}