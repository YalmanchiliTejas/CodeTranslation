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
using namespace std;


typedef long long       ll;
struct edge { ll to; ll cost; };
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

// マクロ
#define repr(itr, bgn, end) for (ll itr = (ll)bgn; itr < (ll)end; ++itr)
#define rep(itr, end) repr(itr, 0, end)
#define reprrev(itr, bgn, end) for (ll itr = (ll)end - 1; itr >= (ll)bgn; --i)
#define reprev(itr, end) reprrev(itr, 0, end)
#define all(container) container.begin(), container.end()
#define sortall(container) sort(all(container))
#define yn(cond) cond ? (cout << "Yes" << endl) : (cout << "No" << endl)
#define YN(cond) cond ? (cout << "YES" << endl) : (cout << "NO" << endl)

// 定数
#define LLONG_MAX 9223372036854775807
constexpr double PI = 3.14159265358979323846;
constexpr ll INF = 1 << 15;
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-7;

// よく使うもの
constexpr int dy[4] = { 0, 1, 0, -1 };
constexpr int dx[4] = { 1, 0, -1, 0 };


// vector入力
template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
	for (T& x : vec) is >> x;
	return is;
}

// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for (T& x : vec) os << x << " ";
	return os;
}

// ***<ここから>****************************************************************



int main(void) {

	int H, W;
	cin >> H >> W;
	vvc a(H, vc(W));
	rep(i, H) rep(j, W) cin >> a[i][j];

	rep(i, H) {
		bool ok = false;
		rep(j, W) {
			if (a[i][j] == '#') {
				ok = true;
				break;
			}
		}
		if (ok) continue;

		rep(j, W) a[i][j] = 'o';
	}

	rep(j, W) {
		bool ok = false;
		rep(i, H) {
			if (a[i][j] == '#') {
				ok = true;
				break;
			}
		}
		if (ok) continue;

		rep(i, H) a[i][j] = 'o';
	}

	rep(i, H) {
		bool out = false;
		rep(j, W) {
			if (a[i][j] != 'o') {
				cout << a[i][j];
				out = true;
			}
		}
		if (out) cout << endl;
	}





	return 0;
}
