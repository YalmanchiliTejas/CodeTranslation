#ifdef _WIN32
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

// 継承可能な型
template <class Type>
struct IN : Type
{
	IN()
	{
		std::cin >> *this;
	}
};

// 継承不可能な型
template <class Type>
struct IN_
{
	Type val;

	IN_()
	{
		std::cin >> val;
	}

	operator Type&()
	{
		return val;
	}

	IN_<Type>& operator=(const Type& _value)
	{
		val = _value;
		return *this;
	}
};

template <class Char, class Type>
std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const IN_<Type>& value)
{
	return os << value.val;
}

template <class Char, class Type>
std::basic_istream<Char>& operator >>(std::basic_istream<Char>& is, IN_<Type>& value)
{
	return is >> value.val;
}

template <class Type>
void OUT(const Type& value)
{
	std::cout << value << std::endl;
}

template <class Type, class ... Args>
void OUT(const Type& value, const Args& ... args)
{
	std::cout << value << ' ';
	OUT(args...);
}

void YES()
{
	OUT("YES");
}
void NO()
{
	OUT("NO");
}
void YESNO(const bool cond)
{
	OUT(cond ? "YES" : "NO");
}

void Yes()
{
	OUT("Yes");
}
void No()
{
	OUT("No");
}
void YesNo(const bool cond)
{
	OUT(cond ? "Yes" : "No");
}

using ll = long long;
using inll = IN_<ll>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using setll = std::set<ll>;
using msetll = std::multiset<ll>;
using P = std::pair<ll, ll>;
using instr = IN<std::string>;

// 階乗を計算 O(N) (N=10^7 で O(10^7))
ll factorial(ll n)
{
	for (ll i = n - 1; i > 1; --i)
		n *= i;
	return n;
}

// nCrを計算 O(N) (N=10^7 で O(10^7))
ll ncr(const ll n, ll r)
{
	if (r * 2 > n) r = n - r;

	ll dividend = 1, divisor = 1;

	for (ll i = 1; i <= r; ++i) {
		dividend *= n - i + 1;
		divisor *= i;
	}

	return dividend / divisor;
}

// 素数判定 O(sqrt(N)) (N=10^7 で O(10^3))
bool isprime(const ll num)
{
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0) return false;
    }

    return true;
}

// 各桁の和を計算 O(logN) (N=10^7 で O(7))
ll digsum(ll n)
{
	ll sum = 0;
	while(n != 0){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

// ２つの数の最大公約数を求める
ll gcd(ll m, ll n)
{
	// 引数に０がある場合は０を返す
	if (m == 0 || n == 0)
		return 0;

	// ユークリッドの方法
	while(m != n)
	{
		if (m > n) m = m - n;
		else n = n - m;
	}
	return m;
}

// ２つの数の最小公倍数を求める
ll lcm(const ll m, const ll n)
{
	// 引数に０がある場合は０を返す
	if (m == 0 || n == 0)
		return 0;

	// lcm = m * n / gcd(m,n)
	return m / gcd(m, n) * n;
}

// ３以上の数の最大公約数を求める
template <class Container>
ll gcd(const Container& v)
{
	ll res = *std::begin(v);
	for (const auto& i : v)
	{
		res = gcd(res, i);
	}
	return res;
}

// ３以上の数の最小公倍数を求める
template <class Container>
ll lcm(const Container& v)
{
	ll res = *std::begin(v);
	for (const auto& i : v)
	{
		res = lcm(res, i);
	}
	return res;
}

// 結果を切り上げる除算
ll divup(const ll a, const ll b)
{
	return (a + b - 1) / b;
}

ll inrange(const ll x, const ll y, const ll w, const ll h)
{
	return 0 <= x && x < w && 0 <= y && y < h;
}

// 指数が整数のpow
// https://kazu-yamamoto.hatenablog.jp/entry/20090223/1235372875
template <typename Type>
Type pow_i(const Type x, const ll n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return pow_i(x * x, n / 2);
	else
		return x * pow_i(x, n - 1);
}

// 指数が整数のpow (mを法として)
// http://augusuto04.hatenablog.com/entry/2015/05/02/183451
ll pow_im(const ll x, const ll n, const ll m)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return pow_im(x * x % m, n / 2, m);
	else
		return x * pow_im(x, n - 1, m) % m;
}

const ll MOD = (ll)1e9 + 7;
const ll INF = (ll)1e18;
const ll dy[] = { 0, 0, 1, -1 };
const ll dx[] = { 1, -1, 0, 0 };

#define FOR(i, m, n) for (ll (i) = (m); (i) < (n); ++(i))
#define REP(i, n) for (ll (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for (ll (i) = (n); (i) >= 0; --(i))
#define ITRREP(it, v) for (auto (it) = (v).begin(); (it) != (v).end(); ++(it))
#define ITRREPR(it, v) for (auto (it) = (v).rbegin(); (it) != (v).rend(); ++(it))

void Main();

int main()
{
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	Main();

#ifdef _DEBUG
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl << "Press Enter key to continue...";
	std::cin.get();
#endif

	return 0;
}

using namespace std;

//////////////////////////////

vll h, p;

ll rec(ll n, ll x)
{
	if (x <= n) return 0;
	if (n == 0) return 1;

	if (x < h[n-1] + 2) return rec(n-1, x-1);
	if (x == h[n-1] + 2) return p[n-1] + 1;
	if (x > h[n-1] + 2) return p[n-1] + 1 + rec(n-1, x - h[n-1] - 2);
}

void Main()
{
	inll n, x;
	h.resize(51);
	p.resize(51);
	h[0] = 1;
	p[0] = 1;
	FOR(i, 1, n)
	{
		h[i] = h[i-1] * 2 + 3;
		p[i] = p[i-1] * 2 + 1;
	}
	OUT(rec(n, x));
}
