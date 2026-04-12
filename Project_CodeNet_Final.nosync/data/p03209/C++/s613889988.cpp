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
using namespace std;

namespace {

	using lint = long long;
	using uli = unsigned long long;

	uli gcd(uli a, uli b) {
		while (1) {
			if (a < b) swap(a, b);
			if (!b) break;
			a %= b;
		}
		return a;
	}

	uli lcm(uli a, uli b)
	{
		return a / gcd(a, b) * b;
	}

	const uli mod = 1000000007;
	const double pi = 3.141592653589793238462;
	const lint intmax = 9223372036854775807;

	uli FactMod(uli n) {
		if (n == 0)
		{
			return 1;
		}
		lint ans = 1;
		while (n > 1) {
			ans *= n;
			n--;
			ans %= mod;
		}
		return ans;
	}

	uli _PowMod(uli x, uli y, uli _mod)
	{
		if (x <= 1)
		{
			return x;
		}
		if (y == 0)
		{
			return 1;
		}
		else if (y == 1)
		{
			return x % _mod;
		}
		else if (y % 2 == 0)
		{
			auto tmp = _PowMod(x, y / 2, _mod);
			return tmp * tmp % _mod;
		}
		else
		{
			auto tmp = _PowMod(x, y / 2, _mod);
			return (tmp * tmp % _mod) * x % _mod;
		}
	}

	uli PowMod(uli x, uli y)
	{
		return _PowMod(x, y, mod);
	}

	uli getModInv(uli N)
	{
		return PowMod(N, mod - 2);
	}

	lint nCrMod(lint n, lint r, lint start)
	{
		if (n < r || n <= 0 || r < 0)
		{
			return 0;
		}
		r = min(r, n - r);
		lint a = start;
		for (size_t i = n; i >= n - r + 1; i--)
		{
			a *= i;
			a %= mod;
		}

		a *= getModInv(FactMod(r));
		a %= mod;
		return a;
	}

	lint nHrMod(lint n, lint r, lint start)
	{
		return nCrMod(n + r - 1, r, start);
	}

	template<class T>
	constexpr auto modK_belowN(T k, T MOD, T n)
	{
		return (n + MOD - k - 1) / MOD;
	}

	struct uf
	{
		vector<lint> p;

		uf(lint n) : p(n)
		{
			for (size_t i = 0; i < n; i++)
			{
				p[i] = i;
			}
		}

		lint rt(lint n)
		{
			return p[n] == n ? n : p[n] = rt(p[n]);
		}

		void un(lint n, lint m)
		{
			p[rt(n)] = p[rt(m)];
		}

		bool eq(lint n, lint m)
		{
			return rt(n) == rt(m);
		}
	};

	bool lineCol(lint a1x, lint a1y, lint a2x, lint a2y, lint b1x, lint b1y, lint b2x, lint b2y)
	{
		auto ta = (b1x - b2x) * (a1y - b1y) + (b1y - b2y) * (b1x - a1x);
		auto tb = (b1x - b2x) * (a2y - b1y) + (b1y - b2y) * (b1x - a2x);
		auto tc = (a1x - a2x) * (b1y - a1y) + (a1y - a2y) * (a1x - b1x);
		auto td = (a1x - a2x) * (b2y - a1y) + (a1y - a2y) * (a1x - b2x);

		return tc * td < 0 && ta * tb < 0;
	}

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

	lint _sMod(string n, lint mod)
	{
		lint k = (n[0] - '0') % mod;
		for (size_t i = 1; i < n.length(); i++)
		{
			k *= 10;
			k += (n[i] - '0');
			k %= mod;
		}
		return k;
	}

#define vec(name, n)			vector<lint> name(n)
#define vec_(name, n, init)		vector<lint> name(n, init)

#define vecs(name, n)			vector<string> name(n)
#define vect(t, name, n)		vector<t> name(n)

#define vec2(name, n, m)		vector<vector<lint>> name(n, vector<lint>(m))
#define vec2_(name, n, m, init)	vector<vector<lint>> name(n, vector<lint>(m, init))

#define rep(i,n)	for(lint i = 0; i < n; i++)
#define rep_(i,n,z)	for(lint i = z; i < n; i++)
#define mmax(a,b)	max((lint)(a), (lint)(b))
#define mmin(a,b)	min((lint)(a), (lint)(b))

	lint div2(lint p, lint q)
	{
		return (p + q - 1) / q;
	}

	struct xy
	{
		lint x, y;
		xy() :x(0), y(0) {}
		xy(lint _x, lint _y) : x(_x), y(_y) {}
	};

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

	lint digcnt(lint n)
	{
		lint ans = 0;
		while (n > 0)
		{
			n /= 10;
			ans++;
		}
		return ans;
	}

	template<class T, class T2>
	T2 ler(T val1, T val2, T2 l, T2 e, T2 r)
	{
		if (val1 < val2)
			return r;
		if (val1 > val2)
			return l;
		return e;
	}

	const lint alpn = 'z' - 'a' + 1;

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
	bool between(T val, T l, T r)
	{
		return (val >= l) && (val <= r);
	}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

	template<class It>
	vector<lint> carr(It begin, It end) {
		vec(c, 0);
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

		vect(T, c, 0);
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

	lint sumdig(lint n) {
		lint ans = 0;
		while (n > 0) {
			ans += n % 10;
			n /= 10;
		}
		return ans;
	}

	lint getdig(lint n, lint d) {
		return (n / powInt(10, d)) % 10;
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

	auto parr(lint n)
	{
		vector<nval<lint>> d;
		lint n_ = n;
		for (lint i = 2; i * i <= n; i++)
		{
			if (n_ % i == 0)
			{
				d.push_back(nval<lint>(1, i));
				n_ /= i;
				while (n_ % i == 0)
				{
					n_ /= i;
					d.back().n++;
				}
			}
		}
		if (n_ > 1)
		{
			d.push_back(nval<lint>(1, n_));
		}
		return d;
	}

	long double dist_1(xy p, xy q) {
		return abs(p.x - q.x) + abs(p.y - q.y);
	}
	long double dist_2(xy p, xy q) {
		return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
	}
	long double dist_inf(xy p, xy q) {
		return max(abs(p.x - q.x), abs(p.y - q.y));
	}

	lint factr(lint n) {
		if (n == 0)
		{
			return 1;
		}
		lint ans = 1;
		while (n > 1) {
			ans *= n;
			n--;
		}
		return ans;
	}

	lint mod0(lint n, lint mod)
	{
		lint tmp = n % mod;
		if (tmp == 0)
			return mod;
		return tmp;
	}

	template<class T>
	lint len(T v)
	{
		return v.size();
	}

	char caesar(char s, lint key)
	{
		if (between(s, 'A', 'Z'))
		{
			return (s - 'A' + key) % alpn + 'A';
		}
		if (between(s, 'a', 'z'))
		{
			return (s - 'a' + key) % alpn + 'a';
		}
		return s;
	}

	string caesar(string s, lint key)
	{
		rep(i, s.length())
			s[i] = caesar(s[i], key);
		return s;
	}

#define ret return 0;

	template<class It>
	auto spacel(It i, It end)
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

	template<typename It, class T>
	It bins_near(It begin, It end, T val) {
		if (end - begin <= 1)
		{
			return begin;
		}
		auto l = (end - begin) / 2;

		auto s1 = bins_near(begin, begin + l, val);
		auto s2 = bins_near(begin + l, end, val);

		if (abs(val - *s1) < abs(val - *s2))
		{
			return s1;
		}
		else
		{
			return s2;
		}
	}

	template<bool f>
	auto make_ptbl(lint n) {
		vec_(a, n + 1, 0);
		vec(p, 0);

		rep_(i, n+1, 2) {
			if (a[i] == 1)
			{
				continue;
			}
			p.push_back(i);
			for (lint j = i*2; j <= n; j += i)
			{
				a[j] = 1;
			}
		}
		if (f)
		{
			return a;
		}
		else
		{
			return p;
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
}

lint llen[100];
lint lp[100];

lint f(lint lv, lint x) {
	if (llen[lv] <= x)
	{
		return lp[lv];
	}

	if (x <= 1)
	{
		return 0;
	}else if (x <= 1 + llen[lv - 1])
	{
		return f(lv - 1, x - 1);
	}else if (x <= 1 + llen[lv - 1] + 1 + llen[lv - 1])
	{
		return lp[lv - 1] + 1 + f(lv - 1, x - (1 + llen[lv - 1] + 1));
	}
	return 2 * lp[lv - 1];
}

int main()
{
	lint n, x;
	cin >> n >> x;

	llen[0] = 1;
	lp[0] = 1;
	rep(i, n)
	{
		llen[i + 1] = 2 * llen[i] + 3;
		lp[i + 1] = 2 * lp[i] + 1;
	}

	cout << f(n, x) << endl;

	return 0;
}
