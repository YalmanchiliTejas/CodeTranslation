#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
struct edge { int to, cost; };
int V;
vector<edge> G[100000];
int d[100000];
void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P>>que;
	fill(d, d + V, (int)MOD);
	d[s] = 0;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < (int)G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
int main() {
	int n, m, k; cin >> n >> m >> k; V = (1 << m);
	int light[100] = {}; int dark[16];
	rep(i, m) {
		int x; cin >> x; x--; light[x] = i + 1; dark[i] = x;
	}
	int trans[100][100];
	rep(i, n) {
		rep(j, k) {
			cin >> trans[i][j]; trans[i][j]--;
		}
	}
	rep(i, (1 << m)-1) {
		map<int, int> used;
		rep(j, k) {
			int nex = (1<<m)-1;
			rep(l, m) {
				if (i&(1 << l))continue;
				if (light[trans[dark[l]][j]] > 0) {
					if ((nex >> light[trans[dark[l]][j]] - 1) & 1) {
						nex = nex ^ (1 << (light[trans[dark[l]][j]] - 1));
					}
				}
			}
			if (used[nex] != 1&&i!=nex) {
				used[nex] = 1;
				G[i].push_back({ nex, 1 });
			}
		}
	}
	dijkstra(0);
	cout << d[(1 << m)-1] << endl;
	return 0;
}
