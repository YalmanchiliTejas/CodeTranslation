/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
		  　　　　　　　　　　(¸.·´ (¸.·'* ☆
					*/

#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <queue>

#pragma GCC optimize("Ofast")
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
#define rep2(i, n) for(int i = 2; i < (n); ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define reprm(i, n) for(int i = n - 1; i >= 0; --i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printin(a) printf(a ? "possible\n" : "inposible\n")
#define printdb(a) printf("%.16f\n", a)//少数出力
#define all(x) (x).begin(), (x).end()
#define allsum(a, b, c) ((a + b) * c / 2)//等差数列の和、初項,末項,項数
#define pb push_back
#define priq priority_queue

using ll = long long;

const int INF = 2147483647;
const int MINF = -2147483648;
const ll LINF = ll(9223372036854775807);
const ll MOD = 1000000007;
const double PI = acos(-1);

//マクロとかここまで

using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll number1, ll number2) {//lcmを求める
	return number1 * number2 / gcd(number1, number2);
}

bool is_prime(int64_t x) {//素数判定
	for (int64_t i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

ll nearPow2(ll n)//x以上の2のべき乗を返す
{
	// nが0以下の時は0とする。
	if (n <= 0) return 0;

	// (n & (n - 1)) == 0 の時は、nが2の冪乗であるため、そのままnを返す。
	if ((n & (n - 1)) == 0) return ll(n);

	// bitシフトを用いて、2の冪乗を求める。
	ll ret = 1;
	while (n > 0) { ret <<= 1; n >>= 1; }
	return ret;
}



map< int64_t, int > prime_factor(int64_t n) {//素因数分解
	map< int64_t, int > ret;
	for (int64_t i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}

template< int mod >
struct ModInt {
	int x;

	ModInt() : x(0) {}

	ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

	ModInt& operator+=(const ModInt& p) {
		if ((x += p.x) >= mod) x -= mod;
		return *this;
	}

	ModInt& operator-=(const ModInt& p) {
		if ((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}

	ModInt& operator*=(const ModInt& p) {
		x = (int)(1LL * x * p.x % mod);
		return *this;
	}

	ModInt& operator/=(const ModInt& p) {
		*this *= p.inverse();
		return *this;
	}

	ModInt operator-() const { return ModInt(-x); }

	ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

	ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

	ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

	ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

	bool operator==(const ModInt& p) const { return x == p.x; }

	bool operator!=(const ModInt& p) const { return x != p.x; }

	ModInt inverse() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt pow(int64_t n) const {
		ModInt ret(1), mul(x);
		while (n > 0) {
			if (n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	friend ostream& operator<<(ostream& os, const ModInt& p) {
		return os << p.x;
	}

	friend istream& operator>>(istream& is, ModInt& a) {
		int64_t t;
		is >> t;
		a = ModInt< mod >(t);
		return (is);
	}

	static int get_mod() { return mod; }
};

using modint = ModInt< MOD >;//MOD=10億7

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

//nCrを1000000007で割った余りを求める
modint nCr(ll a, ll b) {
	modint ans = 1;
	for (ll i = 0; i < b; i++) {
		ans *= a - i;
	}
	for (ll i = 1; i <= b; i++) {
		ans *= modinv(i, MOD);
	}
	return ans;
}

void scans(string& str) {
	char s[1000000];
	scanf("%s", s);
	str = s;
}

/*-----------------------------------------ここまでライブラリとか-----------------------------------------*/

int main() {

	int n;
	scanf("%d", &n);
	printf("%d\n", n * 800 - 200 * (n / 15));

	return 0;
}
