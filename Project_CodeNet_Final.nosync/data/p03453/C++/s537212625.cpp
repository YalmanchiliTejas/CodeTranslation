#include <bits/stdc++.h>
#define FOR(v, a, b) for(int v = (a); v < (b); ++v)
#define FORE(v, a, b) for(int v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(int v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define LLI long long int
#define fst first
#define snd second

#ifdef DEBUG
#include <misc/C++/Debug.cpp>
#else
#define dump(x) ((void)0)
#endif

#define gcd __gcd

using namespace std;
template <class T> constexpr T lcm(T m, T n){return m/gcd(m,n)*n;}

template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}
template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto &a : v) is >> a; return is;}
template <typename T, typename U> istream& operator>>(istream &is, pair<T,U> &p){is >> p.first >> p.second; return is;}

template <typename T, typename U> bool chmin(T &a, const U &b){return (a>b ? a=b, true : false);}
template <typename T, typename U> bool chmax(T &a, const U &b){return (a<b ? a=b, true : false);}
template <typename T, size_t N, typename U> void fill_array(T (&a)[N], const U &v){fill((U*)a, (U*)(a+N), v);}

template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}

  Edge rev() const {return Edge(to,from,cost);}
  
  friend ostream& operator<<(ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Graph = vector<vector<Edge<T>>>;
template <typename T> using Tree = vector<vector<Edge<T>>>;

template <typename C, typename T> void add_edge(C &g, int from, int to, T w){
  g[from].push_back(Edge<T>(from, to, w));  
}

template <typename C, typename T> void add_undirected(C &g, int a, int b, T w){
  g[a].push_back(Edge<T>(a, b, w));
  g[b].push_back(Edge<T>(b, a, w));
}


template <typename T, int MOD = 1000000007>
struct Dijkstra{
  int n;
  vector<T> dist;
  vector<bool> no_path;
  vector<int64_t> path_count;
  
  Dijkstra(const Graph<T> &graph, int src):
    n(graph.size()), dist(n), no_path(n, true), path_count(n)
  {
    vector<bool> check(n, false);
    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> pq;

    path_count[src] = 1;
    dist[src] = 0;
    no_path[src] = false;

    pq.push({0, src});

    while(not pq.empty()){
      int i;
      T d;
      tie(d,i) = pq.top(); pq.pop();

      if(check[i]) continue;
      check[i] = true;

      for(auto &e : graph[i]){
        if(no_path[e.to]){
          dist[e.to] = d + e.cost;
          no_path[e.to] = false;
          path_count[e.to] = path_count[e.from];
          pq.push({dist[e.to], e.to});
        }else{
          if(dist[e.to] > d + e.cost){
            dist[e.to] = d + e.cost;
            path_count[e.to] = path_count[e.from];
            if(not check[e.to]) pq.push({dist[e.to], e.to});
          }else if(dist[e.to] == d + e.cost){
            (path_count[e.to] += path_count[e.from]) %= MOD;
          }
        }
      }
    }
  }
};


const LLI mod = 1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M,S,T;
  while(cin >> N >> M >> S >> T){
    --S, --T;

    Graph<LLI> graph(N);
    REP(i,M){
      int u,v,d; cin >> u >> v >> d;
      --u;
      --v;

      add_undirected(graph,u,v,(LLI)d);
    }


    auto res_s = Dijkstra<LLI,mod>(graph, S);
    auto res_t = Dijkstra<LLI,mod>(graph, T);

    auto ds = res_s.dist;
    auto dt = res_t.dist;
    
    auto count_from_s = res_s.path_count;
    auto count_from_t = res_t.path_count;

    LLI L = ds[T];
    dump(L);
 
    LLI ans = count_from_s[T] * count_from_t[S] % mod;
 
    LLI sub = 0;
 
    if(L%2==0){
      REP(i,N){
        if(ds[i] == L/2 and dt[i] == L/2){
          LLI temp = count_from_s[i] * count_from_t[i] % mod;
          (sub += temp * temp % mod) %= mod;
        }
      }
    }
 
    for(auto &es : graph){
      for(auto &e : es){
        if(ds[e.from]+dt[e.to]+e.cost==L and ds[e.from] < L/2 and dt[e.to] < L/2){
          LLI temp = count_from_s[e.from] * count_from_t[e.to] % mod;
          (sub += temp * temp % mod) %= mod;
        }
      }
    }
    
    ans = (ans - sub + mod) % mod;

    cout << ans << endl;
  }
  
  return 0;
}
