#include<bits/stdc++.h>
#define ll long long
#define pli pair<ll,int>
#define fi first
#define se second
#define mod 1000000007
using namespace std;

struct R{
  int to,nex,val;
}r[404000];

int n,m,st,en,cnt=0,hea[101000];
ll d[101000],f[101000],g[101000],ans,len;

struct Node{
  int u,v;
};
vector<Node>vec;

priority_queue<pli,vector<pli>,greater<pli> >q;

void Dj(){
  for (;!q.empty();) q.pop();
  memset(d,33,sizeof d);
  d[st]=0; q.push((pli){0,st});
  int x,y; ll dx,dy; pli tmp;
  for (;!q.empty();){
    tmp=q.top(); q.pop();
    x=tmp.se; dx=tmp.fi;
    if (d[x]!=dx) continue;
    for (int i=hea[x];i;i=r[i].nex){
      y=r[i].to; dy=dx+r[i].val;
      if (d[y]>dy){
	d[y]=dy;
	q.push((pli){dy,y});
      }
    }
  }
}

ll dfs1(int x){
  if (~f[x]) return f[x];
  f[x]=0;
  for (int i=hea[x];i;i=r[i].nex)
    if (d[r[i].to]==d[x]+r[i].val){
      f[x]=(f[x]+dfs1(r[i].to))%mod;
      if (d[x]*2<len&&d[r[i].to]*2>len)
	      vec.push_back((Node){x,r[i].to});
    }
  return f[x];
}

ll dfs2(int x){
  if (~g[x]) return g[x];
  g[x]=0;
  for (int i=hea[x];i;i=r[i].nex)
    if (d[r[i].to]==d[x]-r[i].val)
      g[x]=(g[x]+dfs2(r[i].to))%mod;
  return g[x];
}

int main(){
  cin>>n>>m; cin>>st>>en;
  int x,y,z;
  for (;m--;){
    scanf("%d%d%d",&x,&y,&z);
    r[++cnt]=(R){y,hea[x],z}; hea[x]=cnt;
    r[++cnt]=(R){x,hea[y],z}; hea[y]=cnt;
  }
  Dj(); len=d[en];
  //for (int i=1;i<=n;++i) printf("%lld ",d[i]); puts("");
  for (int i=1;i<=n;++i)
    if (d[i]*2==len)
      vec.push_back((Node){i,i});
  memset(f,-1,sizeof f); f[en]=1;
  dfs1(st);
  memset(g,-1,sizeof g); g[st]=1;
  dfs2(en);
  ans=f[st]*f[st]%mod;
  //cerr<<ans<<endl;
  for (auto o:vec){
    //cerr<<g[o.u]<<' '<<f[o.v]<<endl;
    ans=(ans-g[o.u]*f[o.v]%mod*g[o.u]%mod*f[o.v]%mod)%mod;
  }
  ans=(ans%mod+mod)%mod;
  cout<<ans<<endl;
}
