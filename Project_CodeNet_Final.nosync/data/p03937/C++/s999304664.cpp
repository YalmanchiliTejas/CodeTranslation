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

#define all(container) container.begin(), container.end()
#define sortall(container) (sort(container.begin(), container.end()))
#define yn(cond) ((cond) ? (cout << "Yes" << endl) : (cout << "No" << endl))
#define YN(cond) ((cond) ? (cout << "YES" << endl) : (cout << "NO" << endl))
#define LLONG_MAX numeric_limits<long long>::max()
#define INT_MAX numeric_limits<int>::max()

typedef long long       ll;
typedef vector<int>     vi;
typedef vector<ll>      vll;
typedef vector<double>  vd;
typedef vector<bool>    vb;
typedef vector<string>  vs;
typedef vector<char>    vc;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
typedef vector<vll>		vvll;
typedef vector<vi>		vvi;
typedef vector<vb>		vvb;
typedef vector<vs>		vvs;
typedef vector<vc>		vvc;

typedef struct edge_ {
	ll to;
	ll cost;
} edge;

typedef struct point_ {
	ll x, y;
	point_(ll x = 0, ll y = 0) : x(x), y(y) {}
} point;

constexpr double	PI = 3.14159265358979323846;
constexpr ll		INF = 1 << 15;
constexpr ll		MOD = (ll)1e9 + 7;
constexpr double	EPS = 1e-7;
constexpr int		dy4[4] = { 0, 1, 0, -1 };
constexpr int		dx4[4] = { 1, 0, -1, 0 };
constexpr int		dy8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
constexpr int		dx8[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

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

istream& operator >> (istream& is, point& p) {
	is >> p.x >> p.y;
	return is;
}

template<typename S, typename T>
ostream& operator << (ostream& os, const pair<S, T>& p) {
	os << "{" << p.first << " " << p.second << "}";
	return os;
}

ostream& operator << (ostream& os, const point& p) {
	os << "(" << p.x << " " << p.y << ")";
	return os;
}

/******************************************************************************/
/**********************         Don't make WA !!         **********************/
/******************************************************************************/

template <typename T>
class mat2D {
private:
	vector<vector<T>> data;
public:
	mat2D(int rows, int cols) : data(vector<vector<T>>(rows, vector<T>(cols))) {}
	T operator () (int row, int col) { return data[row][col]; }

	friend istream& operator >> (istream& is, mat2D<T>& m) { return is >> m.data; }
	friend ostream& operator << (ostream& os, const mat2D<T>& m) {
		for (const vector<T>& row : m.data) os << row << endl;
		return os;
	}
};

int main()
{
	int H, W;
	cin >> H >> W;
	mat2D<char> A(H, W);
	cin >> A;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (A(i, j) == '.') continue;

			int count = 0, count1 = 0;
			if (i + 1 < H && A(i + 1, j) == '#') count++;
			if (j + 1 < W && A(i, j + 1) == '#') count++;
			if (i - 1 >= 0 && A(i - 1, j) == '.') count1++;
			if (j - 1 >= 0 && A(i, j - 1) == '.') count1++;

			if (i > 0 && j > 0 && count1 == 0) {
				cout << "Impossible" << endl;
				return 0;
			}

			if (count == 0 && i != H - 1 && j != W - 1) {
				cout << "Impossible" << endl;
				return 0;
			}

			if (count == 2) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}

	cout << "Possible" << endl;

	return 0;
}