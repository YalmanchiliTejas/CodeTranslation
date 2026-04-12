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
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <regex>
using namespace std;

#define rep(i,n)	for(lint i = 0; i < n; i++)
#define repr(i,n)	for(lint i = n - 1; i >= 0; i--)
#define repi(i,ini,n)	for(lint i = ini; i < n; i++)
#define repir(i,ini,n)	for(lint i = n-1; i >= ini; i--)
#define repb(i,start,end)	for(lint i = start; i <= end; i++)
#define repbr(i,start,end)	for(lint i = end; i >= start; i--)

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define rg(v, n) v.begin(), v.begin()+n
#define rrg(v, n) v.rbegin(), v.rbegin()+n

#define ret return 0;

namespace {

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

	const ulint mod = 1000000007;
	//const ulint mod = 998244353;
	const double pi = 3.141592653589793238462;
	const lint intmax = 9223372036854775807;
	const lint inf = 1100100100100100100LL;
	const ld eps = 0.0000001;
	const lint alpn = 'z' - 'a' + 1;

	template<class It>
	constexpr auto acc(It begin, It end)
	{
		return accumulate(begin, end, decltype(*begin)(0));
	}

	template<class T>
	constexpr auto msum(T arg0)
	{
		return arg0;
	}

	template<class T, class ...Types>
	constexpr auto msum(T arg0, Types ...args)
	{
		static_assert(sizeof...(args) > 0, "arg err");

		return arg0 + msum(args...);
	}

	template<class It>
	constexpr typename It::value_type mmax(It begin, It end)
	{
		return *max_element(begin, end);
	}

	template<class It>
	constexpr typename It::value_type mmin(It begin, It end)
	{
		return *min_element(begin, end);
	}

	template<class T>
	constexpr auto mmax(T arg)
	{
		return arg;
	}

	template<class T, class ...Types>
	constexpr auto mmax(T arg0, Types ...args)
	{
		using promote_t = decltype(msum(arg0, args...));

		return max(static_cast<promote_t>(arg0), static_cast<promote_t>(mmax(args...)));
	}

	template<class T>
	constexpr auto mmin(T arg)
	{
		return arg;
	}

	template<class T, class ...Types>
	constexpr auto mmin(T arg0, Types ...args)
	{
		using promote_t = decltype(msum(arg0, args...));

		return min(static_cast<promote_t>(arg0), static_cast<promote_t>(mmin(args...)));
	}

	constexpr auto clamp(lint val, lint left, lint right)
	{
		return mmax(mmin(val, right), left);
	}

	constexpr lint div2(lint p, lint q)
	{
		return (p + q - 1) / q;
	}

	//lint gcd(lint a, lint b) {
	//	while (1) {
	//		if (a < b) swap(a, b);
	//		if (!b) break;
	//		a %= b;
	//	}
	//	return a;
	//}

	//lint lcm(lint a, lint b)
	//{
	//	return a / gcd(a, b) * b;
	//}

	lint powInt(lint a, lint b)
	{
		if (b == 0)
		{
			return 1;
		}
		if (b == 1)
		{
			return a;
		}
		lint tmp = powInt(a, b / 2);
		return (b % 2 == 1 ? a * tmp * tmp : tmp * tmp);
	}

	template<class T>
	T sgn(T val)
	{
		if (val == T(0))
			return T(0);
		if (val < 0)
			return T(-1);
		if (val > 0)
			return T(1);
	}

	template<class T>
	constexpr auto modK_belowN(T k, T MOD, T n)
	{
		return (n + MOD - k - 1) / MOD;
	}

	template<class It, class T>
	bool exist(It begin, It end, const T& val)
	{
		return find(begin, end, val) != end;
	}

	template<class It, class Pr>
	bool exist_if(It begin, It end, Pr pred)
	{
		return find_if(begin, end, pred) != end;
	}

	template<class T>
	bool between(T val, T l, T r)
	{
		return (val >= l) && (val <= r);
	}

	template<class It>
	auto carr(It begin, It end) {
		vec c;
		c.push_back(1);
		auto before = *begin;
		for (auto it = begin + 1; it != end; it++) {
			if (before != *it) {
				c.push_back(0);
				before = *it;
			}
			c.back()++;
		}
		return c;
	}

	template<class T>
	struct nval {
		lint n;
		T val;
		nval() : n(0) {};
		nval(lint _n, T _val) : n(_n), val(_val) {};
	};

	template<class It>
	auto carr2(It begin, It end) {
		using T = nval<remove_reference_t<decltype(*begin)>>;

		vect<T> c;
		c.push_back(T(1, *begin));
		auto before = *begin;
		for (auto it = begin + 1; it != end; it++) {
			if (before != *it) {
				c.push_back(T(0, *it));
				before = *it;
			}
			c.back().n++;
		}
		return c;
	}

	template<class It, class ...T>
	void sort2(It begin, It end, T ...p)
	{
		using val_t = remove_reference_t<decltype(*begin)>;

		sort(begin, end, [p...](val_t a, val_t b) {
			bool neq[] = { (a.*p != b.*p)... };
			bool sg[] = { (a.*p < b.*p)... };

			rep(i, sizeof...(p)) {
				if (neq[i])
				{
					return sg[i];
				}
			}
			return false;
		});
	}

	template<size_t _K, size_t _N, class ...Types, size_t ...indices>
	auto constexpr __ModKtuple_Impl(index_sequence<indices...>, tuple<Types...> args)
	{
		return make_tuple(get<indices * _N + _K>(args)...);
	}

	template<size_t K, size_t N, class ...Types>
	auto constexpr ModKtuple(Types ...args)
	{
		return __ModKtuple_Impl<K, N>(make_index_sequence<modK_belowN(K, N, sizeof...(args))>{}, forward_as_tuple(args...));
	}

	template<class It, class ...T, class ...Tsg, size_t ...indices>
	void __sort3_Impl(It begin, It end, tuple<T...> p, tuple<Tsg...> sgf, index_sequence<indices...>)
	{
		using val_t = remove_reference_t<decltype(*begin)>;

		sort(begin, end, [p, sgf](val_t a, val_t b) {
			bool neq[] = { (a.*(get<indices>(p)) != b.*(get<indices>(p)))... };
			bool sg[] = { ((a.*(get<indices>(p)) < b.*(get<indices>(p))) != (get<indices>(sgf))) ... };

			rep(i, sizeof...(indices)) {
				if (neq[i])
				{
					return sg[i];
				}
			}
			return false;
			});
	}

	template<class It, class ...T>
	void sort3(It begin, It end, T ...p)
	{
		using val_t = remove_reference_t<decltype(*begin)>;

		auto p_forward = ModKtuple<0, 2>(p...);
		auto sgf_forward = ModKtuple<1, 2>(p...);

		constexpr auto p_sz = tuple_size<decltype(p_forward)>::value;
		constexpr auto sgf_sz = tuple_size<decltype(sgf_forward)>::value;

		static_assert(p_sz == sgf_sz, "arg err");

		__sort3_Impl(begin, end, p_forward, sgf_forward, make_index_sequence<p_sz>{});
	}

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

	template<class It>
	bool next_comb(lint n, It begin, It end)
	{
		auto rend = make_reverse_iterator(begin);
		auto rbegin = make_reverse_iterator(end);

		auto rit = rbegin;
		for (; rit != rend; rit++)
		{
			if ((rit == rbegin && (*rit) + 1 != n) ||
				(rit != rbegin && (*rit) + 1 != *(rit - 1)))
			{
				goto found;
			}
		}
		return false;
	found:;
		(*rit)++;

		for (auto it = rit.base(); it != end; it++)
		{
			(*it) = (*(it - 1)) + 1;
		}
		return true;
	}

	ostream& setp(ostream& ost)
	{
		cout << setprecision(60) << fixed;
		return ost;
	}

#ifdef _LOCAL
	auto& dbg = cout;
#else
	struct dummy_cout
	{
		template<class T>
		dummy_cout& operator<<(T&& op)
		{
			return *this;
		}

		using endl_t = basic_ostream<char, char_traits<char>>;

		dummy_cout& operator<<(endl_t& (*)(endl_t&))
		{
			return *this;
		}
	};

	dummy_cout dbg;
#endif
};

lint len[100], p[100];

lint f(lint n, lint x)
{
	if (x >= len[n])
	{
		return p[n];
	}

	lint ans = 0;

	x--;

	if (x > 0)
	{
		ans += f(n - 1, x);
		x -= len[n - 1];
	}

	if (x > 0)
	{
		x--;
		ans++;
	}

	if (x > 0)
	{
		ans += f(n - 1, x);
		x -= len[n - 1];
	}

	return ans;

}

int main()
{
	lint n, x;
	cin >> n >> x;


	len[0] = 1;
	p[0] = 1;
	rep(i, 60)
	{
		len[i + 1] = len[i] * 2 + 3;
		p[i + 1] = p[i] * 2 + 1;
	}

	cout << f(n, x) << endl;

	return 0;
}
