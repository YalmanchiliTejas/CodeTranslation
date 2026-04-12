# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <math.h>
# include <algorithm>
using namespace std;
# define lowbit(x) ((x)&(-x))
# define pi acos(-1.0)
# define MAXN 100005
# define eps 1e-6
# define MAXM 10000005
# define MOD 1000000007
# define INF 1000000000
# define MIN(a,b) (a)>(b)?(b):(a)
# define MAX(a,b) (a)<(b)?(b):(a)
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(int i=a; i<=n; ++i)
# define FO(i,a,n) for(int i=a; i<n; ++i)
# define bug puts("H");
typedef long long LL;
typedef unsigned long long ULL;
int _MAX(int a, int b){return a>b?a:b;}
int _MIN(int a, int b){return a>b?b:a;}

struct Edge{int p, next, w, v;}edge[MAXM];
int head[MAXN], dis[MAXN], vis[MAXN], pre[MAXN], pos[MAXN], cnt, s, t;

inline void init(){memset(head,0,sizeof(head)); cnt=2;}
inline void add_edge(int u, int v, int w, int val)
{
    edge[cnt].p=v; edge[cnt].w=w; edge[cnt].v=val; edge[cnt].next=head[u]; head[u]=cnt++;
	edge[cnt].p=u; edge[cnt].w=0; edge[cnt].v=-val; edge[cnt].next=head[v]; head[v]=cnt++;
}
bool spfa()
{
	int v, i;
	for (i=s; i<=t; ++i) dis[i]=INF, pre[i]=-1, vis[i]=0;
	dis[s]=0; vis[s]=1; pre[s]=s;
	queue<int>Q; Q.push(s);
	while (!Q.empty()) {
		v=Q.front(); Q.pop(); vis[v]=0;
		for (i=head[v]; i; i=edge[i].next)
			if (edge[i].w>0 && dis[v]+edge[i].v<dis[edge[i].p]) {
				dis[edge[i].p]=dis[v]+edge[i].v; pre[edge[i].p]=v; pos[edge[i].p]=i;
				if (vis[edge[i].p]==0) vis[edge[i].p]=1, Q.push(edge[i].p);
			}
	}
	return pre[t]!=-1&&dis[t]<INF;
}
int costflow()
{
	int cf=0, nf=0, min, i;
	while (spfa()) {
		min = INF;
		for (i=t; i!=s; i=pre[i]) min=MIN(min,edge[pos[i]].w);
		nf+=min; cf+=min*dis[t];
		for (i=t; i!=s; i=pre[i]) edge[pos[i]].w-=min, edge[pos[i]^1].w+=min;
	}
	return cf;
}
int main (void)
{
	int x, i, j, sum, n, m;
    scanf("%d%d",&n,&m);
    init(); sum=0;
    for (i=0; i<n; ++i) for (j=0; j<m; ++j) {
        scanf("%d",&x);
        if ((i==0&&j==0)||(i==n-1&&j==m-1)) sum+=x;
        add_edge(i*m+j,i*m+j+n*m,(i==0&&j==0)||(i==n-1&&j==m-1)?2:1,-x);
        if (i+1<n) add_edge(i*m+j+n*m,(i+1)*m+j,1,0);
        if (j+1<m) add_edge(i*m+j+n*m,i*m+j+1,1,0);
    }
    s=0; t=2*n*m-1;
    printf("%d\n",-costflow()-sum);
	return 0;
}

