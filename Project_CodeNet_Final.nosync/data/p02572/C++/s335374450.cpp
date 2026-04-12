#include <iostream>
#include <array>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <cmath>
#include <stack>
#include <queue>
#include <climits>
#include <string.h>
#include <cctype>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

long long gcd(long long a, long long b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}

long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
	ll x; // typedef long long ll;
	mint(ll x = 0) :x((x% mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const { return pow(mod - 2); }
	mint& operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

struct combination {
	vector<mint> fact, ifact;
	combination(int n) :fact(n + 1), ifact(n + 1) {
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
		ifact[n] = fact[n].inv();
		for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
	}
	mint operator()(int n, int k) {
		if (k < 0 || k > n) return 0;
		return fact[n] * ifact[k] * ifact[n - k];
	}
} comb(2000005);

mint g(int r, int c) {
	return comb(r + c + 2, r + 1) - 1;
}

bool comp(int i, int j) {
	return i > j;
}

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

long tall[200000];
long long diff[200000];
vector<int> que;

// index が条件を満たすかどうか
bool isOK(int index, int key) {
	if (que[index] >= key) return true;
	else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
	int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
	int right = (int)que.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	/* どんな二分探索でもここの書き方を変えずにできる！ */
	while (right - left > 1) {
		int mid = left + (right - left) / 2;

		if (isOK(mid, key)) right = mid;
		else left = mid;
	}

	/* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
	return right;
}

long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

int main()
{
	long long mod = 1000000007;
	long long sum = 0;
	long long n = 0;
	vector<long long> a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
		sum += tmp;
		sum %= mod;
	}

	sum -= a[0];
	if (sum < 0)
	{
		sum += mod;
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		ans += (a[i] * sum % mod);
		ans %= mod;
		sum -= a[i + 1];
		if (sum < 0)
		{
			sum += mod;
		}
	}
	cout << ans;
}
