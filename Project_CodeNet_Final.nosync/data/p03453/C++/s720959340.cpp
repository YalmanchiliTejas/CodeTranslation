#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long mod = 1e9 + 7;

int done[N];
vector < pair < int, int > > g[N];

bool minimize(long long &u, long long v){
	if(u > v){
		u = v;
		return true;
	}
	return false;
}

int n, m, s, t;
long long a[2][N];
long long c[2][N];

void dijkstra(int start, long long *path, long long *cnt){
	fill(done + 1, done + n + 1, 0);
	fill(cnt + 1, cnt + n + 1, 0);
	fill(path + 1, path + n + 1, 1e18);

	cnt[start] = 1;
	path[start] = 0;

	set < pair < long long, int > > que;
	que.insert(make_pair(0, start));

	while(!que.empty()){
		int v = que.begin() -> second;
		que.erase(*que.begin());

		if(done[v]) continue;
		done[v] = 1;


		for(auto p : g[v]){
			int u = p.first, w = p.second;
			if(minimize(path[u], path[v] + w)){
				cnt[u] = cnt[v];
				que.emplace(path[u], u);

			}
			else if(path[u] == path[v] + w) {
				cnt[u] += cnt[v];
				cnt[u] %= mod;
			}
		}
	}
}

struct edge{
	int u;
	int v;
	int w;

	void read(){
		scanf("%d%d%d", &u, &v, &w);
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
}lst[N + N];


int main(){

	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 1; i <= m; ++i){
		lst[i].read();
	}

	dijkstra(s, a[0], c[0]);
	dijkstra(t, a[1], c[1]);


	long long tot = c[0][t] * c[1][s] % mod;


	for(int i = 1; i <= n; ++i){
		if(a[0][i] + a[1][i] != a[0][t]) continue;
		if(a[0][i] == a[1][i]){
			long long calc = c[0][i] * c[1][i] % mod;
			tot -= calc * calc;
			tot += mod * mod;
			tot %= mod;
		}
	}


	for(int u = 1; u <= n; ++u){
		for(auto e : g[u]){
			int v = e.first;
			int w = e.second;

			if(a[0][u] + a[1][v] + w != a[0][t]) continue;
			if(a[0][u] + w <= a[1][v] || a[1][v] + w <= a[0][u]) continue;


			long long calc = c[0][u] * c[1][v] % mod;
			tot -= calc * calc - mod * mod;
			tot %= mod;
		}
	}

	cout << tot;
	return 0;
}