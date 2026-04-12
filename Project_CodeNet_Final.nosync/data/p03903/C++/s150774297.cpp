#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

struct Edge{
    int from, to;
    ll cost;
    Edge(int from,int to,ll cost): from(from),to(to), cost(cost){}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (const Edge &e, const Edge &f){
    return e.cost > f.cost;
}

struct UF {
	vector<int> data;
	UF(int size) : data(size, -1) { }
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool find(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;cin>>n>>m;
    Graph g(n);
    priority_queue<Edge> pq;
    for(int i=0;i<m;i++){
      int a,b;cin>>a>>b;a--;b--;
      ll c;cin>>c;
      pq.push(Edge(a,b,c));
      g[a].push_back(Edge(a,b,c));
      g[b].push_back(Edge(b,a,c));
    }
    ll sum=0;
    UF uf(n);
    Graph mst(n);
    while(!pq.empty()){
      Edge e=pq.top();pq.pop();
      if(uf.find(e.from,e.to)) continue;
      uf.unite(e.from,e.to);
      mst[e.from].push_back(Edge(e.from,e.to,e.cost));
      mst[e.to].push_back(Edge(e.to,e.from,e.cost));
      sum += e.cost;
    }
    vector<vector<ll>> dis(n,vector<ll>(n,-1));
    for(int i=0;i<n;i++){
      queue<int> q;
      dis[i][i]=0;
      q.push(i);
      while(!q.empty()){
        int v=q.front();q.pop();
        for(int j=0;j<(int)mst[v].size();j++){
          int next=mst[v][j].to;
          if(dis[i][next]!=-1) continue;
          dis[i][next]=max(dis[i][v], mst[v][j].cost);
          q.push(next);
        }
      }
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
      int s,t;cin>>s>>t;s--;t--;
      cout<<sum-dis[s][t]<<endl;
    }
}
