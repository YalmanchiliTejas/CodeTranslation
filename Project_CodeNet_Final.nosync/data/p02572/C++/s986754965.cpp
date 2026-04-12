#ifndef AUTO_UTIL_HEADER_HPP
#define AUTO_UTIL_HEADER_HPP

#include <bits/stdc++.h>
#include <cassert>

using std::cin, std::cout, std::bitset, std::complex;
using std::vector, std::array, std::string, std::pair, std::list, std::queue, std::deque;
using std::priority_queue, std::set, std::map, std::unordered_map;
using std::sort, std::greater, std::min, std::max, std::reverse;
using std::min_element, std::max_element, std::accumulate;

using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using ull = unsigned long long int;
using ll = long long int;
using vll = vector<ll>; using vvll = vector<vll>; using vvvll = vector<vvll>;
using vd = vector<double>; using vvd = vector<vd>; using vvvd = vector<vvd>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using cdouble = complex<double>;

const double eps = 1e-7;
#define Loop(i, n) for(int i = 0; i < int(n); i++)
#define Loopll(i, n) for(ll i = 0; i < ll(n); i++)
#define Loop1(i, n) for(int i = 1; i <= int(n); i++)
#define Loopll1(i, n) for(ll i = 1; i <= ll(n); i++)
#define Loopr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define Looprll(i, n) for(ll i = ll(n) - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = int(n); i >= 1; i--)
#define Looprll1(i, n) for(ll i = ll(n); i >= 1; i--)
#define Foreach(buf, container) for(const auto &buf : container)
#define Foreachr(buf, container)  for(const auto &buf : reversed(container))
#define Loopdiag(i, j, h, w, sum) for(int i = ((sum) >= (h) ? (h) - 1 : (sum)), j = (sum) - i; i >= 0 && j < (w); i--, j++)
#define Loopdiagr(i, j, h, w, sum) for(int j = ((sum) >= (w) ? (w) - 1 : (sum)), i = (sum) - j; j >= 0 && i < (h); j--, i++)
#define Loopdiagsym(i, j, h, w, gap) for (int i = ((gap) >= 0 ? (gap) : 0), j = i - (gap); i < (h) && j < (w); i++, j++)
#define Loopdiagsymr(i, j, h, w, gap) for (int i = ((gap) > (h) - (w) - 1 ? (h) - 1 : (w) - 1 + (gap)), j = i - (gap); i >= 0 && j >= 0; i--, j--)
#define Loopitr(itr, container) for(auto itr = container.begin(); itr != container.end(); itr++)
#define quickio() std::ios::sync_with_stdio(false); std::cin.tie(0);
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
#define Comp(type_t) bool operator<(const type_t &another) const
#define fst first
#define snd second
bool feq(double x, double y) { return abs(x - y) <= eps; }
bool inrange(ll x, ll t) { return x >= 0 && x < t; }
bool inrange(vll xs, ll t) { Foreach(x, xs) if (!(x >= 0 && x < t)) return false; return true; }
int ceillog2(ll x) { int m = int(log2(x)); return m + ((1LL << m) < x ? 1 : 0); }
int floorlog2(ll x) { int m = int(log2(x)); return m - ((1LL << m) > x ? 1 : 0); }
const string endl = "\n";
template<class T> T reversed(T container) { reverse(container.begin(), container.end()); return container; }
template<class T> void printv(const vector<T> &v) { for (const T &x : v) cout << x << " "; cout << endl; }
template<class T> void printmx(const vector<vector<T>> &mx) { for (const vector<T> &v : mx) printv(v); }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll floorsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (m*  m <= x ? 0 : -1); }
ll ceilsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return ll(m) * ll(n) / gcd(m, n); }

#endif // AUTO_UTIL_HEADER_HPP

//========================================================================//

namespace mod_op {

	const ll MOD = (ll)1e9 + 7;

	class modll {
	private:
		ll val;
		ll modify(ll x) const { ll ret = x % MOD; if (ret < 0) ret += MOD; return ret; }
		ll inv(ll x) const {
			if (x == 0) return 1 / x;
			else if (x == 1) return 1;
			else return modify(inv(MOD % x) * modify(-MOD / x));
		}
	public:
		modll(ll init = 0) { val = modify(init); return; }
		modll(const modll& another) { val = another.val; return; }
		modll& operator=(const modll &another) { val = another.val; return *this; }
		modll operator+(const modll &x) const { return modify(val + x.val); }
		modll operator-(const modll &x) const { return modify(val - x.val); }
		modll operator*(const modll &x) const { return modify(val * x.val); }
		modll operator/(const modll &x) const { return modify(val * inv(x.val)); }
		modll& operator+=(const modll &x) { val = modify(val + x.val); return *this; }
		modll& operator-=(const modll &x) { val = modify(val - x.val); return *this; }
		modll& operator*=(const modll &x) { val = modify(val * x.val); return *this; }
		modll& operator/=(const modll &x) { val = modify(val * inv(x.val)); return *this; }
		bool operator==(const modll &x) { return val == x.val; }
		bool operator!=(const modll &x) { return val != x.val; }
		friend std::istream& operator >> (std::istream &is, modll& x) { is >> x.val; return is; }
		friend std::ostream& operator << (std::ostream &os, const modll& x) { os << x.val; return os; }
		ll get_val() { return val; }
	};

	modll pow(modll n, ll p) {
		modll ret;
		if (p == 0) ret = 1;
		else if (p == 1) ret = n;
		else {
			ret = pow(n, p >> 1);
			ret *= ret;
			if ((p & 1) == 1) ret *= n;
		}
		return ret;
	}

	vector<modll> facts;

	void make_facts(int n) {
		if (facts.empty()) facts.push_back(modll(1));
		for (int i = (int)facts.size(); i <= n; ++i) facts.push_back(modll(facts.back() * (ll)i));
		return;
	}

	vector<modll> ifacts;
	vector<modll> invs;

	void make_invs(int n) {
		if (invs.empty()) {
			invs.push_back(modll(0));
			invs.push_back(modll(1));
		}
		for (int i = (int)invs.size(); i <= n; ++i) {
			// because 0 = MOD = kq + r, 1/k = -q/r
			invs.push_back(invs[(int)MOD % i] * ((int)MOD - (int)MOD / i));
		}
		return;
	}

	void make_ifacts(int n) {
		make_invs(n);
		if (ifacts.empty()) ifacts.push_back(modll(1));
		for (int i = (int)ifacts.size(); i <= n; ++i) ifacts.push_back(modll(ifacts.back() * invs[i]));
		return;
	}

	//nCr
	modll combination(ll n, ll r) {
		if (n >= r && r >= 0) {
			modll ret;
			make_facts((int)n);
			make_ifacts((int)n);
			ret = facts[(unsigned)n] * ifacts[(unsigned)r] * ifacts[(unsigned)(n - r)];
			return ret;
		}
		else return 0;
	}

	modll get_fact(ll n) {
		make_facts((int)n);
		return facts[(int)n];
	}

	modll get_ifact(ll n) {
		make_ifacts((int)n);
		return ifacts[(int)n];
	}

	//log_a(b), if x does not exist, return -1
	ll disc_log(modll a, modll b) {
		ll ret = -1;
		ll m = ceilsqrt(MOD);
		unordered_map<ll, ll> mp;
		modll x = 1;
		Loop(i, m) {
			mp[x.get_val()] = i;
			x *= a;
		}
		x = modll(1) / pow(a, m);
		modll k = b;
		Loop(i, m) {
			if (mp.find(k.get_val()) == mp.end()) k *= x;
			else {
				ret = i * m + mp[k.get_val()];
				break;
			}
		}
		return ret;
	}
}

using namespace mod_op;
using vmodll = vector<modll>;
using vvmodll = vector<vmodll>;
using vvvmodll = vector<vvmodll>;

int main() {
    int n; cin >> n;
    vmodll a(n); Loop(i, n) cin >> a[i];
    modll acc = 0;
    modll ans = 0;
    Loop(i, n) {
        ans += acc * a[i];
        acc += a[i];
    }
    cout << ans << endl;
}
