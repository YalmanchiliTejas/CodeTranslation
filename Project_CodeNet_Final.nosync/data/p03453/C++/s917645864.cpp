#include <bits/stdc++.h>
using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);++i)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;i>=(int)(m);--i)
#define REP(i,n) rep(i,0,n)
#define REP2(i,n) rep2(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll) 1e9 + 7;
//constexpr long long MOD = 998244353LL;
using ld=long double;
static const ld pi = 3.141592653589793L;
typedef vector<ll> Array;
typedef vector<Array> Matrix;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

struct Edge {
	ll to, cap, rev, col;
	Edge(ll _to, ll _cap, ll _rev) {
	to = _to; cap = _cap; rev = _rev;
	}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

void Dijkstra(Graph& G, ll s, Array& d) {//O(|E|log|V|)
  d.resize(G.size());
  REP(i, d.size())d[i] = INF;
  d[s] = 0;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    P a = q.top();
    q.pop();
    if (d[a.second] < a.first)continue;
    REP(i, G[a.second].size()) {
      Edge e = G[a.second][i];
      if (d[e.to] > d[a.second] + e.cap) {
        d[e.to] = d[a.second] + e.cap;
        q.push(make_pair(d[e.to], e.to));
      }
    }
  }
}

bool tsort(Graph& graph, Array& order) { 
 int n = graph.size(), k = 0;
 Array in(n);
 for (auto& es : graph)
  for (auto& e : es)in[e.to]++;
 priority_queue<ll, Array, greater<ll>> que;
 REP(i, n)
  if (in[i] == 0)que.push(i);
 while (que.size()) {
  int v = que.top();
  que.pop();
  order.push_back(v);
  for (auto& e : graph[v])
   if (--in[e.to] == 0)que.push(e.to);
 }
 if (order.size() != n)return false;
 else return true;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    s--;t--;
    Graph g(n);
    REP(i,m){
        int u,v;
        ll d;
        cin>>u>>v>>d;
        u--;v--;
        add_edge(g,u,v,d,true,d);
    }

    Array d;
    Dijkstra(g,s,d);

    ll time=d[t];
    queue<int> que;
    que.push(t);
    Graph rg(n);//最短経路復元
    Array used(n,false);
    while(que.size()){
        int v=que.front();que.pop();
        for(auto e:g[v]){
            if(d[e.to]+e.cap==d[v]){
                add_edge(rg,e.to,v,e.cap,false,-1);
                if(used[e.to]) continue;
                used[e.to]=true;
                que.push(e.to);
            }
        }
    }

    Array order;
    tsort(rg,order);

    Array dp(n+1,0);
    dp[s]=1;

    for(auto v:order){
        for(auto e:rg[v]){
            (dp[e.to]+=dp[v])%=MOD;//経路数をカウント
        }
    }

    
    ll ans=dp[t]*dp[t]%MOD;

    Array dp2(n,-1);
    dp2[t]=1;
    auto dfs = [&](auto &&self, int v)->ll{
        if(dp2[v]!=-1) return dp2[v];
        ll ret=0;
        for(auto e:rg[v]){
            ll tmp = self(self,e.to);
            ret += tmp;
            ret %= MOD;
            tmp *= dp[v];
            tmp %= MOD;
            if(d[t]>d[v]*2 and d[t]<d[e.to]*2){
                (ans+=MOD - tmp*tmp%MOD)%=MOD;
            }
        }
        if(d[v]*2==d[t]){
            ans+=MOD-ret*ret%MOD*dp[v]%MOD*dp[v]%MOD;
            ans%=MOD;
        }
        return dp2[v]=ret;
    };
    dfs(dfs,s);

    cout<<ans%MOD<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	solve();
	//ll t;cin>>t;REP(i,t) solve();

    return 0;
}
