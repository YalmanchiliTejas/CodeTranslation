#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge*i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=100011,M=N<<1;
struct Edge{
	int v,w;
	Edge*nxt;
}pl[M<<1],*cur=pl,*G[N];
inline void ins(int u,int v,int w){
	*cur=(Edge){v,w,G[u]},G[u]=cur++; 
}
int n,m,S,T;
ll f[N];
int U[M],V[M],W[M];
char inq[N];
queue<int> q;
inline void spfa(){
	rep(i,1,n)f[i]=LONG_LONG_MAX>>2;
	f[S]=0;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		inq[x]=0;
		Es(x,i)if(f[i->v]>f[x]+i->w){
			f[i->v]=f[x]+i->w;
			if(!inq[i->v]){
				inq[i->v]=1;
				q.push(i->v);
			}
		}
	}
}
ll g[N];
inline void spfa2(){
	rep(i,1,n)g[i]=LONG_LONG_MAX>>2;
	g[T]=0;
	q.push(T);
	while(!q.empty()){
		int x=q.front();q.pop();
		inq[x]=0;
		Es(x,i)if(g[i->v]>g[x]+i->w){
			g[i->v]=g[x]+i->w;
			if(!inq[i->v]){
				inq[i->v]=1;
				q.push(i->v);
			}
		}
	}
}
int d[N];
ll dp1[N],dp2[N];
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	n=rd(),m=rd();
	S=rd(),T=rd();
	rep(i,1,m){
		int u=U[i]=rd(),v=V[i]=rd(),w=W[i]=rd();
		ins(u,v,w),ins(v,u,w);
	}
	spfa(),spfa2();
	{
		dp1[S]=1;
		rep(i,1,n){
			Es(i,j)if(f[j->v]==f[i]+j->w)++d[j->v];
		}
		q.push(S);
		while(!q.empty()){
			int x=q.front();q.pop();
			Es(x,i)if(f[i->v]==f[x]+i->w){
				dp1[i->v]+=dp1[x];
				dp1[i->v]%=MOD;
				if(!--d[i->v])q.push(i->v);
			}
		}
	}
	memset(d,0,sizeof d);
	{
		dp2[T]=1;
		rep(i,1,n){
			Es(i,j)if(g[j->v]==g[i]+j->w)++d[j->v];
		}
		q.push(T);
		while(!q.empty()){
			int x=q.front();q.pop();
			Es(x,i)if(g[i->v]==g[x]+i->w){
				dp2[i->v]+=dp2[x];
				dp2[i->v]%=MOD;
				if(!--d[i->v])q.push(i->v);
			}
		}
	}
	ll ans=(ll)dp1[T]*dp2[S]%MOD,tmp=f[T];
	//cout<<ans<<endl;
	rep(i,1,n){
		if(f[i]==g[i]&&f[i]+g[i]==tmp){
			//cout<<i<<" "<<f[i]<<endl;
			ans-=(ll)dp1[i]*dp1[i]%MOD*dp2[i]%MOD*dp2[i]%MOD;
		}
	}
	rep(i,1,m){
		int u=U[i],v=V[i],w=W[i];
		if(f[u]>f[v])swap(u,v);
		if(f[u]+g[v]+w==tmp&&2*f[u]<tmp&&2*f[v]>tmp){
			ans-=(ll)dp1[u]*dp2[v]%MOD*dp1[u]%MOD*dp2[v]%MOD;
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<endl;
}