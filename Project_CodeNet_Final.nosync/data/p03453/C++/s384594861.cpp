#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=1e9;
const int maxn=1e5+10;
const int maxm=2e5+10;
const ll mod=1e9+7;
ll to[maxm<<1],nex[maxm<<1],beg[maxn],w[maxm<<1];
ll vis[maxn],q[maxn*100];
ll dis1[maxn],dis2[maxn];
ll sum[maxn],sum1[maxn],sum2[maxn];
ll mindis;
int e;
struct node{
	ll x,y,z;
}edge[maxm<<1];
inline ll read(){
    ll x=0,flag=1;
    char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')flag=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*flag;
}
inline void add(int x,int y,int z){
    to[++e]=y;
    nex[e]=beg[x];
    beg[x]=e;
    w[e]=z;
}
inline void Spfa(ll st,ll dis[]){
    ll f=0,l=1,i;
    memset(vis,0,sizeof(vis));
    dis[st]=0;q[1]=st;vis[st]=1;
    while(f<l){
        f++;
        ll x=q[f];
        for(i=beg[x];i;i=nex[i]){
            if(dis[to[i]]>dis[x]+w[i]){
                dis[to[i]]=dis[x]+w[i];
                if(!vis[to[i]]){
                    vis[to[i]]=1;
                    q[++l]=to[i];
                }
            }
        }
        vis[x]=0;
    }
}
inline ll Dp(ll x){
	if(sum[x])return sum[x];
	for(int i=beg[x];i;i=nex[i])
		if(dis1[x]+dis2[to[i]]+w[i]==mindis)
			sum[x]=(sum[x]+Dp(to[i]))%mod;
	return sum[x];
}
int main(){
    ll i,j,m,n,s,t;
    n=read();m=read();s=read();t=read();
    ll cnt=0;
    for(i=1;i<=m;i++){
        ll x,y,z;
        x=read();y=read();z=read();
        edge[++cnt]=((node){x,y,z});edge[++cnt]=((node){y,x,z});
        add(x,y,z);add(y,x,z);
    }
    memset(dis1,63,sizeof(dis1));
    memset(dis2,63,sizeof(dis2));
    Spfa(s,dis1);Spfa(t,dis2);
    mindis=dis1[t];
    sum[t]=1;Dp(s);
    swap(dis1,dis2);swap(sum,sum2);
    sum[s]=1;Dp(t);
    swap(dis1,dis2);swap(sum,sum1);
    ll ans=0;
    for(i=1;i<=n;i++)
		if(dis1[i]==dis2[i] && dis1[i]+dis2[i]==mindis)
			(ans+=1ll*sum1[i]%mod*sum1[i]%mod*sum2[i]%mod*sum2[i]%mod)%=mod;
	for(i=1;i<=cnt;i++){
		int x=edge[i].x,y=edge[i].y,z=edge[i].z;
		if(dis1[x]+dis2[y]+z==mindis && abs(dis1[x]-dis2[y])<z)
			(ans+=1ll*sum1[x]%mod*sum1[x]%mod*sum2[y]%mod*sum2[y]%mod)%=mod;
	}
	printf("%lld\n",((1ll*sum1[t]%mod*sum1[t]%mod-ans)%mod+mod)%mod);
    return 0;
}