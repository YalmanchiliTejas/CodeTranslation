#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_V 100005
struct myque{
  int l,r;
  int t[MAX_V];
  void clear(){l=r=0;}
  void pop(){l++;}
  void push(int x){t[r++]=x;}
  int front(){return t[l];}
  bool empty(){return (l==r);}
};
 
struct union_find{
  int p[MAX_V],r[MAX_V];
  void init(){
    for(int i=0;i<MAX_V;i++)p[i]=i,r[i]=1;
  }
  int find(int x){
    return p[x]=(p[x]==x?x:find(p[x]));
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    if(r[x]<r[y])swap(x,y);
    p[y]=x;
    r[x]+=r[y];
  }
};
struct segtree{
  int t[(1<<18)];
  void init(){
    for(int i=0;i<(1<<18);i++)t[i]=1e9;
  }
  void set(int a,int b,int x,int k,int l,int r){
    if(b<=l || r<=a)return;
    if(a<=l && r<=b){t[k]=min(t[k],x);return;}
    int m=(l+r)/2;
    set(a,b,x,k*2+1,l,m);
    set(a,b,x,k*2+2,m,r);
  }
  void set(int a,int b,int x){
    set(a,b,x,0,0,(1<<17));
  }
  int get(int x){
    x=x+(1<<17)-1;
    int res=t[x];
    while(x){
      x=(x-1)/2;
      res=min(res,t[x]);
    }
    return res;
  }
};

struct edge{
  int to,from,cost,id;
  bool operator < (const edge &e)const{
    return cost < e.cost;
  }
};

myque que;
int pa[MAX_V],de[MAX_V],sz[MAX_V];
int cd[MAX_V],mv[MAX_V],hl[MAX_V];

union_find uf;
segtree T;

int V,m;
vector<int> G[MAX_V];
ll ans[300000],ans2[300000];
vector<edge> E;
void HLD(int);


void init(){
  E.clear();
  uf.init();
  T.init();
  memset(ans,-1,sizeof(ans));
  for(int i=0;i<MAX_V;i++){
    G[i].clear();
  }
}

void func(edge e){
  int x=e.from,y=e.to;
  while(mv[x]!=mv[y]){
    if(de[mv[x]]<de[mv[y]])swap(x,y);
    T.set(hl[mv[x]],hl[x]+1,e.cost);
    x=pa[mv[x]];
  }
  if(hl[x]>hl[y])swap(x,y);
  
  if(hl[x]+1<hl[y]+1){
    T.set(hl[x]+1,hl[y]+1,e.cost);
  }
}

void solve(){
  vector<int> A;
  ll sum=0;
  for(int i=0;i<m;i++){
    edge e=E[i];
    if( uf.find(e.to) == uf.find(e.from) ){
      A.push_back(i);
    }else{
      sum+=(ll)e.cost;
      uf.unite(e.from,e.to);
      G[e.from].push_back(e.to);
      G[e.to].push_back(e.from);
    }
  }

  if( uf.r[ uf.find(1) ]!=V )return;

  HLD(1);
  for(int i=0;i<(int)A.size();i++){
    ans[A[i]]=sum;
    func(E[A[i]]);
  }
  for(int i=0;i<m;i++){
    if(ans[i]==sum)continue;
    edge e=E[i];

    int target;
    if(hl[e.from]<hl[e.to])target=hl[e.to];
    else target=hl[e.from];


    ll key=T.get(target);

    if(key==1e9)continue;
    ans[i]=sum-(ll)e.cost+key;
  }  
}

int main(){
  while(scanf("%d %d",&V,&m)!=EOF){
    init();
    for(int i=0;i<m;i++){
      edge e;
      scanf("%d %d %d",&e.to,&e.from,&e.cost);
      e.id=i;
      E.push_back(e);
    }
    sort(E.begin(),E.end());

    solve();
    for(int i=0;i<m;i++){
      ans2[E[i].id]=ans[i];
    }
    for(int i=0;i<m;i++){
      printf("%lld\n",ans2[i]);
    }
  }
  return 0;
}




























void HLD(int root=0){
  que.clear();
  for(int i=1;i<=V;i++){
    sz[i]=1;
    pa[i]=cd[i]=mv[i]=i;
    hl[i]=G[i].size();
    if(i!=root&&hl[i]==1)que.push(i);
  }
  // calc sz[] cd[] pa[]
  while(!que.empty()){
    int pos=que.front();que.pop();
    if(pos==root)continue;
    for(int i=0;i<(int)G[pos].size();i++){
      int to=G[pos][i];
      if(pa[to]==pos)continue;
      pa[pos]=to;
      sz[to]+=sz[pos];           
      if(cd[to]==to||sz[cd[to]]<sz[pos])cd[to]=pos;
      hl[to]--;
      if(hl[to]==1)que.push(to);
    }
  }

  que.clear();
  // calc hl[] de[] mv[]

  que.push(root);
  de[root]=hl[root]=0;
  while(!que.empty()){
    int pos=que.front();que.pop();
    if(cd[pos]==pos)continue;
    mv[cd[pos]]=mv[pos];
    hl[cd[pos]]=hl[pos]+1;
    int sum=hl[pos]+1+sz[cd[pos]];
    for(int i=0;i<(int)G[pos].size();i++){
      int to=G[pos][i];
      if(to==pa[pos])continue;
      que.push(to);
      de[to]=de[pos]+1;
      if(to==cd[pos])continue;
      hl[to]=sum;
      sum+=sz[to];
    }
  }
}
 
int lca(int a,int b){
  while(mv[a]!=mv[b]){
    if(de[mv[a]]<de[mv[b]])swap(a,b);
    a=pa[mv[a]];
  }
  return (de[a]<de[b]?a:b);
}