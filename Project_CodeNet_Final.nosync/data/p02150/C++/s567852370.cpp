//実装が重そうな問題はある程度考えてから書く
//初期化を忘れずに（特に二分探索とか）
//コーナーケースを考えて（特に場合分けとか）
//不可解すぎるバグは配列外参照（配列の長さ）を検討
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
#define RREP(i,b) RFOR(i,b-1,zero)
#define ALL(c) c.begin(),c.end()
#define UNIQUE(c) sort(ALL(c));c.erase(unique(ALL(c)),c.end())
#define MAX(c) (*max_element(ALL(c)))
#define MIN(c) (*min_element(ALL(c)))
#define MP make_pair
#define FI first
#define SE second
#define SI(x) (LL(x.size()))
#define PB emplace_back
#define DEBUG(a) OUT(a)
#define DEBUG2(a,b) OUT2(a,b)
#define cat cout << __LINE__ << endl
#define OUT(a) cout << (a) << endl
#define OUT2(a,b) cout << (a) <<" "<<(b) << endl
#define int long long
#define zero 0LL
#define pb PB
using namespace std;
template<typename T> inline bool middle(T a, T b, T c) { return b <= a && a <= c; }
template<class T> inline bool MX(T &l, const T &r) { return l < r ? l = r, 1 : 0; }
template<class T> inline bool MN(T &l, const T &r) { return l > r ? l = r, 1 : 0; }
typedef long long LL;
typedef double ld;
typedef LL ut;
typedef vector<ut> VI;
typedef vector<VI> VII;
typedef pair<ut, ut> pr;
typedef pair<ut, pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr, Vpr ,greater<pr> > PQ;
inline void outputVI(VI x) { REP(i, SI(x)) { cout << three(i, " ", "") << x[i]; }OUT(""); }
int dx[] = { 0,1,0,-1,0 }, dy[] = { 1,0,-1,0,0 };
const int SIZE1 =3e5 + 1000;
const int SIZE2 = 5010;
const int SIZE3 = 22;
const int SIZE = SIZE1;
const LL p = 7 + 1e9;
const LL INF = 1LL << 60;
const long double EPS = 1e-7;
ut N, M, K, X, L, Y,H,W,Q;
// ut A,B,C,D,E,F,G,H,I,J,O,P,Q,R,T,U;
VI edges[SIZE];
LL vals[SIZE], nums[SIZE], maps[SIZE3][SIZE3], answer = zero;
LL A[SIZE], B[SIZE];
LL solve() {
	LL a, b, x;
	cin >> a >> b >> x;
	LL ans = 0;
	LL diff = a - b;
	ans += x;
	ans %= p;
	x -= a;
	if (x >= 0) {
		ans += (x / diff + 1)%p*(b%p)%p;
		ans %= p;
	}
	ans += p;
	ans %= p;
	cout << ans << endl;
	return 0;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	solve();
//	cin >> N;
	return 0;
}
