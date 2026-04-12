#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
//#pragma warning(disable : 4996)

#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#define __builtin_popcountll __popcnt64
#endif

#include <limits.h>
#include <math.h>
#include <time.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m - 1; i >= n; --i)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v, n) reverse(v, v + n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout << (x) << '\n'
#define pe(x) cout << (x) << " "
#define DEBUG(x) cout << #x << ": " << x << endl
#define lb(v, n) lower_bound(v.begin(), v.end(), (n))
#define ub(v, n) upper_bound(v.begin(), v.end(), (n))
#define int unsigned long long
//#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i, v.size()) cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template <typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template <typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
std::random_device rd;
std::mt19937 mt(rd());
constexpr ll MOD = 1e9 + 7;
constexpr int MAX = 10050;
const double pi = acos(-1);
constexpr double EPS = 1e-8;
constexpr ll LINF = 1e18 + 1;
constexpr int INF = 1e9 + 1;
using ull = uint64_t;

ull A[505][505];
ull U[505], V[505];
bool S[505], T[505];

int N;

void fail() {
	print(-1); exit(0);
}

void slv(int b) {
	//DEBUG(b);
	bitset<505>R, C;
	REP(i, N) {
		R[i] = C[i] = false;
	}
	static bitset<505> res[505];
	REP(i, N)REP(j, N) {
		res[i][j] = false;
	}
	REP(i, N) {
		if (U[i] >> b & 1)R[i] = 1;
		else R[i] = 0;
		if (V[i] >> b & 1)C[i] = 1;
		else C[i] = 0;
	}
	//cerr << "R:" << R << endl;
	//cerr << "C:" << C << endl;
	static bitset<505>done[505];
	REP(i, N)REP(j, N)done[i][j] = false;
	//col
	REP(j, N) {
		if (T[j] && C[j]) {
			REP(i, N) {
				res[i][j] = true;
				done[i][j] = true;
			}
		}
		else if ((!T[j]) && !C[j]) {
			REP(i, N) {
				res[i][j] = false;
				done[i][j] = true;	
			}
		}
	}
	//REP(i, N) {
	//	REP(j, N) {
	//		cerr << res[i][j] << " \n"[j == N - 1];
	//	}
	//}
	//row
	REP(i, N) {
		if (S[i] && R[i]) {
			REP(j, N) {
				if (done[i][j]&&!res[i][j])fail();
				else res[i][j] = true;
				done[i][j] = true;
			}
		}
		else if ((!S[i]) && !R[i]) {
			REP(j, N) {
				if (done[i][j]&&res[i][j])fail();
				else res[i][j] = false;
				done[i][j] = true;
			}
		}
	}
	//cerr << "ok1" << endl;
	//REP(i, N) {
	//	REP(j, N) {
	//		cerr << res[i][j] << " \n"[j == N - 1];
	//	}
	//}
	//REP(i, N) {
	//	REP(j, N) {
	//		cerr << done[i][j] << " \n"[j == N - 1];
	//	}
	//}
	//if each col's condition is satisfied
	vector<bool>ok(N);
	int idx = -1;
	REP(j, N) {
		if (T[j] && C[j]) {
			ok[j] = true;
		}
		else if ((!T[j]) && !C[j]) {
			ok[j] = true;
		}
	}
	REP(i, N) {
		idx = -1;
		REP(j, N)if (ok[j]&&!done[i][j])idx = j;
		//AND = 0 | OR = 1
		if ((S[i] && !R[i])||((!S[i]) && R[i])) {
			bool good = false;
			REP(j, N) {
				if (done[i][j] && (res[i][j]==R[i]))good = true;
			}
			if (good) { //already good
				REP(j, N) {
					ok[j] = true;
					if (!done[i][j]) {
						res[i][j] = C[j];
					}
					done[i][j] = true;
				}
			}
			else {
				if (idx != -1) { 
					REP(j, N)if (!done[i][j]) {
						if (idx == j)res[i][j] = R[i];
						else {
							res[i][j] = C[j];
							ok[j] = true;
						}
						done[i][j] = true;
					}
				}
				else { //no cols's conditions are satisfied
					bool found = false;
					REP(j, N) {
						if (C[j] == R[i]) {
							found = true;
						}
					}
					if (found) {
						REP(j, N)if(!done[i][j]) {
							done[i][j] = true;
							res[i][j] = C[j];
							ok[j] = true;
						}
					}
					else {
						bool fin = false;
						REP(j, N)if (!done[i][j]) {
							if (fin) {
								res[i][j] = C[j];
								ok[j] = true;
							}
							else {
								res[i][j] = R[i];
								fin = true;
							}
							done[i][j] = true;
						}
					}

				}
			}
		}
	}
	//cerr << "constructed" << endl;
	//REP(i, N) {
	//	REP(j, N) {
	//		cerr << res[i][j] << " \n"[j == N - 1];
	//	}
	//}
	//check
	REP(i,N){
		bool OR = 0, AND = 1;
		REP(j, N) {
			OR |= res[i][j];
			AND &= res[i][j];
		}
		if (S[i] && (R[i] != AND))fail();
		if ((!S[i]) && (R[i] != OR))fail();
	}
	//cerr << "row ok" << endl;
	REP(j, N) {
		bool OR = 0, AND = 1;
		REP(i, N) {
			OR |= res[i][j];
			AND &= res[i][j];
		}
		if (T[j] && (C[j] != AND))fail();
		if ((!T[j]) && (C[j] != OR))fail();
	}
	//cerr << "column ok" << endl;

	REP(i, N) {
		REP(j, N) {
			if (res[i][j]) {
				A[i][j] |= (1ULL << b);
			}
		}
	}
}

void solve() {
	cin >> N;
	REP(i, N) {
		cin >> S[i];
		S[i] = !S[i];
	}
	REP(i, N) {
		cin >> T[i];
		T[i] = !T[i];
	}
	REP(i, N)cin >> U[i];
	REP(i, N)cin >> V[i];
	REP(b, 64)slv(b);
	REP(i, N) {
		REP(j, N) {
			cout << A[i][j] << " \n"[j == N - 1];
		}
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	//int q;
	//cin >> q;
	//while (q--)
	solve();
}
