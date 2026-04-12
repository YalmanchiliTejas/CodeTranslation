#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <complex>
#include <regex>
#include <random>
using namespace std;

#define rep(i,n)	for(lint i = 0; i < n; i++)
#define repr(i,n)	for(lint i = n - 1; i >= 0; i--)
#define repi(i,ini,n)	for(lint i = ini; i < n; i++)
#define repir(i,ini,n)	for(lint i = n-1; i >= ini; i--)
#define repb(i,start,end)	for(lint i = start; i <= end; i++)
#define repbr(i,start,end)	for(lint i = end; i >= start; i--)

#define bit(n)				(1LL << (n))

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define rg(v, ini, end) v.begin() + ini, v.begin()+end

#define ret return 0;
#define chmax(a, b) a=max(a,b)
#define chmin(a, b) a=min(a,b)

using lint = long long;
using ulint = unsigned long long;
using ld = long double;
struct xy
{
	lint x, y;
	xy() :x(0), y(0) {}
	xy(lint _x, lint _y) : x(_x), y(_y) {}
	xy operator+(const xy& p) const
	{
		return xy(x + p.x, y + p.y);
	}
	bool operator<(xy p) const
	{
		if (y == p.y)
			return x < p.x;
		return y < p.y;
	}
};
struct xyd
{
	ld x, y;
	xyd() :x(0), y(0) {}
	xyd(long double _x, long double _y) : x(_x), y(_y) {}
};
using vec = vector<lint>;
using vecd = vector<ld>;
using vecs = vector<string>;
using vecp = vector<xy>;
template<class T> using vect = vector<T>;
class vec2 : public vector<vector<lint>>
{
public:
	vec2() {}
	vec2(lint n) : vector(n) {}
	vec2(lint h, lint w) : vector(h, vector<lint>(w)) {}
	vec2(lint h, lint w, lint v) : vector(h, vector<lint>(w, v)) {}
};

template<class T> using priq = priority_queue<T>;
template<class T> using rpriq = priority_queue<T, vector<T>, greater<T>>;
template<class Key, class Val> using hashmap = unordered_map<Key, Val>;
template<class Key> using hashset = unordered_set<Key>;

template<class It>
constexpr typename It::value_type rmax(It begin, It end) {
	return *max_element(begin, end);
}

template<class T1, class T2>
constexpr auto mmax(T1 arg1, T2 arg2) {
	using T = decltype(arg1 + arg2);
	return max(T(arg1), T(arg2));
}

template<class T, class ...Types>
constexpr auto mmax(T arg0, Types ...args) {
	return mmax(arg0, mmax(args...));
}

template<class It>
constexpr typename It::value_type rmin(It begin, It end) {
	return *min_element(begin, end);
}

template<class T1, class T2>
constexpr auto mmin(T1 arg1, T2 arg2) {
	using T = decltype(arg1 + arg2);
	return min(T(arg1), T(arg2));
}

template<class T, class ...Types>
constexpr auto mmin(T arg0, Types ...args) {
	return mmin(arg0, mmin(args...));
}

mt19937 mtrand((random_device())());

const double pi = 3.141592653589793238462;
const lint intmax = 9223372036854775807;
const lint inf = 1100100100100100100LL;

constexpr lint div2(lint p, lint q)
{
	return (p + q - 1) / q;
}

#if(__cplusplus < 201703L)

	lint gcd(lint a, lint b) {
		while (1) {
			if (a < b) swap(a, b);
			if (!b) break;
			a %= b;
		}
		return a;
	}

	lint lcm(lint a, lint b)
	{
		return a / gcd(a, b) * b;
	}

#endif

template<class T>
struct nval {
	lint n;		// counts
	T val;
	nval() : n(0) {};
	nval(lint _n, T _val) : n(_n), val(_val) {};
};

template<class It, class It2>
auto spacel(It i, It2 end)
{
	if (i + 1 == end)
	{
		return '\n';
	}
	else
	{
		return ' ';
	}
}

ostream& setp(ostream& ost)
{
	cout << setprecision(60) << fixed;
	return ost;
}

const ulint mod = 1000000007;
//const ulint mod = 998244353;
const ld eps = 0.0000001;

int main()
{
	lint x;
	cin >> x;
	if (x >= 30)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
