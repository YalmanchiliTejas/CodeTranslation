#include <bits/stdc++.h>
#define SORT(x) sort(x.begin(),x.end())
#define ALL(x) x.begin(),x.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, m, n) for(int i = m; i < n; i++)
#define repr(i, m, n) for(int i = m; i >= n; i--)
#define INF (1e9)
#define PI (acos(-1))
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll ct;
struct edge{ll to;}; //edgeパラメータ
struct graph{
  ll N; //ノードの個数
  vector<vector<edge> > G; //G[辺の元]((.to辺の先,.costコスト),...)

  vector<bool> visited;

  graph(ll n){ //グラフ生成時
    N = n;
    G.resize(N); //Edge情報
    visited.resize(N); //Node情報,深さ
    rep(i,N){visited[i] = false;}
  }
  void add_edge(ll s, ll t){
    G[s].emplace_back((edge){t});
  }

  void dfs(ll v=0){
    visited[v]=true;
    bool lastv=true;
    rep(i,N){
      if(!visited[i]) lastv=false;
    }
    if(lastv){
      ct++;
      visited[v]=false;
      return;
    }
    for(auto E : G[v]){ // E つなぐエッジ
      if(visited[E.to]) continue;
      dfs(E.to); //まだ行ってないなら
    }
    visited[v]=false;
  }
};



void Main(){

  int M,N;

  cin>>N>>M;

  graph g(N);

  rep(i,M){
    int a,b;
    cin>>a>>b;
    g.add_edge(a-1,b-1);
    g.add_edge(b-1,a-1);
  }

  g.dfs(0);

  cout << ct <<"\n";
}
//-----------------------------------
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
//-----------------------------------
