// HTTF.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "bits/stdc++.h"
#define YES "YES"
#define NO "NO"
#define YESNO OUT(three(solve(),YES,NO))
#define ECHO OUT(solve())
#define three(A,B,C) ((A)?(B):(C))
#define FOR(i,a,b)  for(LL i=(a);i< (LL)(b);i++)
#define EFOR(i,a,b) for(LL i=(a);i<=(LL)(b);i++)
#define RFOR(i,a,b) for(LL i=(a);i>=(LL)(b);i--)
#define REP(i,b) FOR(i,zero,b)
#define EREP(i,b) EFOR(i,zero,b)
#define RREP(i,b) RFOR(i,b,zero)
#define ALL(c) c.begin(),c.end()
#define UNIQUE(c) sort(ALL(c));c.erase(unique(ALL(c)),c.end())
#define MAX(c) (*max_element(ALL(c)))
#define MIN(c) (*min_element(ALL(c)))
#define MP make_pair
#define FI first
#define SE second
#define SI(x) (LL(x.size()))
#define PB push_back
#define DEBUG(a) OUT(a)
#define DEBUG2(a,b) OUT2(a,b)
#define cat cout << __LINE__ << endl
#define OUT(a) cout << (a) << endl
#define OUT2(a,b) cout << (a) <<" "<<(b) << endl
#define zero 0LL
#define int LL
#define pb emplace_back
#define eb pb

using namespace std;
template<typename T> inline void maximize(T &a, T b) { a = max(a, b); }
template<typename T> inline void minimize(T &a, T b) { a = min(a, b); }
template<typename T> inline bool middle(T a, T b, T c) { return b <= a && a <= c; }
template<class T> inline bool MX(T &l, const T &r) { return l < r ? l = r, 1 : 0; }
template<class T> inline bool MN(T &l, const T &r) { return l > r ? l = r, 1 : 0; }
typedef long long LL;
typedef double ld;
typedef int ut;
typedef vector<ut> VI;
typedef vector<VI> VII;
typedef pair<ut, ut> pr;
typedef pair<ut, pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr, Vpr, greater<pr> > PQ;
inline void outputVI(VI x) { REP(i, SI(x)) { cout << three(i, " ", "") << x[i]; }OUT(""); }
const int SIZE1 = 5e5 + 1000;
const int SIZE2 = 3010;
const int SIZE3 = 330;
const int SIZE = SIZE1;
const int MAPSIZE = 40;
const LL p = 7 + 1e9;
const LL INF = 1LL << 60;
const long double EPS = 1e-7;
typedef pair<ld, ut> pld;

#define endl "\n" //インタラクティブでは消す
ut N, M, K, L, Q, D, H, W;
// ut A,B,C,D,E,F,G,H,I,J,O,P,Q,R,T,U;
VI edges[SIZE];
LL vals[SIZE], maps2[SIZE2][SIZE2], answer = zero;
LL maps[SIZE2][SIZE2];
LL DP[SIZE2][SIZE2];
bool finished[SIZE2][SIZE2];
LL A[SIZE];
string s, t;
LL solve2(LL a,LL b,bool ismax) {
	if (a==b) return 0;
	if (finished[a][b]) return DP[a][b];
	finished[a][b] = true;
	if (ismax) {
		DP[a][b] = max(solve2(a + 1, b, 0) + A[a], solve2(a, b - 1, 0) + A[b - 1]);
	}
	else {
		DP[a][b] = min(solve2(a + 1, b, 1) - A[a], solve2(a, b - 1, 1) - A[b - 1]);
	}
	//cout << a << " " << b << " " << DP[a][b] << endl;
	return DP[a][b];
}
LL solve() {
	cin >> N ;
	REP(i, N) cin >> A[i];
	cout << solve2(0, N,1) << endl;
	return 0;
}




//!!!!!!!!!!!!!!!!!!!実装を詰める!!!!!!!!!!!!!!!!!!!!!!!!!
signed main() {

	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(12);
	solve();
	cin >> N;
	return 0;

}