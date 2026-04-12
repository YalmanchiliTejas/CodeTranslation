#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 100005;
const int mod = 1000000007;
const ll Inf = 4000000000000000000ll;

int n, m;
int S, T;
vector <ii> neigh[Maxn];
ll distS[Maxn], distT[Maxn];
int waysS[Maxn], waysT[Maxn];

void Dist(int v, ll dist[], int ways[])
{
	fill(dist, dist + Maxn, Inf); dist[v] = 0;
	ways[v] = 1;
	priority_queue <lli> Q; Q.push(lli(-dist[v], v));
	while (!Q.empty()) {
		int v = Q.top().second;
		ll d = -Q.top().first; Q.pop();
		if (d != dist[v]) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			ii u = neigh[v][i];
			if (d + u.second == dist[u.first]) ways[u.first] = (ways[u.first] + ways[v]) % mod;
			else if (d + u.second < dist[u.first]) {
				ways[u.first] = ways[v];
				dist[u.first] = d + u.second;
				Q.push(lli(-dist[u.first], u.first));
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d", &S, &T);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, c));
	}
	Dist(S, distS, waysS);
	Dist(T, distT, waysT);
	int ways = ll(waysS[T]) * ll(waysT[S]) % mod;
	for (int i = 1; i <= n; i++) if (distS[i] + distT[i] == distS[T] && distS[i] == distT[i]) {
		int cur = ll(waysS[i]) * waysT[i] % mod * waysT[i] % mod * waysS[i] % mod;
		ways = (ways - cur + mod) % mod;
	}
	for (int v = 1; v <= n; v++)
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j].first;
			int d = neigh[v][j].second;
			if (distS[v] + d + distT[u] == distS[T]) {
				ll x2 = distT[u] + d - distS[v];
				if (0 < x2 && x2 < 2 * d) {
					int cur = ll(waysS[v]) * waysT[u] % mod * waysT[u] % mod * waysS[v] % mod;
					ways = (ways - cur + mod) % mod;
				}
			}
		}
	printf("%d\n", ways);
	return 0;
}