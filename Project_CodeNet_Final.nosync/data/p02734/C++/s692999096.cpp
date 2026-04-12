#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define int long long
#define ll long long
#define P pair<int,int>
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define all(V) V.begin(),V.end()
#ifdef int
constexpr int INF = LLONG_MAX / 10;
#else
constexpr int INF = INT_MAX / 10;
#endif
constexpr double eps = 1e-9;
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
using namespace std;
inline ll gcd(ll a, ll b) {
	while (b) {
		ll c = a;
		a = b; b = c % b;
	}
	return a;
}
inline ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
bool isprime(ll n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
ll mypow(ll a, ll b) {
	if (!b)return 1;
	if (b & 1)return mypow(a, b - 1) * a;
	ll memo = mypow(a, b >> 1);
	return memo * memo;
}
template<unsigned int modulo = 1000000007>
class modInt {
	ll value;
public:
	modInt() : value(0) {}
	template<typename T>
	modInt(T value = 0) : value(value) {
		if (value < 0)value = -(ll)(-value % modulo) + modulo;
		this->value = value % modulo;
	}
	inline operator int()const { return value; }
	inline modInt& operator+=(const modInt& x) {
		value += x.value;
		if (value >= modulo)value -= modulo;
		return *this;
	}
	inline modInt& operator++() {
		if (value == modulo - 1)value = 0;
		else value++;
		return *this;
	}
	inline modInt operator-()const {
		return modInt(0) -= *this;
	}
	inline modInt& operator-=(const modInt& x) {
		value -= x.value;
		if (value < 0)value += modulo;
		return *this;
	}
	inline modInt& operator--() {
		if (value == 0)value = modulo - 1;
		else value--;
		return *this;
	}
	inline modInt& operator*=(const modInt& x) {
		value = value * x.value % modulo;
		return *this;
	}
	inline modInt& operator/=(modInt rhs) {
		int exp = modulo - 2;
		while (exp) {
			if (exp & 1)*this *= rhs;
			rhs *= rhs;
			exp >>= 1;
		}
		return *this;
	}
	template<typename T> modInt operator+(const T& rhs)const { return modInt(*this) += rhs; }
	template<typename T> modInt& operator+=(const T& rhs) { return operator+=(modInt(rhs)); }
	template<typename T> modInt operator-(const T& rhs)const { return modInt(*this) -= rhs; }
	template<typename T> modInt& operator-=(const T& rhs) { return operator-=(modInt(rhs)); }
	template<typename T> modInt operator*(const T& rhs)const { return modInt(*this) *= rhs; }
	template<typename T> modInt& operator*=(const T& rhs) { return operator*=(modInt(rhs)); }
	template<typename T> modInt operator/(const T& rhs)const { return modInt(*this) /= rhs; }
	template<typename T> modInt& operator/=(const T& rhs) { return operator/=(modInt(rhs)); }
};
int n, s, a[3010];
int dp[3010];
signed main() {
	cin >> n >> s;
	rep(i, n)cin >> a[i];
	int ans = 0;
	dp[0] = 1;
	rep(i, n) {
		for (int j = s - a[i]; j >= 0; j--) {
			if (j == 0)dp[j + a[i]] += dp[j] * (i + 1) % 998244353;
			else dp[j + a[i]] += dp[j];
			dp[j + a[i]] %= 998244353;
		}
		ans += dp[s];
		ans %= 998244353;
	}
	cout << ans << endl;
	return 0;
}