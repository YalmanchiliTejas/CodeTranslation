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
  
  static bool cmp_to_lt(const Edge &e1, const Edge &e2){return e1.to < e2.to;}
  static bool cmp_cost_lt(const Edge &e1, const Edge &e2){return e1.cost < e2.cost;}
  static bool cmp_to_gt(const Edge &e1, const Edge &e2){return e1.to > e2.to;}
  static bool cmp_cost_gt(const Edge &e1, const Edge &e2){return e1.cost > e2.cost;}
  friend ostream& operator<<(ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> class Graph{
public:
  int N;
  vector<vector<Edge<T>>> g;
  Graph(int N): N(N), g(N){}

  inline void add_edge(int from, int to, T w){
    g[from].push_back(Edge<T>(from, to, w));
  }

  inline void add_undirected(int a, int b, T w){
    g[a].push_back(Edge<T>(a, b, w));
    g[b].push_back(Edge<T>(b, a, w));
  }

  inline const size_t size() const {return g.size();}
  inline vector<Edge<T>>& operator[](size_t i){return g[i];}
  inline const bool empty() const {return g.empty();}
  inline vector<Edge<T>>& front(){return g.front();}
  inline vector<Edge<T>>& back(){return g.back();}
  inline auto begin(){return g.begin();}
  inline auto end(){return g.end();}
};



template <typename T, int MOD>
vector<T> dijkstra_with_route_counting(Graph<T> &graph, int src, vector<LLI> &route_count){
  int n = graph.size();
  vector<T> cost(n, -1);
  vector<bool> check(n, false);
  priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> pq;

  route_count.assign(n,0); // src->iの最短経路数え上げ
  route_count[src] = 1;
  
  cost[src] = 0;
  pq.push(make_pair(0,src));

  while(!pq.empty()){
    int i; T d;
    tie(d,i) = pq.top(); pq.pop();

    if(check[i]) continue;
    check[i] = true;

    for(auto &e : graph[i]){
      if(cost[e.to] < 0){
	cost[e.to] = d + e.cost;
	route_count[e.to] = route_count[e.from];
	pq.push(make_pair(cost[e.to], e.to));
      }else{
	if(cost[e.to] > d+e.cost){
	  cost[e.to] = min(cost[e.to], d + e.cost);
	  route_count[e.to] = route_count[e.from];
	  if(!check[e.to]) pq.push(make_pair(cost[e.to], e.to));
	}else if(cost[e.to] == d+e.cost){
	  (route_count[e.to] += route_count[e.from]) %= MOD;
	}
      }
    }
  }
  
  return cost;
}

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

      graph.add_undirected(u,v,d);
    }

    vector<LLI> count_from_s, count_from_t;

    auto ds = dijkstra_with_route_counting<LLI,mod>(graph, S, count_from_s);
    dump(count_from_s);

    auto dt = dijkstra_with_route_counting<LLI,mod>(graph, T, count_from_t);
    dump(count_from_t);

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
