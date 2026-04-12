
#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
const int inf = 1000000001;
const ll INF = 2e18 * 2;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int N = 100010;

int n;
vector< vector< pll > > adj(N, vector< pll >());


void dijkstra(int s, vector<pll> &d) {
	priority_queue< pll, vector< pll >, greater< pll > > pq;
	int i;
	vi color(n, WHITE);

	d[s].first = 0;
	d[s].second = 1;
	pq.push(make_pair(0, s));
	color[s] = GRAY;
	/*
	for (i = 0; i < n; i++) {
		printf("(%lld, %lld) ", d[i].first, d[i].second);
	}
	cout << endl;
	//*/
	while (!pq.empty()) {
		pll f = pq.top();
		pq.pop();
		ll u = f.second;
		color[u] = BLACK;
		if (d[u].first<f.first) {
			continue;
		}
		for (i = 0; i < adj[u].size(); i++) {
			ll v = adj[u][i].second;
			if (color[v] == BLACK) {
				continue;
			}
			if (d[v].first>d[u].first + adj[u][i].first) {
				d[v].first = d[u].first + adj[u][i].first;
				pq.push(make_pair(d[v].first, v));
				color[v] = GRAY;
				d[v].second = d[u].second;
			}
			else if (d[v].first == d[u].first + adj[u][i].first) {
				d[v].second += d[u].second;
				d[v].second %= MOD;
			}
		}
	}
}

int main() {
	int m, i, j;
	cin >> n >> m;
	int s, t2;
	cin >> s >> t2;
	s--; t2--;
	vi u(m), v(m), d(m);
	for (i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> d[i];
		u[i]--; v[i]--;
		adj[u[i]].push_back(pll(d[i], v[i]));
		adj[v[i]].push_back(pll(d[i], u[i]));
	}
	vector<pll> d1(n, pll(INF, 0)), d2(n, pll(INF, 0));
	dijkstra(s, d1);
	dijkstra(t2, d2);
	/*
	for (i = 0; i < n; i++) {
		printf("(%lld, %lld) ", d1[i].first, d1[i].second);
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		printf("(%lld, %lld) ", d2[i].first, d2[i].second);
	}
	cout << endl;
	//*/
	ll t = d1[t2].first;
	vi kind(n);
	if (t % 2) {
		for (i = 0; i < n; i++) {
			if (d1[i].first <= t / 2) {
				kind[i] = 1;
			}
			if (d2[i].first <= t / 2) {
				kind[i] = 2;
			}
		}
		ll ans = 0;
		for (i = 0; i < m; i++) {
			if (kind[u[i]] == 1 && kind[v[i]] == 2) {
				if (d1[u[i]].first + d[i] + d2[v[i]].first == t) {
					ans = (ans + d1[u[i]].second * d2[v[i]].second % MOD * d1[u[i]].second % MOD * d2[v[i]].second % MOD) % MOD;
				}
			}
			else if (kind[u[i]] == 2 && kind[v[i]] == 1) {
				if (d2[u[i]].first + d[i] + d1[v[i]].first == t) {
					ans = (ans + d2[u[i]].second * d1[v[i]].second % MOD * d2[u[i]].second % MOD * d1[v[i]].second % MOD) % MOD;
				}
			}
		}
		ans = (d1[t2].second * d2[s].second % MOD - ans + MOD) % MOD;
		cout << ans << endl;
	}
	else {
		ll ans = 0;
		for (i = 0; i < n; i++) {
			if (d1[i].first < t / 2) {
				kind[i] = 1;
			}
			if (d2[i].first < t / 2) {
				kind[i] = 2;
			}
			if (d1[i].first == t / 2 && d2[i].first == t / 2) {
				kind[i] = 3;
				ans = (ans + d1[i].second * d2[i].second % MOD * d1[i].second % MOD * d2[i].second % MOD) % MOD;
			}
		}
		for (i = 0; i < m; i++) {
			if (kind[u[i]] == 1 && kind[v[i]] == 2) {
				if (d1[u[i]].first + d[i] + d2[v[i]].first == t) {
					ans = (ans + d1[u[i]].second * d2[v[i]].second % MOD * d1[u[i]].second % MOD * d2[v[i]].second % MOD) % MOD;
				}
			}
			else if (kind[u[i]] == 2 && kind[v[i]] == 1) {
				if (d2[u[i]].first + d[i] + d1[v[i]].first == t) {
					ans = (ans + d2[u[i]].second * d1[v[i]].second % MOD * d2[u[i]].second % MOD * d1[v[i]].second % MOD) % MOD;
				}
			}
		}
		ans = (d1[t2].second * d2[s].second % MOD - ans + MOD) % MOD;
		cout << ans << endl;
	}
}

