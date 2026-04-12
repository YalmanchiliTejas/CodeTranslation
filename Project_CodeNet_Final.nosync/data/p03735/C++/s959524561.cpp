#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename Type> class RangeMin {
private:
	int size_;
	std::vector<Type> dat;
public:
	RangeMin() : size_(0), dat(std::vector<Type>()) {};
	RangeMin(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat.resize(size_ << 1, std::numeric_limits<Type>::max() / 2);
	}
	template<class T>
	RangeMin(T begin_, T end_) {
		int n = end_ - begin_;
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, std::numeric_limits<Type>::max() / 2);
		for (int i = 0; i < n; i++) dat[i + size_] = *(begin_ + i);
		for (int i = size_ - 1; i > 0; i--) dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
	}
	inline unsigned size() { return size_; }
	inline void update(int i, Type x) {
		i += size_; dat[i] = x;
		while (i > 1) {
			i >>= 1;
			dat[i] = std::min(dat[i << 1], dat[i << 1 | 1]);
		}
	}
	inline Type query(int l, int r) {
		Type ret = std::numeric_limits<Type>::max() / 2;
		l += size_; r += size_;
		while (l != r) {
			if (l & 1) ret = std::min(ret, dat[l++]); l >>= 1;
			if (r & 1) ret = std::min(ret, dat[--r]); r >>= 1;
		}
		return ret;
	}
};

long long N, X[200009], Y[200009]; vector<pair<long long, long long>>E;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i]; if (X[i] > Y[i]) swap(X[i], Y[i]);
		E.push_back(make_pair(X[i], Y[i]));
	}
	sort(E.begin(), E.end());

	RangeMin<long long> LX(N + 2), LY(N + 2), RX(N + 2), RY(N + 2);

	for (int i = 0; i < N; i++) {
		X[i] = E[i].first; Y[i] = E[i].second;
		LX.update(i, X[i]); LY.update(i, Y[i]);
		RX.update(i, -X[i]); RY.update(i, -Y[i]);
	}
	long long ans = (1LL << 60);
	for (int i = 0; i < N; i++) {
		long long LA = min(LX.query(0, i), LY.query(i, N));
		long long RA = min(RX.query(0, i), RY.query(i, N)) * -1LL;
		long long LB = min(LY.query(0, i), LX.query(i, N));
		long long RB = min(RY.query(0, i), RX.query(i, N)) * -1LL;
		ans = min(ans, (RA - LA)*(RB - LB));
	}
	cout << ans << endl;
	return 0;
}