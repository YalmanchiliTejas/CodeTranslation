#include <bits/stdc++.h>
#define il inline
#define RG register
#define ll long long
#define rhl (1000000007)
#define inf (1LL<<60)
#define N (500005)

using namespace std;

struct edge{ int nt,to,dis; }g[N];
struct data{
  int x; ll dis;
  il int operator < (const data &a) const{
    return dis>a.dis;
  }
};

priority_queue<data> Q;

int head[N],vis[N],f[N],h[N],S,T,n,m,num,ans;
ll dis1[N],dis2[N],len;

il int gi(){
  RG int x=0,q=1; RG char ch=getchar();
  while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
  if (ch=='-') q=-1,ch=getchar();
  while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
  return q*x;
}

il void insert(RG int from,RG int to,RG int dis){
  g[++num]=(edge){head[from],to,dis},head[from]=num; return;
}

il void dijkstra(ll *dis,RG int S,RG int T){
  for (RG int i=1;i<=n;++i) dis[i]=inf,vis[i]=0;
  dis[S]=0,Q.push((data){S,0});
  while (!Q.empty()){
    RG data now=Q.top(); Q.pop();
    if (vis[now.x]) continue; vis[now.x]=1;
    for (RG int i=head[now.x],v;i;i=g[i].nt){
      v=g[i].to;
      if (dis[v]>dis[now.x]+g[i].dis)
	dis[v]=dis[now.x]+g[i].dis,Q.push((data){v,dis[v]});
    }
  }
  return;
}

il int dfs1(RG int x){
  if (x==S) return f[x]=1;
  if (f[x]!=-1) return f[x]; f[x]=0;
  for (RG int i=head[x];i;i=g[i].nt)
    if (dis1[x]==dis1[g[i].to]+g[i].dis){
      f[x]+=dfs1(g[i].to);
      if (f[x]>=rhl) f[x]-=rhl;
    }
  return f[x];
}

il int dfs2(RG int x){
  if (x==T) return h[x]=1;
  if (h[x]!=-1) return h[x]; h[x]=0;
  for (RG int i=head[x];i;i=g[i].nt)
    if (dis2[x]==dis2[g[i].to]+g[i].dis){
      h[x]+=dfs2(g[i].to);
      if (h[x]>=rhl) h[x]-=rhl;
    }
  return h[x];
}

int main(){
  n=gi(),m=gi(),S=gi(),T=gi();
  memset(f,-1,sizeof(f)),memset(h,-1,sizeof(h));
  for (RG int i=1,u,v,w;i<=m;++i)
    u=gi(),v=gi(),w=gi(),insert(u,v,w),insert(v,u,w);
  dijkstra(dis1,S,T),dijkstra(dis2,T,S),len=dis1[T];
  dfs1(T),dfs2(S),ans=1LL*f[T]*f[T]%rhl;
  for (RG int i=1,tmp;i<=n;++i)
    if (dis1[i]*2==len && dis2[i]*2==len)
      tmp=1LL*f[i]*h[i]%rhl,ans=(ans-1LL*tmp*tmp)%rhl;
  for (RG int x=1;x<=n;++x)
    for (RG int i=head[x],tmp;i;i=g[i].nt)
      if (dis1[x]*2<len && dis2[g[i].to]*2<len && dis1[x]+dis2[g[i].to]+g[i].dis==len)
	tmp=1LL*f[x]*h[g[i].to]%rhl,ans=(ans-1LL*tmp*tmp)%rhl;
  cout<<(ans+rhl)%rhl; return 0;
}
