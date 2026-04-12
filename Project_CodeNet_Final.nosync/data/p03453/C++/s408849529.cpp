#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define pdi pair<db,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define eps 1e-8
#define mo 974711
#define MAXN 200005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
    while(c < '0' || c > '9') {
	if(c == '-') f = -1;
	c = getchar();
    }
    while(c >= '0' && c <= '9') {
	res = res * 10 + c - '0';
	c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
	out(x / 10);
    }
    putchar('0' + x % 10);
}
const int MOD = 1000000007;
int N,M,S,T;
struct node {
    int to,next;
    int64 val;
}E[MAXN * 2];
int head[MAXN],sumE,id[MAXN],on,dp[2][MAXN],ans;
int64 dis[2][MAXN];
bool vis[MAXN];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void add(int u,int v,int64 c) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    E[sumE].val = c;
    head[u] = sumE;
}
priority_queue<pair<int64,int> > Q;
void dijkstra(int u,int64 *d) {
    for(int i = 1 ; i <= N ; ++i) d[i] = 1e18;
    memset(vis,0,sizeof(vis));
    d[u] = 0;
    Q.push(mp(-d[u],u));
    while(!Q.empty()) {
	pair<int64,int> now = Q.top();Q.pop();
	if(vis[now.se]) continue;
	int u = now.se;
	vis[u] = 1;
	for(int i = head[u] ; i ; i = E[i].next) {
	    int v = E[i].to;
	    if(!vis[v] && d[v] > d[u] + E[i].val) {
		d[v] = d[u] + E[i].val;
		Q.push(mp(-d[v],v));
	    }
	}
    }
}
bool cmp(int a,int b) {
    return dis[on][a] < dis[on][b];
}
void Process() {
    for(int i = 1 ; i <= N ; ++i) id[i] = i;
    sort(id + 1,id + N + 1,cmp);
    dp[on][id[1]] = 1;
    for(int i = 1 ; i <= N ; ++i) {
	int u = id[i];
	for(int j = head[u] ; j ; j = E[j].next) {
	    int v = E[j].to;
	    if(dis[on][v] - dis[on][u] == E[j].val) {
		dp[on][v] = inc(dp[on][v],dp[on][u]);
	    }
	}
    }
}
void Solve() {
    read(N);read(M);
    read(S);read(T);
    int u,v;int64 d;
    for(int i = 1 ; i <= M ; ++i) {
	read(u);read(v);read(d);
	add(u,v,d);add(v,u,d);
    }
    dijkstra(S,dis[0]);
    dijkstra(T,dis[1]);
    on = 0;Process();
    on = 1;Process();
    ans = mul(dp[0][T],dp[0][T]);
    for(int u = 1 ; u <= N ; ++u) {
	for(int i = head[u] ; i ; i = E[i].next) {
	    int v = E[i].to;
	    if(dis[0][u] + dis[1][v] + E[i].val == dis[0][T]) {
		if(dis[1][v] + E[i].val - dis[0][u] > 0 && dis[1][v] + E[i].val - dis[0][u] < 2 * E[i].val) {
		    ans = inc(ans,MOD - mul(mul(dp[0][u],dp[1][v]),mul(dp[1][v],dp[0][u])));
		}
	    }
	}
	if(dis[0][u] == dis[1][u]) {
	    ans = inc(ans,MOD - mul(mul(dp[0][u],dp[1][u]),mul(dp[0][u],dp[1][u])));
	}
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
