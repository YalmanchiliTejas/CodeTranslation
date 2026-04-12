#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <limits>
#include <numeric>
#include <valarray>
#include <fstream>

using namespace std;
typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PP;
#define REP(i, a, n) for(LL i = (a), i##_max = (n); i < i##_max; ++i)
#define REM(i, a, n) for(LL i = (LL)(n) - 1, i##min = (a); i >= i##min; --i)
#define ALL(arr) (arr).begin(), (arr).end()
#define FLOAT fixed << setprecision(16)
#define SPEEDUP {cin.tie(NULL); ios::sync_with_stdio(false);}
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const string INFSTR = "\x7f";
const double EPS = 1.0e-9;

void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
template <class T, class U>
istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U>
ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N>
void Fill(T(&dest)[N], const TCompatible& val) { fill(dest, dest + N, val); }
template <class T, class TCompatible, size_t M, size_t N>
void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
template<class T>
T Compare(T left, T right) { return left > right ? 1 : (left < right ? -1 : 0); }
istream& Ignore(istream& ist) { string s; ist >> s; return ist; }
bool Inside(int i, int j, int h, int w) { return i >= 0 && i < h && j >= 0 && j < w; }
template <class T>
T Next() { T buf; cin >> buf; return buf; }

#ifdef ONLY_MY_ENVIR
#include "IntMod.h"
#include "Union_Find.h"
#include "Graph.h"
#include "Range.h"
#include "Global.h"
#include "Flow_Solver.h"
#include "Tree.h"
#include "Suffix_Array.h"
#include "Geometry.h"
#include "Matrix.h"
#include "Segment_Tree.h"
#include "Rational.h"
#include "Position.h"
#include "Factorization.h"
#endif

#ifdef __GNUC__
typedef __int128 LLL;
istream& operator>> (istream& ist, __int128& val) { LL tmp;  ist >> tmp; val = tmp; return ist; }
ostream& operator<< (ostream& ost, __int128 val) { LL tmp = val; ost << tmp; return ost; }
#endif

#if 1234567891
#include <array>
#include <random>
#include <unordered_set>
#include <unordered_map>
template<typename T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;	// コスト小を優先
template <class T>
auto Is(const T& value) { return [value](const auto& comparand) -> bool { return comparand == value; }; }
#endif

int N;
ULL M;
ULL B[3004][3004];
ULL C[3004][3004];

ULL Powmod(ULL base, ULL exp, ULL mod) {
	if (exp == 0) return 1;
	if (exp % 2 == 1) return Powmod(base, exp - 1, mod) * base % mod;
	ULL tmp = Powmod(base, exp / 2, mod);
	return tmp * tmp % mod;
}

ULL Except(int k) {
	ULL base = Powmod(2, N - k, M);
	ULL prod = 1;
	ULL sum = 0;
	REP(j, 0, k + 1) {
		sum = (sum + B[k + 1][j + 1] * prod) % M;
		prod = prod * base % M;
	}

	ULL right = Powmod(2, Powmod(2, N - k, M - 1), M);
	return sum * right % M;
}

int main() {
	cin >> N >> M;

	B[0][0] = 1;
	REP(n, 1, N + 4) {
		REP(k, 1, N + 4) {
			B[n][k] = (B[n - 1][k - 1] + k * B[n - 1][k] % M) % M;
		}
	}

	REP(i, 0, N + 4) {
		C[i][0] = C[i][i] = 1;
	}
	REP(n, 1, N + 4) {
		REP(k, 1, N + 4) {
			C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % M;
		}
	}

	ULL sum = Powmod(2, (Powmod(2, N, M - 1)), M);
	
	REP(i, 1, N + 1) {
		ULL tmp = Except(i) * C[N][i] % M;
		if (i % 2 == 0) {
			sum = (sum + tmp) % M;
		} else {
			sum = (sum + M - tmp) % M;
		}
	}
	cout << sum << endl;
	return 0;
}
