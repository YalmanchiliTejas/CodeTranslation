#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 100001
#define INF 2147483647
#define REP(i,COUNT) for(int i=0;i<(int)(COUNT);i++)
struct edge{
  int to, cost;
};
typedef vector<vector<edge> > AdjList;
AdjList graph;
typedef pair<int, int> P;
void init(int n);
int find(int n);
void unite(int x,int y);
bool same(int x, int y);
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
vector<int> dist;
vector<int> dist2;
vector<int> prever;
void dijkstra(int n,int s){
  dist = vector<int>(n,INF);
  dist2 = vector<int>(n,INF);
  prever = vector<int>(n,-1);
  dist[s] = 0;

  priority_queue<P, vector<P> , greater<P> > que;
  que.push(P(0,s));
  
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    int d = p.first;
    //if(dist[v] < d){
    //  cout << dist[v] << " " << d << endl;
    //  continue;
    //}
    REP(i,graph[v].size()){
      edge e = graph[v][i];
      if(dist[e.to] > dist[v] + e.cost){
        dist[e.to] = dist[v] + e.cost;
        prever[e.to] = v;
        que.push(P(dist[e.to],e.to));
      }

    }

  }
}

int main()
{
  int N,M,a,b,cnt=0,f=0;
  cin >> N >> M;
  vector<vector<int> > Adj(N+1,vector<int>(N+1,0));
  vector<int> vs(0);
  REP(i,N){
    vs.push_back(i+1);
  }
  REP(i,M){
    cin >> a >> b;
    Adj[a][b] = 1;
    Adj[b][a] = 1;
  }
  
  do{
    f = 1;
    REP(i,N-1){
      if(!Adj[vs[i]][vs[i+1]])
        f = 0;
    }
    if(f)
      cnt++;
  }while(next_permutation(vs.begin()+1,vs.end()));
  
  cout << cnt<< endl;
  return 0;
}

int par[MAX_N];
int ranks[MAX_N];

//n要素で初期化
void init(int n){
  REP(i,n){
    par[i] = i;
    ranks[i] = 0;
  }

}

//木の根を求める
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y) return ;
  if(ranks[x] < ranks[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(ranks[x] == ranks[y]) ranks[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

