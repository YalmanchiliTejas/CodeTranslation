#include<bits/stdc++.h>
#define ll long long
#define PI pair<ll,int>
#define mo 1000000007
#define N 100005
using namespace std;
ll ds[N],dt[N],ways[N],wayt[N];
struct edge {
	int to,next,v;
} e[N*4];
int head[N],vis[N];
int n,m,s,t,tot,ans;
priority_queue<PI > q;
inline char gc() {
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read() {
	int x = 0;
	char ch = gc();
	bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a) {
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a) {
	if(a<0) {
		a=-a;
		putchar('-');
	}
	write(a);
	puts("");
}
void add(int x,int y,int v) {
	e[++tot]=(edge){
		y,head[x],v
	};
	head[x]=tot;
}
void dijkstra(int S,ll *dis,ll *way) {
	for(int i=1; i<=n; i++){dis[i]=1e18; vis[i]=way[i]=0;}
	dis[S]=0;
	way[S]=1;
	while(!q.empty())q.pop();
	q.push(PI(0,S));
	while (!q.empty()) {
		int x=q.top().second;
		q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int i=head[x]; i; i=e[i].next) {
			ll tmp=dis[x]+e[i].v;
			if (dis[e[i].to]>tmp) {
				dis[e[i].to]=tmp;
				way[e[i].to]=0;
				q.push(PI(-tmp,e[i].to));
			}
			if (dis[e[i].to]==tmp)way[e[i].to]=(way[e[i].to]+way[x])%mo;
		}
	}
}
int main() {
	n=read();
	m=read();
	s=read();
	t=read();
	for (int i=1; i<=m; i++) {
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,z);
	}
	dijkstra(s,ds,ways);
	ans=(long long)ways[t]*ways[t]%mo;
	dijkstra(t,dt,wayt);
	for (int i=1; i<=n; i++)
		if (ds[i]*2==ds[t]&&ds[i]+dt[i]==ds[t])
			ans=(ans+mo-(long long)ways[i]*ways[i]%mo*wayt[i]%mo*wayt[i]%mo)%mo;
	for (int x=1; x<=n; x++)
		for (int i=head[x]; i; i=e[i].next)
			if (ds[x]+e[i].v+dt[e[i].to]==ds[t])
				if (ds[x]*2<ds[t]&&dt[e[i].to]*2<ds[t])
					ans=(ans+mo-(long long)ways[x]*wayt[e[i].to]%mo*ways[x]%mo*wayt[e[i].to]%mo)%mo;
	writeln(ans);
}