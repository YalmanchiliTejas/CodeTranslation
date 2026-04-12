#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int const N = 100000, M = 200000, md = 1e9 + 7;
pair<int, int> in[M];
vector<pair<int, int> > g[N + 1];
int n, m, st, ed, w[M], dp[2][N + 1];
bool good[M], visfg[N + 1];
ll vis[N + 1];

inline void ad(int &x, int y) { if ((x += y) >= md)x -= md; }
inline void sb(int &x, int y) { if ((x -= y) <  0 )x += md; }

int I;
void pl(int st, int ed){
	priority_queue<pair<ll, pair<int, int> > > q;
	q.push(make_pair(0ll, make_pair(st, 0)));
	dp[I][0] = 1;
	while (!q.empty()){
		ll d = -q.top().first;
		int v = q.top().second.first, u = q.top().second.second;
		q.pop();
		if (vis[v] < d)continue;
		if (vis[v] == d) { ad(dp[I][v], dp[I][u]); continue; }
		vis[v] = d;
		dp[I][v] = dp[I][u];
		f(i, 0, g[v].size()){
			u = g[v][i].first;
			int id = g[v][i].second;
			ll nd = d + w[id];
			if (nd <= vis[u]){
				q.push(make_pair(-nd, make_pair(u, v)));
				in[id] = make_pair(v, u);
			}
		}
	}
}

void fg(int v = ed){
	if (visfg[v])return;
	visfg[v] = true;
	f(i, 0, g[v].size()){
		int u = g[v][i].first, id = g[v][i].second;
		if (vis[u] + w[id] != vis[v])continue;
		good[id] = true;
		fg(u);
	}
}

int main(){
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	f(i, 0, m){
		int a, b;
		scanf("%d%d%d", &a, &b, w + i);
		w[i] <<= 1;
		g[a].push_back(make_pair(b, i));
		g[b].push_back(make_pair(a, i));
	}
	f(i, 1, n + 1)vis[i] = 1e18;
	I = 1;
	pl(ed, st);
	f(i, 1, n + 1)vis[i] = 1e18;
	I = 0;
	pl(st, ed);
	fg();
	int an = (ll)dp[0][ed] * dp[0][ed] % md;
	set<int> bad;
	ll mdd = vis[ed] >> 1;
	f(i, 0, m)if (good[i]){
		if (vis[in[i].first] == mdd)bad.insert(in[i].first);
		else if (vis[in[i].second] == mdd)bad.insert(in[i].second);
		else if (mdd > vis[in[i].first] && mdd < vis[in[i].second])sb(an, (ll)dp[0][in[i].first] * dp[1][in[i].second] % md * dp[0][in[i].first] % md * dp[1][in[i].second] % md);
	}
	for (set<int>::iterator it = bad.begin(); it != bad.end(); ++it)sb(an, (ll)dp[0][*it] * dp[1][*it] % md * dp[0][*it] % md * dp[1][*it] % md);
	printf("%d\n", an);
}