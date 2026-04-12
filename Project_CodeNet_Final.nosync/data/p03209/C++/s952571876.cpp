#include "bits/stdc++.h"
using namespace std;
typedef long long int lint;
typedef pair<lint, lint> plint;
typedef pair<double long, double long> pld;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
const lint MOD = 1e9 + 7, INF = 1e18;

lint N, X;
lint dp_a[51], dp_p[51];

lint rec(lint n, lint x) {
	if (n == 0) return 1;
	if (x == 1) return 0;
	if (x < 2 + dp_a[n - 1]) return rec(n - 1, x - 1);
	if (x == 2 + dp_a[n - 1]) return dp_p[n - 1] + 1;
	if (x < 3 + 2 * dp_a[n - 1]) return dp_p[n - 1] + 1 + rec(n - 1, x - 2 - dp_a[n - 1]);
	else return 2 * dp_p[n - 1] + 1;
}


int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> X;
	dp_a[0] = 1;
	dp_p[0] = 1;
	REP(i, 50) {
		dp_a[i + 1] = 2 * dp_a[i] + 3;
		dp_p[i + 1] = 2 * dp_p[i] + 1;
	}
	cout << rec(N, X);
}
