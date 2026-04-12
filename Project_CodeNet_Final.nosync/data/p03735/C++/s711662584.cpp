#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<tuple>
#include<cstdio>
using namespace std;
#pragma warning(disable:4996)

//=========================================================================
//=========================================================================
//=========================================================================
template<typename Type> class RMQ {
private:
	unsigned size_; std::vector<Type> dat;
	inline Type query_(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return std::numeric_limits<Type>::max();
		if (a <= l && r <= b) return dat[k];
		Type lc = query_(a, b, (k << 1), l, (l + r) >> 1);
		Type rc = query_(a, b, (k << 1) + 1, (l + r) >> 1, r);
		return std::min(lc, rc);
	}
public:
	RMQ() : size_(0), dat(std::vector<Type>()) {};
	RMQ(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat.resize(size_ << 1, std::numeric_limits<Type>::max());
	}
	template<class T>
	RMQ(T begin_, T end_) {
		int n = end_ - begin_;
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, std::numeric_limits<Type>::max());
		for (int i = 0; i < n; i++) dat[i + size_] = *(begin_ + i);
		for (int i = size_ - 1; i > 0; i--) dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
	}
	inline unsigned size() { return size_; }
	inline void update(int i, Type x) {
		i += size_; dat[i] = x;
		while (i > 1) {
			i >>= 1;
			dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
		}
	}
	inline Type query(int l, int r) {
		return query_(l, r, 1, 0, size_);
	}
};
//=========================================================================
//=========================================================================
//=========================================================================

long long n, a[300000], b[300000]; vector<pair<long long, long long>>E;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { scanf("%lld%lld", &a[i], &b[i]); if (a[i] > b[i])swap(a[i], b[i]); }

	//----------------------------パターン１：最大と最小それぞれを赤と青でカバーする---------------------------
	long long r1 = (1LL << 30), r2 = -(1LL << 30), r3 = (1LL << 30), r4 = -(1LL << 30);
	for (int i = 0; i < n; i++) {
		r1 = min(r1, a[i]); r2 = max(r2, a[i]); r3 = min(r3, b[i]); r4 = max(r4, b[i]);
	}
	long long ret1 = 1LL * (r2 - r1)*(r4 - r3);

	//-----------------パターン２：最大と最小両方を赤がカバーする：bmax-bminの最小値を求める-------------------

	//平面走査とＲＭＱでごり押し！！常勝！！！！
	RMQ<long long>X(n);
	for (int i = 0; i < n; i++) { E.push_back(make_pair(a[i], i)); E.push_back(make_pair(b[i], i)); }
	sort(E.begin(), E.end());

	long long ret2 = (1LL << 60);
	for (int i = 0; i < n; i++)X.update(i, -(1LL << 60));

	for (int i = 0; i < E.size(); i++) {
		long long p1 = E[i].first, p2 = E[i].second;
		X.update(p2, p1);
		ret2 = min(ret2, p1 - X.query(0, n));
	}
	ret2 *= (r4 - r1);

	cout << min(ret1, ret2) << endl;
	return 0;
}