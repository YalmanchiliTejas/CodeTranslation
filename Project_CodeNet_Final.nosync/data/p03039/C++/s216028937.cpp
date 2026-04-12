#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <list>
#include <utility>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <random>

using namespace std;

static const double EPS = 1e-9;
template<class T> bool INRANGE(T x, T a, T b) { return a <= x && x <= b; }
template<class T> void amin(T &a, T v) { if (a > v) a = v; }
template<class T> void amax(T &a, T v) { if (a < v) a = v; }
int ROUND(double x) { return (int)(x + 0.5); }
bool ISINT(double x) { return fabs(ROUND(x) - x) <= EPS; }
bool ISEQUAL(double x, double y) { return fabs(x - y) <= EPS * max(1.0, max(fabs(x), fabs(y))); }
double SQSUM(double x, double y) { return x * x + y * y; }
template<class T>
vector<T> make_vector(int n, T t) {
	return vector<T>(n, t);
}
 
template<class ...Ts>
auto make_vector(int n, Ts ... ts) {
	return vector<decltype(make_vector(ts...))>(n, make_vector(ts...));
}

#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG ((int)1e9+10)
#define BIGLL ((ll)4e18)
#define SZ(a) ((int)(a).size())
#define SQ(a) ((a)*(a))
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl

#define BitSet(arg,posn) ((arg) |= (1LL << (posn)))
#define BitClr(arg,posn) ((arg) &= ~(1LL << (posn)))
#define BitFlp(arg,posn) ((arg) ^= (1LL << (posn)))
#define IsBit(arg,posn) static_cast<bool>((arg) & (1LL << (posn)))

// #define DEBUG(x) cerr<<#x<<": "<<(x)<<endl
// #define DEBUG_VEC(v) cerr<<#v<<": ";REP(__i,(v).size())cerr<<((v)[__i])<<", ";cerr<<endl

typedef unsigned long long ull;
typedef long long ll;

struct in {
	int n;
	in() {}
	in(int n_) : n(n_) {};
	template <class T> operator T() {
		T ret;
		cin >> ret;
		return ret;
	}
	template <class T> operator vector<T>() {
		vector<T> ret(n);
		for (int i = 0; i < n; i++) cin >> ret[i];
		return ret;
	}
};

// modint: mod 計算を int を扱うように扱える構造体
template<int MOD>
struct ModInt {
	long long val;
	constexpr ModInt(long long v = 0) noexcept : val(v % MOD) {
		if (val < 0) v += MOD;
	}
	constexpr int getmod() { return MOD; }
	constexpr ModInt operator - () const noexcept {
		return val ? MOD - val : 0;
	}
	constexpr ModInt operator + (const ModInt& r) const noexcept { return ModInt(*this) += r; }
	constexpr ModInt operator - (const ModInt& r) const noexcept { return ModInt(*this) -= r; }
	constexpr ModInt operator * (const ModInt& r) const noexcept { return ModInt(*this) *= r; }
	constexpr ModInt operator / (const ModInt& r) const noexcept { return ModInt(*this) /= r; }
	constexpr ModInt& operator += (const ModInt& r) noexcept {
		val += r.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}
	constexpr ModInt& operator -= (const ModInt& r) noexcept {
		val -= r.val;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr ModInt& operator *= (const ModInt& r) noexcept {
		val = val * r.val % MOD;
		return *this;
	}
	constexpr ModInt& operator /= (const ModInt& r) noexcept {
		long long a = r.val, b = MOD, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr bool operator == (const ModInt& r) const noexcept {
		return this->val == r.val;
	}
	constexpr bool operator != (const ModInt& r) const noexcept {
		return this->val != r.val;
	}

	friend ostream& operator << (ostream &os, const ModInt<MOD>& x) noexcept {
		return os << x.val;
	}
	friend istream& operator >> (istream &is, ModInt<MOD>& x) noexcept {
		return is >> x.val;
	}
	friend constexpr ModInt<MOD> modpow(const ModInt<MOD> &a, long long n) noexcept {
		if (n == 0) return 1;
		auto t = modpow(a, n / 2);
		t = t * t;
		if (n & 1) t = t * a;
		return t;
	}
};

// 二項係数ライブラリ
template<class T> struct BiCoef
{
	constexpr BiCoef() {}
	constexpr BiCoef(int n) noexcept : mFact(n, 1), mInv(n, 1), mFInv(n, 1)
	{
		Init(n);
	}

	constexpr void Init(int n) noexcept
	{
		mFact.assign(n, 1), mInv.assign(n, 1), mFInv.assign(n, 1);
		int factMod = mFact[0].getmod();
		for (int i = 2; i < n; i++) {
			mFact[i] = mFact[i - 1] * i;
			mInv[i] = -mInv[factMod%i] * (factMod / i);
			mFInv[i] = mFInv[i - 1] * mInv[i];
		}
	}

	constexpr T Fact(int n) const noexcept {
		if (n < 0) return 0;
		return mFact[n];
	}

	constexpr T Comb(int n, int k) const noexcept {
		if (n < k || n < 0 || k < 0) return 0;
		return mFact[n] * mFInv[k] * mFInv[n - k];
	}

	constexpr T Perm(int n, int k) const noexcept {
		if (n < k || n < 0 || k < 0) return 0;
		return mFact[n] * mFInv[k] * mFInv[n - k];
	}

	constexpr T Homo(int n, int r) const {
		if (n < 0 || r < 0) return 0;
		return r == 0 ? 1 : Comb(n + r - 1, r);
	}

	constexpr T inv(int n) const noexcept {
		if (n < 0) return 0;
		return mInv[n];
	}

	constexpr T finv(int n) const noexcept {
		if (n < 0) return 0;
		return mFInv[n];
	}

	vector<T> mFact;
	vector<T> mInv;
	vector<T> mFInv;
};

const int MOD = 1000000007;
using mint = ModInt<MOD>;
BiCoef<mint> bc(1234567); // 1M * 3 * 8B(ll) = 24MB 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N, M, K;
	cin >> N >> M >> K;

	mint ret = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < M; ++k)
		{
			mint tmp = N - i;
			tmp *= M - k;
			tmp *= i + k;
			if (i != 0 && k != 0)
			{
				tmp *= 2;
			}

			ret += tmp;
		}
	}

	ret *= bc.Comb(N*M - 2, K - 2);
	cout << ret << endl;

	return 0;
}
