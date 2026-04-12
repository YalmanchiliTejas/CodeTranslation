#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
同一直線状は0か
横の順or縦の順でしかとりえない。
BFSでいいかな
うーん、union?
距離が短い順につなげていく。
もしunionだったらスルー
N-1回つないだら終了とか

*/

vector<bool> seen;
vector<vector<ll>> G;
struct UnionFind{
  vector<ll> par,siz;
  
  UnionFind(ll N):par(N+1),siz(N+1,1){
    for(int i=0; i<=N; i++)
      par[i]=i;
  }
  
  void mkpar1(ll parent, ll n){//親は最上位
    for(auto next_n: G[n]){
      if(seen[next_n]) continue;
      seen[next_n]=true;
      par[next_n]=parent;
      mkpar1(parent, next_n);
    }
  }
  
  void mkpar2(ll n){//親は1個うえ
    for(auto next_n: G[n]){
      if(seen[next_n]) continue;
      seen[next_n]=true;
      par[next_n]=n;
      mkpar2(next_n);
    }
  }
  
  ll root(ll x){
    if(par[x]==x)
      return x;
    return par[x]=root(par[x]);
  }
  
  void unite(ll x, ll y){
    if(x>y) swap(x,y);
    ll rx=root(x), ry=root(y);
    if(rx==ry)
      return;
    par[ry]=rx;
    siz[rx]+=siz[ry];
  }
  
  bool issame(ll x, ll y){
    return root(x)==root(y);
  }
  
  ll size(ll x){
    return siz[root(x)];
  }
};
//2点間の距離と頂点番号
//近距離順にとっていく。
//頂点番号同士でunionかどうか。unionならスルー

struct V{
  ll dis,to1,to2;
};

int main(){
  ll N; cin>>N;
  seen.assign(N+1,false);
  vector<vector<ll>> A(N+10,vector<ll>(2,0)),B(N+10,vector<ll>(2,0)),Z(N+10,vector<ll>(2,0)),G(N+10,vector<ll>(0,0));
  vector<V> D(0);
    for(ll i=1; i<=N; i++){
    ll x,y; cin>>x>>y;
    A[i][0]=x;
    A[i][1]=i;
    B[i][0]=y;
    B[i][1]=i;
    Z[i][0]=x;
    Z[i][1]=y;
  }
  sort(A.begin()+1, A.begin()+N+1, [](auto& x, auto& y){return x[0] < y[0];});
  sort(B.begin()+1, B.begin()+N+1, [](auto& x, auto& y){return x[0] < y[0];});
//Vをいれてく
  for(ll i=1; i<N; i++){
    ll a1=A[i][0],a2=A[i+1][0];
    ll b1=B[i][0],b2=B[i+1][0];
    ll n=a2-a1,m=b2-b1;
    ll to1=A[i][1];
    ll to2=A[i+1][1];
    ll to11=B[i][1];
    ll to22=B[i+1][1];
    if(to1>to2) swap(to1,to2);
    if(to11>to22) swap(to11,to22);
    D.push_back({n,to1,to2});
    D.push_back({m,to11,to22});
  }
  sort(D.begin(), D.end(), [](auto& x, auto& y){return x.dis < y.dis;});
  
  UnionFind tree(N);
  ll cnt=0,i=-1,ans=0;
  while(cnt<N-1){
    V v=D[++i];
//cout<<"i:"<<i<<" ans:"<<ans<<" dis:"<<v.dis<<" to1:"<<v.to1<<" to2:"<<v.to2<<endl;
    if(tree.issame(v.to1,v.to2))continue;
    ans+=v.dis;
    tree.unite(v.to1,v.to2);
    cnt++;
  }
  cout<<ans<<endl;
}