#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

// MOD p でいくつクラス
#define MOD 1000000007 // 10^9 + 7
class mll {
	unsigned long long val = 0;
public:
	mll(long long y = 0) : val(((y % MOD) + MOD) % MOD) {}
	mll operator + (const mll& y) { return mll(*this) += y; }
	mll& operator += (const mll& y) {
		val = (val + y.val) % MOD;
		return *this;
	}
	mll operator - (const mll& y) { return mll(*this) -= y; }
	mll& operator -= (const mll& y) {
		val = (val - y.val + MOD) % MOD;
		return *this;
	}
	mll operator * (const mll& y) { return mll(*this) *= y; }
	mll& operator *= (const mll& y) {
		val = (val * y.val) % MOD;
		return *this;
	}
	mll operator / (const mll& y) { return mll(*this) /= y; }
	mll& operator /= (const mll& y) {
		long long a = y.val, b = MOD, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		mll c = val * u; // この計算でoverflowしないか？
		val = c.val;
		return *this;
	}
	bool operator >= (const mll& y) {
		return this->val >= y.val;
	}
	mll pow(long long t) const {
		if (!t) return 1;
		mll a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}
	unsigned long long getVal() {
		return val;
	}
	friend ostream& operator <<(ostream& os, mll& y) {
		os << y.val;
		return os;
	}
};
#undef MOD


int main() {
	int N;
	cin >> N;
	mll A = 0;
	mll A2 = 0;
	for(int i = 0; i < N; i++){
		ll a = 0;
		cin >> a;
		A += a;
		mll Ai = a;
		Ai *= a;
		A2 += Ai;
	}

	mll c = A * A - A2;
	c /= 2;

	cout << c.getVal() << endl;
	return(0);
}
