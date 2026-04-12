#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;

#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define gcd __gcd

#define cil(a,b) ( ((a)%(b) == 0)?((a)/(b)):((a)/(b)+1) )
#define err(x) cerr << #x << " = " << x << endl;
#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v, c) for(typeof((c).begin())v=(c).begin();v!=(c).end();++v)

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vii;

clock_t start;
void Time(bool timeIt) {
	if (!timeIt) return;
	clock_t end = clock();
	double elapsed_time = ((db)end - (db)start) / (db)CLOCKS_PER_SEC;
	printf("Time elapsed = %0.4lf\n", elapsed_time); 
}

#define LINF (long long)1e18
#define EPS 1e-9
#define INF 1000000000000007ll
#define SIZE 100010
#define MAX_A 1000010

vector<pll> adj[SIZE];
ll d[2][SIZE], num[2][SIZE];
priority_queue<pll, vector<pll>, greater<pll> > pq;
const ll mod = 1e9 + 7;

void Dijkstra(int s, int idx) {
	pq.push(MP(0, s));
	d[idx][s] = 0;
	while (!pq.empty()) {
		int v = pq.top().Y;
                ll dist = pq.top().X;
		pq.pop();
		if (d[idx][v] != dist) continue;
		for (auto u: adj[v]) {
			if (dist + u.Y < d[idx][u.X]) {
				d[idx][u.X] = dist + u.Y;
				pq.push(MP(d[idx][u.X], u.X));
			}
		}
	}
}

void dfs(int v, int p, int idx) {
	if (d[idx][v] == 0) {
		num[idx][v] = 1;
		return;
	}
	for (auto u: adj[v]) {
		if (u.X == p) continue;
		if (d[idx][u.X] + u.Y == d[idx][v]) {
			if (num[idx][u.X] == 0) dfs(u.X, v, idx); 
			num[idx][v] += num[idx][u.X];
			if (num[idx][v] >= mod) num[idx][v] -= mod;
		}
	}
}

pii edges[2 * SIZE];
ll w[2 * SIZE];

int main() {
	start = clock();

	int s, t, n, m;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0 ; i < m ; ++i) {
		int u, v, dst;
		scanf("%d %d %d", &u, &v, &dst);
		edges[i] = MP(u, v);
		w[i] = dst;
		adj[u].PB(MP(v, dst));
		adj[v].PB(MP(u, dst));
	}

	for (int i = 1 ; i <= n ; ++i) {
		d[0][i] = d[1][i] = INF;
		num[0][i] = num[1][i] = 0;
	}
	Dijkstra(s, 0);
	Dijkstra(t, 1);

	dfs(s, s, 1);
	dfs(t, t, 0);

	assert(num[0][t] == num[1][s]);
	ll tot = (num[0][t] * num[1][s]) % mod;
	for (int i = 1 ; i <= n ; ++i) {
		if (d[0][i] == d[1][i]) {
			ll r = (num[0][i] * num[1][i]) % mod;
			tot -= (r * r) % mod;
			if (tot < 0) tot += mod;
		}
	}
	for (int i = 0 ; i < m ; ++i) {
		int u = edges[i].X, v = edges[i].Y;
		if (d[0][u] + w[i] == d[0][v]) {
			if (abs(d[0][u] - d[1][v]) < w[i]) {
				ll r = (num[0][u] * num[1][v]) % mod;
				tot -= (r * r) % mod;
				if (tot < 0) tot += mod;
			}
		}
		else if (d[1][u] + w[i] == d[1][v]) {
			if (abs(d[1][u] - d[0][v]) < w[i]) {
				ll r = (num[1][u] * num[0][v]) % mod;
				tot -= (r * r) % mod;
				if (tot < 0) tot += mod;
			}
		}
	}
	printf("%lld\n", tot);

	Time(0);
	return 0;
}
