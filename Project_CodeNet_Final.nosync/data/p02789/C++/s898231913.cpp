#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>
#include <cassert>
#include <random>
#include <valarray>
//#include <fstream>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define next next239
#define prev prev239
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define ba back()
#define fastIO() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define in(x) int x; cin >> x;
#define in1(x) int x; cin >> x; x--;
#define inll(x) ll x; cin >> x;
#define ins(x) string x; cin >> x;

#ifdef LOCAL_BOBER
bool local = true;
#define deb(x) cout << #x << " = " << (x) << endl
#define debn(x, n) { cout << #x << "(" << n << ") = " << \
	"{"; int _f_ = 1; rep(_i_, n) {if (!_f_) cout << "|"; cout << x[_i_]; _f_= 0;} cout << "}" << endl;}
#define deba(x) { cout << #x << " (size: " << sz(x) << ") = " << \
	"{"; int _f_ = 1; for (auto o : x) {if (!_f_) cout << "|"; cout << o; _f_ = 0;} cout << "}" << endl;}
#else
bool local = false;
#define deb(x) ;
#define debn(x, n) ;
#define deba(x) ;
#define endl "\n"
#endif

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef pair<double, double> pdd;
typedef long double LD;
typedef double D;

template<class T> string toString(T x) { ostringstream sout; sout << x;	re sout.str();}
template<class T> void print(T v) { cout << sz(v) << endl; for (auto x : v) cout << x << ' '; cout << endl; };
template<class T1, class T2> ostream& operator << (ostream &o, pair<T1, T2> x) {re o << x.fi << ' ' << x.se;}
template<class T1, class T2> istream& operator >> (istream &o, pair<T1, T2> &x) {re o >> x.fi >> x.se;}
template<class T1, class T2> pair<T1, T2> operator + (pair<T1, T2> a, pair<T1, T2> b) {a.fi += b.fi; a.se += b.se; re a;}
template<class T1, class T2> pair<T1, T2> operator - (pair<T1, T2> a, pair<T1, T2> b) {a.fi -= b.fi; a.se -= b.se; re a;}
template<class T1, class T2> void operator += (pair<T1, T2> &a, pair<T1, T2> b) {a.fi += b.fi; a.se += b.se;}
template<class T1, class T2> void operator -= (pair<T1, T2> &a, pair<T1, T2> b) {a.fi -= b.fi; a.se -= b.se;}

int nint() {int x; cin >> x; re x;}
double getTime() { re clock() / (double) CLOCKS_PER_SEC;};

mt19937 rnd(0);
int rand(int n) { re rnd() % n; }
int rand(int l, int r) { re rnd() % (r - l + 1) + l; }

const int mod = 1000000000 + 7;

void initIO() {
	if (local) {
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
		srand((int)time(0));
		rnd.seed((int)time(0));
	}
	else {
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
		fastIO();
	}
}

void solve();

int main() {
	initIO();

	int tc = 1;
//	cin >> tc;
	rep(tt, tc) {
//		cout << "Case #" << tt + 1 << ": ";
		solve();
	}

	if (local)
		cout << endl << "time = " << getTime() << endl;
}


/* ================ actual code starts here ================ */

int n;
int m;

void solve() {
	cin >> n >> m;
	cout << (n == m ? "Yes" : "No");
}









