#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>
#include <cstdint>
#include <tuple>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) (a*a)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

using edge = PII;
using node = vector<edge>;
using graph = vector<node>;

int main() {
	int n;
	cin >> n;
	vector<PII> xi(n), yi(n);
	REP(i, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		xi[i] = MP(x, i);
		yi[i] = MP(y, i);
	}
	SORT(xi);
	SORT(yi);
	graph g(n);
	REP(i, n-1) {
		g[xi[i].second].PB(edge(xi[i + 1].first - xi[i].first, xi[i + 1].second));
		g[xi[i + 1].second].PB(edge(xi[i + 1].first - xi[i].first, xi[i].second));
		g[yi[i].second].PB(edge(yi[i + 1].first - yi[i].first, yi[i + 1].second));
		g[yi[i + 1].second].PB(edge(yi[i + 1].first - yi[i].first, yi[i].second));
	}
	vector<bool> visit(n, false);
	priority_queue<edge, vector<edge>, greater<edge> > q;
	REP(i, g[0].size())q.push(g[0][i]);
	visit[0] = true;
	LL ret = 0;
	while (!q.empty()) {
		auto e = q.top();
		q.pop();
		if (visit[e.second])continue;
		visit[e.second] = true;
		REP(i, g[e.second].size())if(!visit[g[e.second][i].second])q.push(g[e.second][i]);
		ret += e.first;
	}
	cout << ret << endl;
	return 0;
}