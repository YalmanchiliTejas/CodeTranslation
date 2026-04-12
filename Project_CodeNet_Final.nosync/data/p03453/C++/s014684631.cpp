#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;


using f64 = double;
using i64 = long long;
using pii = pair<i64, i64>;

const i64 MOD = 1e9 + 7;
const int N = 1e5 + 5;


vector<pii> g[N], dag[N];
i64 dist[N], in[N], ut[N];
int deg_in[N], deg_ut[N];
bool f[N];

i64 ant;
int n, m, s, t;


static void fix(i64 &x) {
	x = x >= MOD ? x - MOD : x; }

static void dijkstra(int s) {
	priority_queue<pii> pq;
	i64 u, d;

	memset(dist, 0x3f, sizeof dist);
	pq.emplace(0, s);
	dist[s] = 0;

	while (!pq.empty()) {
		pii top = pq.top(); pq.pop();
		tie(d, u) = tie(top.x, top.y);

		if (dist[u] == -d)
		for (auto v: g[u]) if (dist[v.x] > -(d - v.y)) {
			dist[v.x] = -(d - v.y);
			pq.emplace(-dist[v.x], v.x); } } }

static void make_dag(int u) {
	f[u] = true;
	for (auto v: g[u]) if (dist[v.x] == dist[u] - v.y && dist[v.x] < dist[u]) {
		dag[v.x].emplace_back(u, v.y); deg_ut[v.x]+= 1;
		dag[u].emplace_back(v.x, -v.y); deg_in[u]+= 1;
		if (!f[v.x])
			make_dag(v.x); } }

static void dp_in(int u) {
	for (auto v: dag[u]) if (v.y > 0) {
		deg_in[v.x]-= 1;
		in[v.x] = (in[v.x] + in[u]) % MOD;
		if (!deg_in[v.x])
			dp_in(v.x); } }

static void dp_ut(int u) {
	for (auto v: dag[u]) if (v.y < 0) {
		deg_ut[v.x]-= 1;
		ut[v.x] = (ut[v.x] + ut[u]) % MOD;
		if (!deg_ut[v.x])
			dp_ut(v.x); } }

static void magic() {
	i64 cnt, len = dist[t];

	for (int u = 1; u <= n; ++u) if (dist[u] == len - dist[u]) { // for nodes
		cnt = (in[u] * ut[u]) % MOD;
		ant+= cnt * (in[t] - cnt) % MOD; }

	for (int u = 1; u <= n; ++u) // for edges
	for (auto v: dag[u]) if (v.y > 0 && abs((len - dist[v.x]) - dist[u]) < v.y) {
		cnt = (in[u] * ut[v.x]) % MOD;
		ant+= cnt * (in[t] - cnt) % MOD; }


	ant = ((ant % MOD) + MOD) % MOD; }


int main() {
#ifdef HOME
	freopen("arc.in", "r", stdin);
	freopen("arc.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	

	cin >> n >> m >> s >> t;
	for (int u, v, c, i = 0; i < m; ++i) {
		cin >> u >> v >> c;
		g[u].emplace_back(v, c);
		g[v].emplace_back(u, c); }

	dijkstra(s);
	make_dag(t);

	in[s] = 1, dp_in(s);
	ut[t] = 1, dp_ut(t);

	magic();

	cout << ant << endl;

	return 0; }
