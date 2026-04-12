#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(int i=(int)(st),i##end=(int)(ed);i<=i##end;++i)
#define DREP(i,st,ed) for(int i=(int)(st),i##end=(int)(ed);i>=i##end;--i)
template<typename T>bool chkmin(T &x,const T &y){return x>y?x=y,1:0;}
template<typename T>bool chkmax(T &x,const T &y){return x<y?x=y,1:0;}
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
template<typename T>T read(){
	T x=0,f=1;
	char c=getchar();
	while((c<'0')||(c>'9')){if(c=='-')f=-1;c=getchar();}
	while((c>='0')&&(c<='9'))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
#define read() read<int>()
template<typename T>void write(T x,char c){
	static char t[25];
	static int tlen;
	t[tlen=1]=c;
	if(x<0)putchar('-'),x=-x;
	do t[++tlen]=(x%10)^48;
	while(x/=10);
	while(tlen)putchar(t[tlen--]);
}
#define pb push_back
typedef long long ll;
typedef double lf;
const int maxn=100005,mod=1e9+7;
int n,m,dp[2][maxn];
ll dis[2][maxn];
bool mark[maxn];
int S,T;
struct edge{int v,w;};
struct data{
	int id;
	ll dis;
	bool operator < (const data &A) const {
		return dis>A.dis;
	}
};
vector<edge>E[maxn];
void add(int &x,const int &y){
	x+=y;
	if(x>=mod)x-=mod;
	if(x<0)x+=mod;
}
void solve(int S,ll *dis,int *dp){
	static priority_queue<data>Q;
	static bool vis[maxn];
	static int indeg[maxn];
	REP(i,1,n)dis[i]=1e18,vis[i]=0,indeg[i]=0;
	Q.push((data){S,dis[S]=0});
	while(!Q.empty()){
		int u=Q.top().id;Q.pop();
		if(vis[u])continue;
		vis[u]=1;
		REP(i,0,E[u].size()-1){
			int v=E[u][i].v;
			if(chkmin(dis[v],dis[u]+E[u][i].w))Q.push((data){v,dis[v]});
		}
	}
	REP(i,1,n)
		REP(j,0,E[i].size()-1)
			if(dis[E[i][j].v]==dis[i]+E[i][j].w)++indeg[E[i][j].v];
	static queue<int>q;
	q.push(S),dp[S]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		REP(i,0,E[u].size()-1){
			int v=E[u][i].v;
			if(dis[v]==dis[u]+E[u][i].w){
				add(dp[v],dp[u]);
				if(--indeg[v]==0)q.push(v);
			}
		}
	}
/*
	REP(i,1,n)write(dis[i],i==n?'\n':' ');
	REP(i,1,n)write(dp[i],i==n?'\n':' ');
*/
}
int main(){
	n=read(),m=read(),S=read(),T=read();
	REP(i,1,m){
		int u=read(),v=read(),w=read();
		E[u].pb((edge){v,w}),E[v].pb((edge){u,w});
	}
	solve(S,dis[0],dp[0]);
	solve(T,dis[1],dp[1]);
	REP(i,1,n)mark[i]=(dis[0][T]==dis[0][i]+dis[1][i]);
	int ans=1ll*dp[0][T]*dp[0][T]%mod;
	REP(i,1,n){
		if(!mark[i])continue;
		if(dis[0][i]==dis[1][i])
			add(ans,-1ll*dp[0][i]*dp[1][i]%mod*dp[0][i]%mod*dp[1][i]%mod);
		REP(j,0,E[i].size()-1){
			int v=E[i][j].v;
			if(!mark[v])continue;
			if(dis[0][v]==dis[0][i]+E[i][j].w)
				if((dis[0][v]>dis[1][v])&&(dis[1][i]>dis[0][i]))
					add(ans,-1ll*dp[0][i]*dp[1][v]%mod*dp[0][i]%mod*dp[1][v]%mod);
		}
	}
	write(ans,'\n');
	return 0;
}