#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>
#include <cmath>
#include <complex>
#include <cctype>
#include <map>
#include <queue>

using namespace std;
#define PI       3.14159265358979323846
#define MOD 1000000007

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef complex<double> P;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;

struct edge {
	int to;
	LL d;
	edge(int _to, LL _d) : to(_to), d(_d) {}
};

using graph = vector<vector<edge> >;

struct state {
	LL d;
	int v;
	state(LL _d, int _v) : v(_v), d(_d) {}
	bool operator<(const state& right)const {
		return d == right.d ? v < right.v : d < right.d;
	}
	bool operator>(const state& right)const {
		return d == right.d ? v > right.v : d > right.d;
	}
};

LL dp1[100005];
LL dp2[100005];
LL d1[100005];
LL d2[100005];

void calc(graph g, int s, LL *d, LL *dp) {
	priority_queue<state, vector<state>, greater<state>> q;
	q.push(state(0LL, s));
	d[s] = 0;
	dp[s] = 1;
	while (!q.empty()) {
		state tmp = q.top();
		q.pop();
		auto tv = tmp.v;
		auto td = tmp.d;
		if (td > d[tv])continue;
		REP(i, g[tv].size()) {
			if (td + g[tv][i].d < d[g[tv][i].to]) {
				d[g[tv][i].to] = td + g[tv][i].d;
				dp[g[tv][i].to] = dp[tv];
				q.push(state(d[g[tv][i].to], g[tv][i].to));
			}
			else if (td + g[tv][i].d == d[g[tv][i].to]) {
				dp[g[tv][i].to] = (dp[g[tv][i].to]+dp[tv])%MOD;
			}
		}
	}
}

int main() {
	memset(d1, 0x77, sizeof(d1));
	memset(d2, 0x77, sizeof(d2));
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	s--, t--;
	graph g(n);
	REP(i, m) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		u--, v--;
		g[u].PB(edge(v, d));
		g[v].PB(edge(u, d));
	}
	calc(g, s, d1, dp1);
	calc(g, t, d2, dp2);

	LL ret = (dp1[t] * dp1[t]) % MOD;
	// meet on point
	REP(i, n) {
		if (2 * d1[i] == d1[t]) {
			LL tmp = dp1[i];
			tmp = (tmp*dp1[i]) % MOD;
			tmp = (tmp*dp2[i]) % MOD;
			tmp = (tmp*dp2[i]) % MOD;
			ret = (ret + MOD - tmp) % MOD;
		}
	}
	// meet on edge
	REP(i, n) {
		if (2 * d1[i] >= d1[t])continue;
		REP(j, g[i].size()){
			if (2 * d2[g[i][j].to] >= d2[s])continue;
			if (d1[i] + d2[g[i][j].to] + g[i][j].d == d1[t]) {
				LL tmp = dp1[i];
				tmp = (tmp*dp1[i]) % MOD;
				tmp = (tmp*dp2[g[i][j].to]) % MOD;
				tmp = (tmp*dp2[g[i][j].to]) % MOD;
				ret = (ret + MOD - tmp) % MOD;
			}
		}
	}
	cout << ret << endl;
	return 0;
}
