#include "bits/stdc++.h"
#define YES "YES"
#define Yes "Yes"
#define NO "NO"
#define No "No"
#define YESNO OUT(three(solve(),YES,NO))
#define YesNo OUT(three(solve(),Yes,No))
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
typedef long double ld;
typedef LL ut;
typedef vector<ut> VI;
typedef vector<VI> VII;
typedef pair<ut, ut> pr;
typedef pair<ut, pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr, Vpr, greater<pr> > PQ;
inline void outputVI(VI x) { REP(i, SI(x)) { cout << three(i, " ", "") << x[i]; }OUT(""); }
int dx[] = { 0,1,0,-1,1,1,-1,-1,0 }, dy[] = { 1,0,-1,0,1,-1,1,-1,0 };
const int SIZE1 = 5e5 + 1000;
const int SIZE2 = 1010;
const int SIZE3 = 201;
const int SIZE = SIZE1;
const LL p = 7+1e9;
const LL INF = 1LL<<60;
const long double EPS = 1e-7;
ut N, M, K, L, H, W, Q, D, T;
// ut A,B,C,D,E,F,G,H,I,J,O,P,Q,R,T,U;
Vpr edges[SIZE];
LL vals[SIZE], nums[SIZE], maps[SIZE2][SIZE2], answer = zero;
LL A[SIZE], B[SIZE], C[SIZE], X, Y[SIZE];
LL DP[SIZE][2][2];
LL DP2[SIZE];
LL same() {
	DP[0][0][0] = 1;
	DP[0][1][1] = 1;
	FOR(i, 1, N) {
		REP(j, 2) {
			DP[i][j][0] = DP[i - 1][j][1]%p;
			DP[i][j][1] = (DP[i - 1][j][1]+DP[i-1][j][0]) % p;
		}
	}
	LL ans = DP[N - 1][0][1] + DP[N - 1][1][0] + DP[N - 1][1][1];
//	cout << DP[N - 1][0][1] << DP[N - 1][1][1] << DP[N - 1][1][1] << endl;
	return ans % p;
}
LL BIT[SIZE];
void add(LL x, LL val) {
	x++;
	while (x < SIZE) {
		BIT[x] += val;
		BIT[x] %= p;
		x += x & -x;
	}

}
LL sum(LL x) {
	x++;
	LL ans = 0;
	while (x > 0) {
		ans += BIT[x]%p;
		x -= x & -x;
	}
	return ans%p;
}
LL sum(LL a, LL b) {
	MX(a, 0LL);
	MX(b, 0LL);
	return (sum(b) - sum(a - 1)+p)%p;
}
LL solve2(LL n,LL range) {
	if (n % 2) return 0;
	DP2[0] = 1;
	add(0, 1);
	FOR(i, 1, n) {
		if (i % 2) continue;
		DP2[i] = sum(i - range-1, i - 1)%p;
		add(i, DP2[i]);
	}
	LL ans = 0;
	REP(i, n) {
		if (n - (i+1)<=range) {
			ans += DP2[i] * (n-i)%p;
			ans %= p;
		}
		
	}
	return ans;
}
LL solve() {
	cin >> N >> M;
	
	string s;
	cin >> s;
	REP(i, M) {
		if (s[i] != s[0])
			break;
		if (M - 1 == i) {
			return same();
		}
	}
	if (s[0] != s[1]) {
		return 2;
	}
	LL minium = INF;
	LL diffed = 0;
	int now = 0;
	REP(i, M) {
		if (s[i] != s[0]) {
			if (diffed == 0) {
				MN(minium, now / 2 * 2 + 1);
			}
			else if (now % 2 == 0);
			else {

				MN(minium, now);
			}
			now = 0;
			diffed++;
		}
		else {
			now++;
		}
	}
	//cout << minium << endl;

	LL ans = solve2(N,minium);
	return ans%p;
}
signed main() {

	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	cout << solve() << endl;
	//	cin >> N;
	return 0;
}
