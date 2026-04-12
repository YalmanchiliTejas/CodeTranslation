#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = (1LL << 31) - 1;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100 * 3

int n;
vector<P> px, py;

struct edge { int to; int cost; };
vector<edge> G[100100];
int mincost[100100];
int res = 0;
bool used[100100];

int prim() {
	for (int i = 0; i < 100100; i++) {
		mincost[i] = INF;
		used[i] = false;
	}
	mincost[0] = 0;

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P(0, 0));

	while (que.size()) {
		P p = que.top(); que.pop();
		int v = p.second;

		if (used[v])continue;

		used[v] = 1;

		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (used[e.to])continue;
			if (mincost[e.to] > e.cost) {
				mincost[e.to] = e.cost;
				que.push(P(e.cost, e.to));
			}
		}
	}

	REP(i, n) {
		//cout << mincost[i] << endl;
		res += mincost[i];
	}
	return res;
}

int main() {
	cin >> n;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		px.push_back({ a,i });
		py.push_back({ b,i });
	}
	sort(ALL(px));
	sort(ALL(py));
	REP(i, n - 1) {
		int a = px[i].second, b = px[i + 1].second, c = px[i + 1].first - px[i].first;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
		a = py[i].second, b = py[i + 1].second, c = py[i + 1].first - py[i].first;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	cout << prim() << endl;
}