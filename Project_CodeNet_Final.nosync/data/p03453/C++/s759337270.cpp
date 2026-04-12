#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
void go(int &a){
	a = (a % mod + mod) % mod;
}

int ver[100010], nxt[400010], to[400010], d[400010], tot;
void addedge(int from, int t, int dist){
	nxt[++tot] = ver[from];
	to[tot] = t;
	d[tot] = dist;
	ver[from] = tot;
}

struct Inf{
	int vertex;long long dist;
	Inf(int v=0,long long d=0):vertex(v), dist(d){}
};
bool operator < (const Inf& a , const Inf& b){
	return a.dist > b.dist;
}
priority_queue<Inf> heap;

int n, m;

bool flag[100010];long long d1[100010], d2[100010];
int g1[100010], g2[100010];

void dijkstra(int source, long long dist[], int g[]){
	for(int i = 1 ; i <= n ; i++)
		flag[i] = false, dist[i] = 1e18;
	heap.push(Inf(source, 0));
	dist[source] = 0;
	g[source] = 1;
	while(!heap.empty()){
		auto now = heap.top();heap.pop();
		if(flag[now.vertex])continue;
		flag[now.vertex] = true;
		for(int i = ver[now.vertex] ; i ; i = nxt[i]){
			if(dist[now.vertex] + d[i] < dist[to[i]]){
				dist[to[i]] = dist[now.vertex] + d[i];
				g[to[i]] = g[now.vertex];
				heap.push(Inf(to[i], dist[to[i]]));
			}
			else if(dist[now.vertex] + d[i] == dist[to[i]]){
				g[to[i]] += g[now.vertex];
				go(g[to[i]]);
			}
		}
	}
}


int s, t;



int main(){
	scanf("%d%d" , &n , &m);
	scanf("%d%d" , &s , &t);

	for(int i = 1 ; i <= m ; i++){
		int u, v, d;
		scanf("%d%d%d" , &u , &v , &d);
		addedge(u, v, d);
		addedge(v, u, d);
	}

	dijkstra(s, d1, g1);
	dijkstra(t, d2, g2);

	long long shortest_path = d1[t];

	int ans = (long long)g1[t] * g2[s] % mod;

	for(int i = 1 ; i <= n ; i++){
		// meet at the node
		if(d1[i] != d2[i])continue;

		// printf("meet at node %d\n", i);

		int n1 = (long long)g1[i] * g2[i] % mod;

		int now = (long long)n1 * n1 % mod;
		ans -= now;
		go(ans);
	}

	for(int i = 1 ; i <= n ; i++){
		for(int _ = ver[i] ; _ ; _ = nxt[_]){
			if(d1[i] + d[_] + d2[to[_]] == shortest_path){

				if(d1[i] + d[_] > d2[to[_]] && d2[to[_]] + d[_] > d1[i]){

					// printf("meet at <%d,%d>\n", i, to[_]);

					int n1 = (long long)g1[i] * g2[to[_]] % mod;

					ans -= (long long)n1 * n1 % mod;
					go(ans);
				}
			}
		}
	}

	printf("%d\n" , ans);

	return 0;
}