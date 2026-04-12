#define NOMINMAX
#define TEST_MODE true

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep2(i, a, b) for (int i = (a)-1; i >= (int)b; --i)
#define range(i, a, b, c) for (int i = a;             \
                                   c > 0 ? i < b : i > b; \
                                   i += c)
#define chmax(a, b) (a = (a) < (b) ? (b) : (a))
#define chmin(a, b) (a = (a) > (b) ? (b) : (a))
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) begin(a), end(a)
#define ifnot(a) if (not(a))
#define int long long

#ifdef LOCAL_ENV

#if TEST_MODE == true
const bool test = true;
#define dump(x) cerr << #x << " : " << (x) << " "
#define dumpl(x) dump(x) << endl
#else
const bool test = false;
#define dump(x) 
#define dumpl(x)
#endif

#else
const bool test = false;
#define dump(x) 
#define dumpl(x)
#endif

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
const int INF = (int)1 << 60;
const int undefined = INF;
const ll INFL = (ll)1 << 60;
ll mod_n = (int)1e9 + 7;
const double eps = 1e-10;
typedef long double Real;
// return -1, 0, 1
int sgn(const Real &r) { return (r > eps) - (r < -eps); }
int sgn(const Real &a, const Real &b) { return sgn(a - b); }

//.....................
const int MAX = (int)2e5 + 5;

vector<string> split(const string &str, char sep)
{
	vector<string> v;
	stringstream ss(str);
	string buffer;
	while (getline(ss, buffer, sep))
	{
		v.push_back(buffer);
	}
	return v;
}

string join(const vector<string>& v, const string delim = 0) {
	string s;
	if (!v.empty()) {
		s += v[0];
		for (decltype(v.size()) i = 1, c = v.size(); i < c; ++i) {
			if (delim != "") s += delim;
			s += v[i];
		}
	}
	return s;
}

string operator * (const string& s, const int& n) {
	string res = "";
	rep(i, n) res += s;
	return res;
}

template <class InputIterator>
int sum(InputIterator begin, InputIterator end)
{
	return accumulate(begin, end, 0ll);
}

template<typename T>
T gcd(T a, T b)
{
	T c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

template<typename T>
T bit_count(T N) {
	T cnt = 0;
	while (N) {
		if (N & 1) cnt++;
		N >>= 1;
	}
	return cnt;
}

template<typename T>
void print_vec(ostream& ostream, vector<T> a) {
	rep(i, a.size() - 1) ostream << a[i] << " ";
	ostream << a.back() << endl;
}

ll pow_n(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x;
		x = x * x;
		n >>= 1;
	}
	return res;
}

template<class T, class U>
T mod_pow(T x, U n) {
	T res = 1;
	while (n > 0) {
		if (n & 1) res = res * x;
		x = x * x;
		x %= mod_n;
		n >>= 1;
		res %= mod_n;
	}
	return res;
}

template<class T>
T mod_rev(T a) {
	T res = 1;
	return mod_pow(a, mod_n - 2);
}

int H, W;

bool grid_ng(int y, int x) {
	return y < 0 || y >= H || x < 0 || x >= W;
}

struct Point {
	int x, y;
	bool operator < (const Point& r) const {
		if (y != r.y) return y < r.y;
		return x < r.x;
	}
};

class Solver {
public:
	int n, x;
	int level_n[55];
	int level_p[55];

	int cnt(int level, int l) {
		if (level == 0) return l <= x;
		int a = level_n[level - 1];
		if (l + 1 >= x) return 0;
		if (l + 1 + a >= x) return cnt(level - 1, l + 1);
		if (l + 1 + a + 1 >= x) return level_p[level - 1] + 1;
		if (l + 1 + a + 1 + a >= x) return level_p[level - 1] + 1 + cnt(level - 1, l + 1 + a + 1);
		return level_p[level];
	}

	void solve() {
		cin >> n >> x;
		level_n[0] = 1; level_p[0] = 1;
		rep2(i, 1, n + 1) {
			level_n[i] = 2 * level_n[i - 1] + 3; dump(level_n[i]);
			level_p[i] = 2 * level_p[i - 1] + 1; dumpl(level_p[i]);
		}
		cout << cnt(n, 0) << endl;
	}
};

signed main()
{
	srand((unsigned int)time(NULL));
	cout << fixed << setprecision(20);
	auto ptr = new Solver();
	ptr->solve();
	delete ptr;
	//while (true) {
	//	if (cin.eof() == true) break;
	//	auto ptr = new Solver();
	//	ptr->solve();
	//	delete ptr;
	//}
	return 0;
}