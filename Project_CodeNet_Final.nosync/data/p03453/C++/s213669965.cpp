#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define all(a) a.begin(),a.end()
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
#define pii pair<int,int> 
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define SZ(x) ((int)x.size())
using namespace std;
template<class T> inline void gmin(T &x,const T &y){x=x>y?y:x;}
template<class T> inline void gmax(T &x,const T &y){x=x<y?y:x;}
template<class T> inline bool Gmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T> inline bool Gmax(T &x,const T &y){return x<y?x=y,1:0;}
const int BufferSize=1<<16;
char buffer[BufferSize],*Bufferhead,*Buffertail;
bool Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T>inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){rev|=c=='-';c=Getchar();if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	if(c=='.'){
		c=Getchar();double t=0.1;
		while(c>='0'&&c<='9') x=x+(c-'0')*t,c=Getchar(),t=t/10;
	}
	x=rev?-x:x;
	return 1;
}
template<class T1,class T2> inline bool read(T1 &x,T2 &y){return read(x)&read(y);}
template<class T1,class T2,class T3> inline bool read(T1 &x,T2 &y,T3 &z){return read(x)&read(y)&read(z);}
template<class T1,class T2,class T3,class T4> inline bool read(T1 &x,T2 &y,T3 &z,T4 &w){return read(x)&read(y)&read(z)&read(w);}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c='\n'){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
//--------------------------------head---------------------------------------------

const ll inf=1ll<<60;
const int N=200005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int u,v,w;}p[N],res[N];
int n,m,S,T,tot,dp1[N],dp2[N];
ll ds[N],dt[N];
bool vis[N];
vector<pii> g[N],f[N];

inline void dij(int S,ll *d){
	heap(pair<ll,int>) q;
	for(int i=1;i<=n;i++) d[i]=1ll<<60;
	d[S]=0;q.push(mp(0,S));
	while(!q.empty()){
		int x=q.top().SS;q.pop();
		for(auto i:g[x]){
			int y=i.FF,w=i.SS;
			if(d[y]>d[x]+w){
				d[y]=d[x]+w;
				q.push(mp(d[y],y));
			}
		}
	}
}
inline void dfs(int x,int T,int *dp){
	if(vis[x]) return;
	vis[x]=1;dp[x]=0;
	if(x==T){dp[x]=1;return;}
	for(auto i:g[x]){
		int y=i.FF;
		dfs(y,T,dp);
		ch(dp[x],dp[y]);
	}
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	read(n,m,S,T);
	for(int i=1;i<=m;i++){
		int x,y,z;read(x,y,z);
		p[i]=(node){x,y,z};
		g[x].pb(mp(y,z));
		g[y].pb(mp(x,z));
	}
	dij(S,ds);
	dij(T,dt);
	for(int i=1;i<=n;i++)
		g[i].clear();
	for(int i=1;i<=m;i++){
		int u=p[i].u,v=p[i].v,w=p[i].w;
		if(ds[u]+w+dt[v]==ds[T]) g[u].pb(mp(v,w)),f[v].pb(mp(u,w)),res[++tot]=(node){u,v,w};
		if(ds[v]+w+dt[u]==ds[T]) g[v].pb(mp(u,w)),f[u].pb(mp(v,w)),res[++tot]=(node){v,u,w};
	}
	dfs(S,T,dp2);
//	debug(dp2[S]);
//	for(int i=1;i<=n;i++)
//		dprintf("%d ",dp2[i]);dprintf("\n");
	for(int i=1;i<=n;i++)
		g[i]=f[i];
	clr(vis,0);dfs(T,S,dp1);
	int ans=(ll)dp1[T]*dp1[T]%mod;
//	debug(dp1[T]);
	for(int i=1;i<=n;i++)
		if(ds[i]==dt[i]&&ds[i]+dt[i]==ds[T])
			ch(ans,-(ll)dp1[i]*dp1[i]%mod*dp2[i]%mod*dp2[i]);
	for(int i=1;i<=tot;i++){
		int u=res[i].u,v=res[i].v,w=res[i].w;
		if(ds[u]+w>dt[v]&&dt[v]+w>ds[u])
			ch(ans,-(ll)dp1[u]*dp1[u]%mod*dp2[v]%mod*dp2[v]);
	}
	if(ans<0) ans+=mod;
	printf("%d\n",ans);
	return 0;
}