#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define REP(i,a,n) for(LL i = (a); i < (LL)(n); ++i)
#define REM(i,a,n) for(LL i = ((n) - 1); i >= (a); --i)
#define FLOAT fixed << setprecision(16)
#define SPEEDUP {cin.tie(0); ios::sync_with_stdio(false);}
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
// all_of
// partial_sum, adjacent_difference

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
#endif

struct Edge {
	LL from, to, cost;
};


int A, B;
int D[11][11];
int C[101][101];
vector<Edge> G;

int main() {
	cin >> A >> B;

	REP(i, 0, A) {
		REP(j, 0, B) {
			cin >> D[i + 1][j + 1];
		}
	}

	REP(x, 0, 101) {
		REP(y, 0, 101) {
			REP(a, 1, A + 1) {
				REP(b, 1, B + 1) {
					C[x][y] = max(C[x][y], D[a][b] - (int)(a * x + b * y));
				}
			}
		}
	}
	
	bool ok = 1;
	REP(a, 1, A + 1) {
		REP(b, 1, B + 1) {
			int mn = INF;
			REP(x, 0, 101) {
				REP(y, 0, 101) {
					mn = min(mn, C[x][y] + (int)(a * x + b * y));
				}
			}
			if (mn != D[a][b]) {
				ok = 0;
			}
		}
	}

	cout << (ok ? "Possible" : "Impossible") << endl;
	if (ok) {
		const int XX = 12345;
		const int YY = 56789;

		int X = 101;
		int Y = 101;
		REP(i, 0, X) G.push_back(Edge{ i, i + 1, XX });
		REP(i, 0, Y) G.push_back(Edge{ i + X, i + X + 1, YY });

		int S = X;
		REP(i, 0, X + 1) {
			REP(j, 0, Y + 1) {
				if (i == X || j == Y) continue;
				G.push_back(Edge{ S - (X - i),  S + (Y - j), C[i][j] });
			}
		}

		cout << X + Y + 1 << ' ' << G.size() << endl;
		for (auto e : G) {
			cout << e.from + 1 << ' ' << e.to + 1 << ' ';
			if (e.cost == XX) {
				cout << 'X' << endl;
			} else if (e.cost == YY) {
				cout << 'Y' << endl;
			} else {
				cout << e.cost << endl;
			}
		}
		cout << 1 << ' ' << X + Y + 1 << endl;
	}
	return 0;
}