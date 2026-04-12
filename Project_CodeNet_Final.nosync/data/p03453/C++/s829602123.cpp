#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
#define rpp(i,x,e,head) for(int i=head[x];~i;i=e[i].next)
#define dyes cerr<<"yes"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define pts puts("")
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1LL;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
template <class T> inline void chmax(T &a,T b){if(a<b) a=b;}
template <class T> inline void chmin(T &a,T b){if(a>b) a=b;}
inline void swap(int &a,int &b){int c=a;a=b;b=c;}
using namespace std;
#define mst(a,val) memset(a,val,sizeof(a))
#define pii pair<int,ll>
#define piii pair<int,pair<int,int> >
#define mp(i,j) make_pair(i,j)
#define fi first
#define sc second
#define inf (0x3f3f3f3f)
#define id(i,j) ((i-1)*m+j)
const int N=2e5+10;
const int P=1e9+7;
struct node{
    int next,to,id;
    ll w;
}e[N<<1];
int head[N],cnt;
inline ll qpow(ll a,ll b){
    ll q=1;
    while(b){
        if(b&1) q=q*a%P;
        a=a*a%P;
        b>>=1;
    }
    return q;
}
inline ll inv(ll x){return qpow(x,P-2);}
inline void add(int u,int v,ll w,int id){
    e[cnt].id=id;e[cnt].to=v;e[cnt].w=w;e[cnt].next=head[u];head[u]=cnt++;
}
ll dis[N],val[N],pre[N];
ll dis2[N],val2[N];
struct cmp{
    bool operator () (pii a,pii b)const{
        return a.sc>b.sc;
    }
};
int n,m,s,t,vis[N];
ll oscar[N],ind;
int u[N],v[N],w[N];
int ison[N];
int main(){
    mst(head,-1);n=read();m=read();
    s=read();t=read();
    rep(i,1,m){
        u[i]=read(),v[i]=read(),w[i]=read()<<1;
        add(u[i],v[i],w[i],i);add(v[i],u[i],w[i],i);
    }
    priority_queue<pii ,vector <pii> ,cmp> q;mst(dis,0x3f);
    q.push(mp(s,0));val[s]=1;dis[s]=0;
    while(!q.empty()){
        pii cur=q.top();q.pop();int x=cur.fi;if(vis[x]) continue;vis[x]=1;
        rpp(i,x,e,head){
            int v=e[i].to;
            if(dis[v]>dis[x]+e[i].w){
                dis[v]=dis[x]+e[i].w;pre[v]=e[i].id;
                val[v]=val[x];q.push(mp(v,dis[v]));
            }else if(dis[v]==dis[x]+e[i].w){
                (val[v]+=val[x])%=P;
            }
        }
    }
    mst(vis,0);
    mst(dis2,0x3f);q.push(mp(t,0));val2[t]=1;dis2[t]=0;
    while(!q.empty()){
        pii cur=q.top();q.pop();int x=cur.fi;if(vis[x]) continue;vis[x]=1;
        rpp(i,x,e,head){
            int v=e[i].to;
            if(dis2[v]>dis2[x]+e[i].w){
                dis2[v]=dis2[x]+e[i].w;pre[v]=x;
                val2[v]=val2[x];q.push(mp(v,dis2[v]));
            }else if(dis2[v]==dis2[x]+e[i].w){
                (val2[v]+=val2[x])%=P;
            }
        }
    }
//    rep(i,1,n) cerr<<val[i]<<" ";pts;
//    rep(i,1,n) cerr<<dis[i]<<" ";pts;
    ll qwqd=dis[t]>>1;
    ll ans=val[t]*val[t]%P;
    rep(x,1,n){
        if(dis[x]==qwqd&&dis2[x]==qwqd){
            ans=((ans-val[x]*val[x]%P*val2[x]%P*val2[x])%P+P)%P;
        }
        rpp(i,x,e,head){
            int v=e[i].to;
            if(dis[x]<qwqd&&dis[v]>qwqd)
            if(dis[x]<qwqd&&dis2[v]<=qwqd&&dis[x]+dis2[v]+e[i].w==dis[t]){
                ans=((ans-val[x]*val[x]%P*val2[v]%P*val2[v])%P+P)%P;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}





