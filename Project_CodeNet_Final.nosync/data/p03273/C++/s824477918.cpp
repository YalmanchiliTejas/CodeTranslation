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
#define dump(x) cerr << #x << " = " << (x) << " "
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

struct Point {
	int y, x;
	bool operator < (const Point& r) {
		if (x < r.x) return true;
		else return false;
	}
};

class Solver {
public:
	int H, W;

	bool grid_ok(int y, int x) {
		return 0 <= y && y < H && 0 <= x && x < W;
	}

	int N;
	vector<string> field;

	bool all_white1(string& s) {
		rep(i, W) {
			if (s[i] == '#') return false;
		}
		return true;
	}

	bool all_white2(int j) {
		rep(i, H) {
			if (field[i][j] == '#') return false;
		}
		return true;
	}

	void solve() {
		cin >> H >> W;
		rep(i, H) {
			string s; cin >> s;
			if (not all_white1(s)) field.push_back(s);
		}
		H = field.size();
		bool arr[105] = {};
		rep(i, W) {
			if (all_white2(i)) arr[i] = true;
		}
		rep(i, H) {
			rep(j, W) {
				if (arr[j] == true) continue;
				cout << field[i][j];
			}
			cout << endl;
		}
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
