#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll unipar[4010];
ll unilen[4010];
vector<pll> vn[4010];
struct edge{
  ll len,from,to;
};
bool cmp(edge& a,edge& b){
  return a.len<b.len;
}
void uniinit(ll n){
  for(ll i=1;i<=n;i++){
    unipar[i]=i;
    unilen[i]=0;
  }
}
ll root(ll n){
  if(unipar[n]==n)return n;
  return unipar[n]=root(unipar[n]);
}
void unit(ll a,ll b){
  a=root(a);
  b=root(b);
  if(a==b)return;
  if(unilen[a]<unilen[b]){
    unipar[a]=b;
  }
  else{
    unipar[b]=a;
    if(unipar[b]==unipar[a])unilen[a]++;
  }
}
ll ne;
ll par[60][4010];
ll dep[4010];
void lcadfs(ll v,ll p,ll d){
  par[0][v]=p;
  dep[v]=d;
  for(ll i=0;i<vn[v].size();i++){
    if(vn[v][i].first!=p)lcadfs(vn[v][i].first,v,d+1);
  }
}
void lcainit(ll n){
  lcadfs(ne,-1,0);
  for(ll i=0;i<59;i++){
    for(ll j=1;j<=n;j++){
      if(par[i][j]<0)par[i+1][j]=-1;
      else par[i+1][j]=par[i][par[i][j]];
    }
  }
}
ll lca(ll u,ll v){
  if(dep[u]>dep[v])swap(u,v);
  for(ll i=0;i<60;i++){
    if((dep[v]-dep[u])>>i&1)v=par[i][v];
  }
  if(u==v)return u;
  for(ll i=59;i>=0;i--){
    if(par[i][u]!=par[i][v]){
      u=par[i][u];
      v=par[i][v];
    }
  }
  return par[0][u];
}
ll mae[60][4010];
void maedfs(ll v,ll p,ll dis){
  mae[0][v]=dis;
  for(ll i=0;i<vn[v].size();i++){
    if(vn[v][i].first!=p)maedfs(vn[v][i].first,v,vn[v][i].second);
  }
}
void maeinit(ll n){
  maedfs(ne,-1,-1);
  for(ll i=0;i<59;i++){
    for(ll j=1;j<=n;j++){
      if(par[i][j]<0)mae[i+1][j]=-1;
      else mae[i+1][j]=max(mae[i][j],mae[i][par[i][j]]);
    }
  }
}
ll maxedge(ll u,ll v){
  ll r=lca(u,v);
  ll ret=0;
  for(ll i=59;i>=0;i--){
    if((dep[u]-dep[r])>>i&1){
      ret=max(ret,mae[i][u]);
      u=par[i][u];
    }
  }
  for(ll i=59;i>=0;i--){
    if((dep[v]-dep[r])>>i&1){
      ret=max(ret,mae[i][v]);
      v=par[i][v];
    }
  }
  return ret;
}
int main(){
  ll n,m;cin>>n>>m;
  vector<edge> v;
  for(ll i=0;i<m;i++){
    ll a,b,c;cin>>a>>b>>c;
    v.push_back((edge){c,a,b});
  }
  sort(v.begin(),v.end(),cmp);
  uniinit(n);
  ll now=0;
  ll sum=0;
  for(ll i=0;i<m;i++){
    edge e=v[i];
    ll a=e.from,b=e.to;
    if(root(a)!=root(b)){
      unit(a,b);
      sum+=e.len;
      vn[a].push_back(make_pair(b,e.len));
      vn[b].push_back(make_pair(a,e.len));
      now++;
    }
    if(now==n-1)break;
  }
  ne=1;
  lcainit(n);
  maeinit(n);
  ll q;cin>>q;
  for(ll i=0;i<q;i++){
    ll s,t;cin>>s>>t;
    ll dd=maxedge(s,t);
    cout<<sum-dd<<endl;
  }
  //cout<<maxedge(5,7)<<endl;
  //for(ll i=0;i<10;i++){
    //for(ll j=1;j<=7;j++)cout<<par[i][j]<<" ";
    //cout<<endl;
  //}
}