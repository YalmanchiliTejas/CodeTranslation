#include<bits/stdc++.h>
#define MAXN 100005
#define LL long long
#define P int(1e9+7)
using namespace std;

int N,M,S,T;
struct edge{
	int v,w;
	edge(int v=0, int w=0):v(v), w(w){}
};

vector<edge> adj[MAXN];

struct Node{
	int id;
	LL v;
	Node(int id=0, LL v=0):id(id), v(v){}
	
	bool operator < (const Node& n1) const{
		return v > n1.v;
	}
};

bool vis[MAXN];
LL d1[MAXN], d2[MAXN], g1[MAXN], g2[MAXN];
void dijkstra1(){
	memset(d1, 1, sizeof(d1));
	d1[S] = 0;
	priority_queue<Node> q;
	q.push(Node(S,0));
	
	int u,v,w;
	while(!q.empty()){
		u = q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		
		for(int k=0;k<adj[u].size();k++){
			v = adj[u][k].v;
			w = adj[u][k].w;
			if(d1[u] + w < d1[v]){
				g1[v] = g1[u];
				d1[v] = d1[u] + w;
				q.push(Node(v, d1[v]));
			}
			else if(d1[u] + w == d1[v]){
				g1[v] = (g1[v] + g1[u]) % P;
			}
		}
	}
}

void dijkstra2(){
	memset(d2, 1, sizeof(d2));
	d2[T] = 0;
	priority_queue<Node> q;
	q.push(Node(T,0));
	
	int u,v,w;
	while(!q.empty()){
		u = q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		
		for(int k=0;k<adj[u].size();k++){
			v = adj[u][k].v;
			w = adj[u][k].w;
			if(d2[u] + w < d2[v]){
				g2[v] = g2[u];
				d2[v] = d2[u] + w;
				q.push(Node(v, d2[v]));
			}
			else if(d2[u] + w == d2[v]){
				g2[v] = (g2[v] + g2[u]) % P;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	
	cin>>N>>M>>S>>T;
	int u,v,w;
	for(int i=1;i<=M;i++){
		cin>>u>>v>>w;
		adj[u].push_back(edge(v,w));
		adj[v].push_back(edge(u,w));
	}
	
	g1[S] = g2[T] = 1;
	dijkstra1();
	memset(vis, 0, sizeof(vis));
	dijkstra2();
	
	LL ans = g1[T]*g2[S]%P;
	LL D = d1[T];

	for(u=1;u<=N;u++){
		if(d1[u] + d2[u]==D && d1[u]==d2[u]){
			ans = (ans - g1[u]*g2[u]%P*g1[u]%P*g2[u]%P + P) % P;
		}
		
		for(int k=0;k<adj[u].size();k++){
			v = adj[u][k].v;
			w = adj[u][k].w;
			if(d1[u] + w + d2[v] == D){
				if(d1[u] < d2[u] && d2[v] < d1[v]){
					ans = (ans - g1[u]*g2[v]%P*g1[u]%P*g2[v]%P + P) % P;
				}
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}