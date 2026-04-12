#include <bits/stdc++.h>
#define int long long int
#define mod(x) ((x % MOD) + MOD) % MOD
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define RFORE(i,a,b) for(int i=(b);i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SZ(c) (int)((c).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define LB(c,x) (int)(lower_bound(ALL(c),x)-(c).begin())
#define UB(c,x) (int)(upper_bound(ALL(c),x)-(c).begin())
#define COUNT(c,x) (UB(c,x)-LB(c,x))
#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)),(c).end());
#define COPY(c1,c2) copy(ALL(c1),(c2).begin())
#define EXIST(s,e) (bool)((s).find(e)!=(s).end())
#define PB push_back
#define MP make_pair
#define DEL(v) decltype(v)().swap(v)
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
using namespace std;
template<typename T1, typename T2> using P = pair<T1,T2>;
template<typename T> using V = vector<T>;
struct edge { int from, to; int cost; };
bool operator< (const edge &edge1, const edge &edge2) { return edge1.cost < edge2.cost; };
const int INF = 1e18;
const int MOD = 1e9+7;

template<typename T> ostream& operator << (ostream& s, const V<T>& v) {
   s << "[";
   for (int i = 0; i < v.size(); i++) { s << v[i]; if (i < v.size() - 1) s << " "; }
   s << "]";
   return s;
}

template<typename T>
void add_edge(vector< vector<edge> >& G, int u, int v, T c) {
   G[u].push_back((edge){ u, v, c });
   G[v].push_back((edge){ v, u, c });
}

template<typename T>
void dijkstra(const vector< vector<edge> >& G, vector<T>& d, int s)
{
   priority_queue<P<T,int>, vector<P<T,int>>, greater<P<T,int>> > que;
   fill(d.begin(), d.end(), INF);
   d[s] = 0;
   que.push(make_pair(0, s));
   while(!que.empty()) {
      T temp_cost = que.top().first;
      int from = que.top().second;
      que.pop();
      if (d[from] < temp_cost) continue;
      for (int i = 0; i < G[from].size(); i++) {
         edge e = G[from][i];
         if (d[e.to] > d[from] + e.cost) {
            d[e.to] = d[from] + e.cost;
            que.push(make_pair(d[e.to], e.to));
         }
      }
   }
}

signed main()
{
   int N, M, S, T; cin >> N >> M >> S >> T;
   S--; T--;
   V<int> u(M), v(M), D(M);
   REP(i, M) {
      cin >> u[i] >> v[i] >> D[i];
      u[i]--; v[i]--;
   }

   V<V<edge>> G(N);
   REP(i, M) {
      add_edge(G, u[i], v[i], D[i]);
   }

   V<int> d(N, INF);
   dijkstra(G, d, S);

   V<int> order(N);
   V<P<int,int>> pair(N);
   REP(i, N) pair[i] = MP(d[i], i);
   SORT(pair);
   REP(i, N) order[i] = pair[i].second;

   V<int> n1(N, 0), n2(N, 0);
   n1[S] = 1;
   FOR(i, 0, SZ(order)) {
      int idx = order[i];
      REP(j, SZ(G[idx])) {
         edge e = G[idx][j];
         if (d[e.from] + e.cost == d[e.to]) {
            n1[e.to] = mod(n1[e.to] + n1[e.from]);
         }
      }
   }
   n2[T] = 1;
   RFOR(i, 0, SZ(order)) {
      int idx = order[i];
      REP(j, SZ(G[idx])) {
         edge e = G[idx][j];
         if (d[e.from] == d[e.to] + e.cost) {
            n2[e.to] = mod(n2[e.to] + n2[e.from]);
         }
      }
   }

   int ans = n1[T] * n2[S];
   REP(i, N) {
      if (2 * d[i] == d[T]) {
         ans = mod(ans - mod(mod(n1[i]*n2[i]) * mod(n1[i]*n2[i])));
      }
   }

   REP(i, N) {
      REP(j, SZ(G[i])) {
         edge e = G[i][j];
         if (d[e.from] + e.cost == d[e.to] && 2 * d[e.from] < d[T] && 2 * d[e.to] > d[T]) {
            ans = mod(ans - mod(mod(n1[e.from]*n2[e.to]) * mod(n1[e.from]*n2[e.to])));
         }
      }
   }
   cout << ans << endl;

   return 0;
}
