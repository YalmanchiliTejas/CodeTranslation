#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) FOR(i,0,b)
#define INF mugen
#define dump(x) cerr<<#x<<"="<<x<<endl
#define all(a) (a).begin(),(a).end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<int,int> P;
template <class T> void chmin(T & a, T const & b) { if (b < a) a = b; }

using ll = long long;
const ll mod = LLONG_MAX;

int V,E;
int w[112345];
int s[112345],t[112345];

int uni[1000010];
void init(int V){
  for(int i=0;i<V;i++){
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

const int MAX_E = 1123456; //辺の最大数
struct edge{
  int u, v, cost;
  edge(int u,int v,int cost){
    this->u=u;
    this->v=v;
    this->cost = cost;
  }
};
vector<edge> es;
//----------クラスカル法------------
bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}
int kruskal() {
  sort(es.begin(), es.end(), comp); // edge.costの小さい順 Eは変数
  init(V); // Union-Findの初期化 Vは頂点数
  int res = 0;
  for (int i = 0; i < es.size(); i++) {
    edge e = es[i];
    if (!same(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}



pair<int,int> x[112345],y[112345];
int main(){
  int N;
  cin>>N;
  V=3*N;
  rep(i,N){
    cin>>x[i].first>>y[i].first;
    x[i].second=i;
    y[i].second=i+N;
  }
  dump('a');


  rep(i,N){
    es.push_back(edge{x[i].second,y[i].second,0});
  }
  dump('b');

  sort(x,x+N);
  sort(y,y+N);
  dump('a');
  rep(i,N-1){
    es.push_back(edge{x[i+1].second,x[i].second,x[i+1].first-x[i].first});
  }

  rep(i,N-1){
    es.push_back(edge{y[i+1].second,y[i].second,y[i+1].first-y[i].first});
  }
  dump('c');


  int ans=kruskal();
  cout<<ans<<endl;
}
