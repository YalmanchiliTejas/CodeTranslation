#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <utility>


using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { a = abs(a), b = abs(b); while (b > 0) { tie(a, b) = make_pair(b, a % b); } return a; }


constexpr long long INF = 1LL << 60;
constexpr int inf = 1000000007;
constexpr long long mod = 1000000007LL;
//constexpr long long mod = 998244353LL;

struct mint {
	long long x;
	mint(long long x = 0) :x((x% mod + mod) % mod) {}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res *= a;
	}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const {
		return pow(mod - 2);
	}
	mint& operator/=(const mint a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint a) const {
		mint res(*this);
		return res /= a;
	}
};

int main()
{

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	ll n; cin >> n;
	vector<ll> a(n); for (int i = 0; i < n; i++) cin >> a[i];
	vector<mint> sum(n + 1); for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
	mint res = 0;
	for (int i = 0; i + 1< n; i++) {
		res += (sum.back() - sum[i + 1]) * a[i];
	}
	cout << res.x << endl;
	return 0;
}