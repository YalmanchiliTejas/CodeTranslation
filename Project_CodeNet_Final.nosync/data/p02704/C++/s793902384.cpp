#define _CRT_SECURE_NO_WARNINGS
#define REL

#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include <set>
#include <bitset>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <complex>
#include <stack> 
#include <random>

using namespace std;

typedef int64_t i64;
typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef complex <LD> cld;
typedef unsigned int uint;
typedef complex <double> cd;
typedef unsigned long long ULL;

#define endl "\n"
#define dendl "\n\n"
#define mp make_pair
#define mt make_tuple
#define size(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

/////////////////////////////////////////////////////////////////////

template <typename T>
T sqr(T a) {
	return a * a;
}

template <typename T>
int sign(T a) {
	if (a == 0)
		return 0;
	return (a > 0 ? 1 : -1);
}

template <typename T>
bool uax(T& a, const T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T>
bool uin(T& a, const T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T1, typename T2>
istream& operator >> (istream& in, pair<T1, T2>& p) {
	in >> p.first >> p.second;
	return in;
}

template <typename T1, typename T2>
ostream& operator << (ostream& out, pair<T1, T2>& p) {
	out << p.first << ' ' << p.second;
	return out;
}

mt19937_64 rnd(0);

const int LOG = 64;
const int N = (int)507;
const int MAXN = (int)3e3 + 7;
const int MOD = (int)998244353;
const int INF = (int)1e9 + 7;
const int CONST = 450;
const LL LINF = (i64)1e17;
const LD PI = 3.1415926535897932384626433832795;
const LD EPS = 1;

/////////////////////////////////////////////////////////////////////

int bit[N][N];
bool done_row[N], done_col[N];
ULL ans[N][N], row_val[N], col_val[N];
int n, row_op[N], col_op[N], row_type[N][LOG], col_type[N][LOG];

bool check_bit(ULL x, int pos) {
	return (x & (1ULL << pos)) > 0;
}

void color_row(int row, int val, int b) {
	for (int col = 0; col < n; col++) {
		if (bit[row][col] == 1 - val) {
			cout << -1;
			exit(0);
		}
		if (col_type[col][b] % 2 == val)
			done_col[col] = true;
		bit[row][col] = val;
	}
}

void color_col(int col, int val, int b) {
	for (int row = 0; row < n; row++) {
		if (bit[row][col] == 1 - val) {
			cout << -1;
			exit(0);
		}
		if (row_type[row][b] % 2 == val)
			done_row[row] = true;
		bit[row][col] = val;
	}
}

void finish(const vector <int>& rest_row, const vector <int>& rest_col, int row_val, int col_val) {
	if (!size(rest_row) || !size(rest_col))
		return;
	if (size(rest_row) == 1 || size(rest_col) == 1) {
		cout << -1;
		exit(0);
	}
	for (int i = 0; i < size(rest_row); i++) {
		for (int j = 0; j < size(rest_col); j++) {
			int row = rest_row[i], col = rest_col[j];
			if (i == j) {
				if (size(rest_row) <= size(rest_col)) {
					bit[row][col] = row_val;
					done_row[row] = true;
				}
				else {
					bit[row][col] = col_val;
					done_col[col] = true;
				}
			}
			else {
				if (size(rest_row) <= size(rest_col)) {
					bit[row][col] = col_val;
					done_col[col] = true;
				}
				else {
					bit[row][col] = row_val;
					done_row[row] = true;
				}
			}
		}
	}
}

void solve(int b) {
	for (int i = 0; i < n; i++)
		fill(bit[i], bit[i] + n, -1);
	fill(done_row, done_row + n, false);
	fill(done_col, done_col + n, false);

	for (int i = 0; i < n; i++) {
		if (row_type[i][b] == 1 || row_type[i][b] == 2) {
			color_row(i, row_type[i][b] % 2, b);
			done_row[i] = true;
		}
		if (col_type[i][b] == 1 || col_type[i][b] == 2) {
			color_col(i, col_type[i][b] % 2, b);
			done_col[i] = true;
		}
	}

	for (int rep = 0; rep < 2; rep++) {
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				if (bit[row][col] != -1)
					continue;
				if (row_type[row][b] == col_type[col][b]) {
					bit[row][col] = row_type[row][b] % 2;
					done_row[row] = done_col[col] = true;
				}
				if (!done_row[row] && done_col[col]) {
					bit[row][col] = row_type[row][b] % 2;
					done_row[row] = true;
				}
				if (done_row[row] && !done_col[col]) {
					bit[row][col] = col_type[col][b] % 2;
					done_col[col] = true;
				}
			}
		}
	}

	vector <int> rest_row[2], rest_col[2];
	for (int i = 0; i < n; i++) {
		if (!done_row[i])
			rest_row[row_type[i][b] % 2].push_back(i);
		if (!done_col[i])
			rest_col[col_type[i][b] % 2].push_back(i);
	}

	finish(rest_row[0], rest_col[1], 0, 1);
	finish(rest_row[1], rest_col[0], 1, 0);

	for (int i = 0; i < n; i++) {
		if (!done_row[i] || !done_col[i]) {
			cout << -1;
			exit(0);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bit[i][j] = (bit[i][j] == -1 ? 0 : bit[i][j]);
			ans[i][j] |= 1ULL * bit[i][j] << b;
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> row_op[i];
	for (int i = 0; i < n; i++)
		cin >> col_op[i];
	for (int i = 0; i < n; i++) {
		cin >> row_val[i];
		for (int j = 0; j < LOG; j++) {
			int a = row_op[i], b = check_bit(row_val[i], j);
			row_type[i][j] = 2 * a + b;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> col_val[i];
		for (int j = 0; j < LOG; j++) {
			int a = col_op[i], b = check_bit(col_val[i], j);
			col_type[i][j] = 2 * a + b;
		}
	}
	for (int i = 0; i < LOG; i++)
		solve(i);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
}

int main() {
	double start = clock();
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cout << fixed << setprecision(20);
	cerr << fixed << setprecision(20);
#else
	cout << fixed << setprecision(20);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	rnd.seed(time(0));
#endif

	int t = 1;
	for (int i = 0; i < t; i++) {
		solve();
	}

#ifdef _DEBUG
	cout << endl << "Time is " << (clock() - start) / 1000.0;
#endif
}