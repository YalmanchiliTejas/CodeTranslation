#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define int ll
const ll inf=1744174417441744;
const ll mod=1e9+7;
ll dist_s[100005]={0},dist_t[100005]={0},num_s[100005]={0},num_t[100005]={0};
vector<P> node[100005];
void dijkstra_s(ll s){
  priority_queue<P,vector<P>,greater<P>> pque;
  pque.push(P(0,s));
  num_s[s]=1;
  for(int i=1;i<100005;i++) dist_s[i]=inf;
  dist_s[s]=0;
  while(!pque.empty()){
    P p=pque.top();
    pque.pop();
    ll cos=p.first,pos=p.second;
    if(dist_s[pos]<cos) continue;
    for(int i=0;i<node[pos].size();i++){
      ll to=node[pos][i].first,ncos=node[pos][i].second;
      ncos+=cos;
      if(dist_s[to]>ncos){
        dist_s[to]=ncos;
        num_s[to]=num_s[pos];
        num_s[to]%=mod;
        pque.push(P(ncos,to));
      }
      else if(dist_s[to]==ncos){
        num_s[to]+=num_s[pos];
        num_s[to]%=mod;
      }
    }
  }
}
void dijkstra_t(ll t){
  priority_queue<P,vector<P>,greater<P>> pque;
  pque.push(P(0,t));
  num_t[t]=1;
  for(int i=1;i<100005;i++) dist_t[i]=inf;
  dist_t[t]=0;
  while(!pque.empty()){
    P p=pque.top();
    pque.pop();
    ll cos=p.first,pos=p.second;
    if(dist_t[pos]<cos) continue;
    for(int i=0;i<node[pos].size();i++){
      ll to=node[pos][i].first,ncos=node[pos][i].second;
      ncos+=cos;
      if(dist_t[to]>ncos){
        dist_t[to]=ncos;
        num_t[to]=num_t[pos];
        num_t[to]%=mod;
        pque.push(P(ncos,to));
      }
      else if(dist_t[to]==ncos){
        num_t[to]+=num_t[pos];
        num_t[to]%=mod;
      }
    }
  }
}
signed main(){
  ll n,m,s,t;
  cin>>n>>m>>s>>t;
  for(int i=0;i<m;i++){
    ll u,v,d;
    cin>>u>>v>>d;
    node[u].push_back(P(v,d));
    node[v].push_back(P(u,d));
  }
  dijkstra_s(s);
  dijkstra_t(t);
  for(int i=1;i<=n;i++){
    num_s[i]%=mod;
    num_t[i]%=mod;
  }
  ll L=dist_s[t];
  ll ans=(num_s[t]*(num_s[t]-1))%mod;
  if(L%2==0){
    for(int i=1;i<=n;i++){
      if(dist_s[i]*2==L&&dist_t[i]*2==L){
        ll path_num=(num_s[i]*num_t[i])%mod;
        path_num*=(path_num-1);
        path_num%=mod;

        ans-=path_num;
        ans+=mod;
        ans%=mod;
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<node[i].size();j++){
      ll u=i,v=node[i][j].first;
      if(dist_s[u]*2<L&&dist_t[v]*2<L&&dist_s[u]+dist_t[v]+node[i][j].second==L){
        ll path_num=(num_s[u]*num_t[v])%mod;
        path_num*=(path_num-1);
        path_num%=mod;

        ans-=path_num;
        ans+=mod;
        ans%=mod;
      }
    }
  }
  cout<<ans%mod<<endl;
}
