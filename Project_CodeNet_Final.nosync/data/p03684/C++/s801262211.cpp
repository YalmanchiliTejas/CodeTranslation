#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rFOR(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,b) FOR(i,0,b)
#define INF 1e9
#define dump(x) cerr<< #x << " = "<<(x)<<endl
#define int long long

using ll = long long;
const ll mod = LLONG_MAX;

typedef pair<int,int> P;

struct edge{
  int u,v,cost;
};
bool comp(const edge& e1,const edge& e2){
  return e1.cost < e2.cost;
}
int uni[1000010];
void init(int N){
  for(int i=0;i<N;i++){
    uni[i]=-1;
  }
}

int root(int a){
  if(uni[a] < 0)return a;
  else return uni[a] = root(uni[a]);
}
bool unite(int a,int b){
  a = root(a);
  b = root(b);
  if(a==b) return false;
  if(uni[a] > uni[b]) swap(a,b);
  uni[a]+=uni[b];
  uni[b]=a;
}
bool same(int a,int b){
  return root(a)==root(b);
}

vector<edge> es;
vector<P> xbox;
vector<P> ybox;
int n,E;

int kruskal(){
  sort(es.begin(),es.end(),comp);
  init(n+10);
  int res=0;
  rep(i,es.size()){
    edge e=es[i];
    if(!same(e.u,e.v)){
      unite(e.u,e.v);

      res+=e.cost;
    }
  }
  return res;
}

signed main(){
  cin>>n;
  rep(i,n){
    int x,y;
    cin>>x>>y;
    xbox.push_back(P(x,i));
    ybox.push_back(P(y,i));
  }
  sort(xbox.begin(),xbox.end());
  sort(ybox.begin(),ybox.end());
  //辺をはる
  rep(i,n-1){
    es.push_back((edge){xbox[i].second,xbox[i+1].second,xbox[i+1].first-xbox[i].first});
    es.push_back((edge){xbox[i+1].second,xbox[i].second,xbox[i+1].first-xbox[i].first});
    es.push_back((edge){ybox[i].second,ybox[i+1].second,ybox[i+1].first-ybox[i].first});
    es.push_back((edge){ybox[i+1].second,ybox[i].second,ybox[i+1].first-ybox[i].first});
  }

  cout<<kruskal()<<endl;


}
