// AtCoder.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// AtCoder.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//


#define _USE_MATH_DEFINES
#include<math.h>

//#include<cmath>

#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>



//#include "Ants.h"
using namespace std;
typedef long long ll;
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int i=0;i<n;i++)
#define show(s) cout<<s<<endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define LINF (1000000000000000000ll)
#define MOD (1e9+7)
typedef pair < int, int> P;
ll gcd(ll a, ll b) {//最大公約数を求める///最大公倍数a*b/gcd(a,b)
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcd(ll a, ll b) {//最小公倍数を求める　b=0のときaを返す
	if (b == 0) return a;
	return (a / gcd(a, b)) * b;
}
vector<int> divnum(ll num) {
	int dig;
	vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p;
}
int digiter(ll num) {
	int dig;
	vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p.size();
}
vector<int> convertstring(string s) {
	vector<int> d;
	ll n = s.size();
	rep(i, n) {
		d.push_back(s[i] - '0');
	}
	return d;
}
map< int64_t, int > prime_factor(int64_t n) {
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
vector<ll> divisor(ll n) {
	vector<ll>res;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i != 0)continue;
		res.push_back(i);
		if (i * i != n)res.push_back(n / i);
	}
	return res;
}


ll myPow(ll x, ll n, ll m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}
std::vector<int> Eratosthenes(const int N)
{
	std::vector<bool> is_prime(N + 1);
	for (int i = 0; i <= N; i++)
	{
		is_prime[i] = true;
	}
	std::vector<int> P;
	for (int i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			for (int j = 2 * i; j <= N; j += i)
			{
				is_prime[j] = false;
			}
			P.emplace_back(i);
		}
	}
	return P;
}
const int mod = MOD;
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
		assert(n < mod);
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
		ifact[n] = fact[n].inv();
		for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
	}
	mint operator()(int n, int k) {
		if (k < 0 || k > n) return 0;
		return fact[n] * ifact[k] * ifact[n - k];
	}
}comb(1000005);//comb貯め
mint f(int n, int k) {
	if (n < 0) return 0;
	// nPk = nCk * k!
	mint res = comb(n, k);
	res *= comb.fact[k];
	return res;
}


ll N,M,K;
int main()
{
	cin >> N >> M >> K;
	mint res = 0;
	rep(y1, M) {
		/*rep(y2, M) {
			if (y1 >= y2)continue;
			
			res += abs(y2-y1);
		}*/
		res += (M - y1 - 1) * (M - y1) / 2;
	}
	
	res *= N;
	res *= N;
	ll ares = 0;
	//cout << res << endl;
	rep(x1, N) {
		/*rep(x2, N) {
			if (x1 >= x2)continue;
			
			ares += abs(x1 - x2);
		}*/
		ares += (N - x1 - 1) * (N - x1) / 2;
	}
	
	ares *= M;
	ares *= M;
	res += ares;
	//cout << res << endl;
	//cout << comb(N * M, K - 2) << endl;
	res *= comb(N*M-2, K - 2);
	cout << res << endl;
}