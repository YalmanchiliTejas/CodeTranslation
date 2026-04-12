#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

const int MAX_V=4040;
struct edge {int to,cost;};
vector<vector<edge>> G(MAX_V);
vector<tuple<int,int,int> > E;
int N,M;

int par[MAX_V]; //　親
int rnk[MAX_V]; // rank, 木の深さ

// V要素で初期化
void init(){
  for(int i=0;i<MAX_V;i++){
    par[i]=i;
    rnk[i]=0;
  }
}

// 木の根を求める
int find(int x){
  if (par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

// ｘとｙの属する集合を併合
void unite(int x, int y){
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rnk[x] < rnk[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

// ｘとｙが同じ集合に属するかどうか
bool same(int x, int y){
  return find(x) == find(y);
}

int maxE[4040][4040];

int main(){
  cin>>N>>M;
  rep(i,M){
    int a,b,c; cin>>a>>b>>c; a--,b--;
    E.push_back(make_tuple(c,a,b));
  }
  sort(E.begin(),E.end());
  init();
  ll sum=0;
  rep(i,M){
    tuple<int,int,int> t=E[i];
    int c=get<0>(t),a=get<1>(t),b=get<2>(t);
    if(!same(a,b)){
      unite(a,b);
      G[a].push_back({b,c});
      G[b].push_back({a,c});
      sum+=c;
    }
  }
  rep(s,N){
    queue<tuple<int,int,int> > que;
    que.push(make_tuple(s,-1,0));
    while(que.size()){
      tuple<int,int,int> t=que.front(); que.pop();
      int v=get<0>(t), p=get<1>(t), ma=get<2>(t);
      for(auto e:G[v]) if(e.to!=p){
        if(e.cost>ma) ma=e.cost;
        maxE[s][e.to]=ma;
        que.push(make_tuple(e.to,v,ma));
      }
    }
  }
  int Q; cin>>Q;
  rep(i,Q){
    int s,t; cin>>s>>t; s--,t--;
    cout<<sum-maxE[s][t]<<endl;
  }
  return 0;
}
