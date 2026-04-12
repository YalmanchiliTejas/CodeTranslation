#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
template<class _Tp>_Tp max(_Tp a,_Tp b){if(a>b) return a;return b;}
template<class _Tp>_Tp min(_Tp a,_Tp b){if(a<b) return a;return b;}
template<class _Tp>void ckmax(_Tp &a,_Tp b){if(a<b) a=b;}
template<class _Tp>void ckmin(_Tp &a,_Tp b){if(a>b) a=b;}
template<class _Tp>void sswap(_Tp &a,_Tp &b){_Tp c=a;a=b;b=c;}
template<class _Tp>_Tp gcd(_Tp a,_Tp b){return (b==0)?(a):(gcd(b,a%b));}
template<class _Tp>_Tp abs(_Tp a){if(a<0)return-a;return a;}
int read(){
	char ch=getchar();bool f=1;int x=0;
	while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
	if(ch=='-') f=0,ch=getchar();
	while(ch>='0' && ch<='9'){x=x*10+(ch&15);ch=getchar();}
	return f?x:-x;
}
ll readll(){
	char ch=getchar();bool f=1;ll x=0ll;
	while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
	if(ch=='-') f=0,ch=getchar();
	while(ch>='0' && ch<='9'){x=x*10+(ch&15ll);ch=getchar();}
	return f?x:-x;
}
const int inf=1000000000;
const ll mod=1000000007;
#define N 100050
#define M 200050
int w[M<<1],nxt[M<<1],to[M<<1],head[N];
int A[M],B[M],C[M],top,n,m,S,T;
ll dis1[N],dis2[N],cnt1[N],cnt2[N],ans;
bool vis1[N],vis2[N];
void add(int u,int v,int z){
	to[++top]=v;
	nxt[top]=head[u];
	head[u]=top;
	w[top]=z;
}
#include<queue>
priority_queue<pli,vector<pli>,greater<pli> > q;
void dij(ll *dis,ll *cnt,bool *vis,int s){
	dis[s]=0;
	q.push(pli(0ll,s));
	cnt[s]=1;
	while(!q.empty()){
		pli Tmp=q.top();q.pop();
		int u=Tmp.second;
		ll d=Tmp.first;
		if(vis[u]||dis[u]<d)continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			if(dis[to[i]]==d+w[i])
				cnt[to[i]]=(cnt[to[i]]+cnt[u])%mod;
			if(dis[to[i]]>d+w[i]){
				dis[to[i]]=d+w[i];
				cnt[to[i]]=cnt[u];
				q.push(pli(dis[to[i]],to[i]));
			}
		}
	}
	return;
}
int main(){
	n=read();m=read();
	S=read();T=read();
	for(int i=1,x,y,z;i<=m;++i){
		x=read();y=read();z=read();
		add(x,y,z);
		add(y,x,z);
		A[i]=x;B[i]=y;C[i]=z;
	}
	memset(dis1,0x3f,sizeof(dis1));
	dij(dis1,cnt1,vis1,S);
	memset(dis2,0x3f,sizeof(dis2));
	dij(dis2,cnt2,vis2,T);
	ll Dis=dis1[T];
//	printf("** %lld\n",Dis);
	ans=cnt1[T]*cnt1[T]%mod;
	for(int i=1;i<=n;++i){//point
		if(dis1[i]+dis2[i]==Dis&&dis1[i]==dis2[i])
			ans=(ans-cnt1[i]*cnt1[i]%mod*cnt2[i]%mod*cnt2[i]%mod)%mod;
	}
	for(int i=1,u,v,d;i<=m;++i){//edge
		u=A[i];v=B[i];d=C[i];
		if(dis1[u]+d+dis2[v]==Dis&&dis1[u]+d>dis2[v]&&dis2[v]+d>dis1[u])
			ans=(ans-cnt1[u]*cnt2[v]%mod*cnt1[u]%mod*cnt2[v]%mod)%mod;
		sswap(u,v);
		if(dis1[u]+d+dis2[v]==Dis&&dis1[u]+d>dis2[v]&&dis2[v]+d>dis1[u])
			ans=(ans-cnt1[u]*cnt2[v]%mod*cnt1[u]%mod*cnt2[v]%mod)%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}
