#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <iomanip>
#include <typeinfo>
#include <iterator>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <map>
#include <set>
#include <numeric>
using namespace std;

#define repr(itr, bgn, end) for (ll itr = (ll)bgn; itr < (ll)end; ++itr)
#define rep(itr, end) repr(itr, 0, end)
#define reprrev(itr, bgn, end) for (ll itr = (ll)end - 1; itr >= (ll)bgn; --i)
#define reprev(itr, end) reprrev(itr, 0, end)
#define all(container) container.begin(), container.end()
#define sortall(container) sort(all(container))
#define yn(cond) cond ? (cout << "Yes" << endl) : (cout << "No" << endl)
#define YN(cond) cond ? (cout << "YES" << endl) : (cout << "NO" << endl)
#define LLONG_MAX numeric_limits<ll>::max()
#define INT_MAX numeric_limits<int>::max()

typedef long long       ll;
typedef struct edge_ { ll to; ll cost; } edge;
typedef vector<int>     vi;
typedef vector<ll>      vll;
typedef vector<double>  vd;
typedef vector<bool>    vb;
typedef vector<string>  vs;
typedef vector<char>    vc;
typedef vector<edge>    ve;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
typedef vector<vll>		vvll;
typedef vector<vi>		vvi;
typedef vector<ve>      vve;
typedef vector<vc>		vvc;

constexpr double	PI = 3.14159265358979323846;
constexpr ll		INF = 1 << 15;
constexpr ll		MOD = (ll)1e9 + 7;
constexpr double	EPS = 1e-7;
constexpr int		dy4[4] = { 0, 1, 0, -1 };
constexpr int		dx4[4] = { 1, 0, -1, 0 };
constexpr int		dy8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
constexpr int		dx8[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

template <int mod>
class modint {
private:
	long long num;
	modint set(int _num) { num = _num % mod; return *this; }

public:
	modint() { num = 0; }
	modint(int num) : num(num % mod) {}

	modint operator =  (const int& x) { return set(x % mod); }
	modint operator +  (const int& x) { return modint<mod>(num + (x % mod)); }
	modint operator -  (const int& x) { return modint<mod>(num - (x % mod)); }
	modint operator *  (const int& x) { return modint<mod>(num * (x % mod)); }
	modint operator /  (const int& x) { return modint<mod>(num / (x % mod)); }
	modint operator += (const int& x) { return set(num + (x % mod)); }
	modint operator -= (const int& x) { return set(num - (x % mod)); }
	modint operator *= (const int& x) { return set(num * (x % mod)); }

	friend ostream& operator << (ostream& os, const modint<mod>& x) {
		os << x.num;
		return os;
	}
};

template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
	for (T& x : vec) is >> x;
	return is;
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
	for (const T& x : vec) os << x << " ";
	return os;
}

template<typename S, typename T>
istream& operator >> (istream& is, pair<S, T>& p) {
	is >> p.first >> p.second;
	return is;
}

template<typename S, typename T>
ostream& operator << (ostream& os, const pair<S, T>& p) {
	os << p.first << " " << p.second;
	return os;
}

/******************************************************************************/
/**********************         Don't make WA !!         **********************/
/******************************************************************************/


int main()
{
	int X;
	cin >> X;
	YN(X == 7 || X == 5 || X == 3);

	return 0;
}