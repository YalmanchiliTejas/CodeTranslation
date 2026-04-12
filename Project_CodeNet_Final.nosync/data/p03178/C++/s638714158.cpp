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
ut N, M, K, L, Q, D, H,W;
// ut A,B,C,D,E,F,G,H,I,J,O,P,Q,R,T,U;

VI edges[SIZE];
LL vals[SIZE], maps2[SIZE2][SIZE2], answer = zero;
LL maps[SIZE2][SIZE2];
LL DP[10101][101][2];
bool finished[10101][101][2];
LL A[SIZE2][SIZE2];
string s;
LL solve2(LL keta,LL amari,LL able) {
	if (keta==s.size()) return amari==0;
	if (finished[keta][amari][able]) return DP[keta][amari][able];
	finished[keta][amari][able] = true;
	LL ans = 0;
	if (able) {
		EFOR(i, 0, 9) {
			ans += solve2(keta + 1, (amari + i)%D, able);
			ans %= p;
		}
	//	cout << keta << " " << amari << " " << able << endl;
	}
	else {
		EFOR(i, 0, s[keta] - '0') {
			//if (keta == 0 and i == 0) continue;
		//	cout << ans << endl;
			ans += solve2(keta + 1, (amari + i)%D, i!=(s[keta] - '0'));
			ans %= p;
			//	cout << ans << endl;
	//		cout << keta << " " << amari << endl;
		}
	}
	return DP[keta][amari][able]=ans%p;
}
LL solve() {
	LL ans = 0;
	cin >>s;
	cin >> D;
	ans += solve2(0, 0, 0);
	cout << (ans-1+p)%p << endl;
	return 0;
}




//!!!!!!!!!!!!!!!!!!!実装を詰める!!!!!!!!!!!!!!!!!!!!!!!!!
signed main() {

	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(0);
	solve();
	cin >> N;
	return 0;

}
