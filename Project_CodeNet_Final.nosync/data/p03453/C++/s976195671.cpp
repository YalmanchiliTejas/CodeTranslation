#include "bits/stdc++.h"

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i, x, n) for(int i = x; i >= n; i--)
#define rrep(i, n) RREP(i,n,0)
#define pb push_back
#pragma GCC optimize ("-O3")

using namespace std;

#define DEBUG_IS_VALID

#ifdef DEBUG_IS_VALID
#define DEB 1 
#else
#define DEB 0
#endif
#define DUMPOUT cout
#define dump(...) if(DEB) DUMPOUT<<"  "<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl<<"    "; if(DEB) dump_func(__VA_ARGS__)
template<typename T1,typename T2>ostream& operator << (ostream& os, pair<T1,T2> p){cout << "(" << p.first << ", " << p.second << ")"; return os;}
template<typename T>ostream& operator << (ostream& os, vector<T>& vec) { os << "{"; for (int i = 0; i<vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : ", "); os << "}"; return os; }
template<typename T>ostream& operator << (ostream& os, set<T>& st){for(auto itr = st.begin(); itr != st.end(); itr++) cout << *itr << (next(itr)!=st.end() ? ", " : ""); cout << "}"; return os;}
template<typename T1,typename T2>ostream& operator << (ostream& os, map<T1,T2> mp){cout << "{"; for(auto itr = mp.begin(); itr != mp.end(); itr++) cout << "(" << (itr->first) << ", " << (itr->second) << ")" << (next(itr)!=mp.end() ? "," : ""); cout << "}"; return os; }

void dump_func(){DUMPOUT << endl;}
template <class Head, class... Tail>void dump_func(Head&& head, Tail&&... tail){ DUMPOUT << head; if (sizeof...(Tail) == 0) { DUMPOUT << " "; } else { DUMPOUT << ", "; } dump_func(std::move(tail)...);}
template<class T> inline bool chmax(T& a,T const& b){if(a>=b) return false; a=b; return true;}
template<class T> inline bool chmin(T& a,T const& b){if(a<=b) return false; a=b; return true;}

using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

const int mod=1e9+7,INF=1<<29;
const double EPS=1e-12,PI=3.1415926535897932384626;
const ll lmod = 1e9+7,LINF=1LL<<59; 

template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }
template<typename T, int FAC_MAX> struct Comb { vector<T> fac, ifac;
    Comb(){fac.resize(FAC_MAX,1);ifac.resize(FAC_MAX,1); for(int i = 1; i < FAC_MAX; i++)fac[i]=fac[i-1]*i;
        ifac[FAC_MAX-1]=T(1)/fac[FAC_MAX-1];for(int i = FAC_MAX-2; i >= 1; i--)ifac[i]=ifac[i+1]*T(i+1);}
    T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
    T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
    T nHk(int n, int k) { if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k); }}; // nHk = (n+k-1)Ck : n is separator
using mint = ModInt<1000000007>;

template<typename T> T inf;
template<> constexpr int inf<int> = 1<<30;
template<> constexpr ll inf<ll> = 1LL<<60;
template<> constexpr double inf<double> = 1e30;

using Cost = ll;
using Node = int;
struct Edge{
  Cost cost; Node to;
  Edge(Cost cost,Node to)
    :cost(cost),to(to){}
};
using Graph = vector<vector<Edge>>;

vector<Cost> dijkstra
(Graph &graph, Node start,vector<mint>& dp, Cost zero = 0LL)
{
  using Pcn = pair<Cost,Node>;
  priority_queue<Pcn,vector<Pcn>,greater<Pcn>> que;
  vector<Cost> dist(graph.size(),inf<Cost>);
  dist[start] = zero;
  dp[start] = 1;
  que.push(Pcn(zero,start));
  while(!que.empty()){
    Pcn p = que.top(); que.pop();
    Node v = p.second; //行き先
    if(dist[v] < p.first)  continue;
    for(Edge e : graph[v]){
      if(dist[v]+e.cost == dist[e.to]){
        dp[e.to] += dp[v];
      }if(dist[v]+e.cost < dist[e.to]){
        dist[e.to] = dist[v]+e.cost;
        dp[e.to] = dp[v];
        que.push(Pcn(dist[e.to],e.to));
      }
    }
  }
  return dist;
}

void add_edge(Graph& g,Node a,Node b,Cost c){
  g[b].push_back(Edge(c,a));
  g[a].push_back(Edge(c,b));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N,M; cin >> N >> M ;
  int s,t; cin >> s >> t ;
  s--; t--;
  Graph g(N);
  rep(i,M){
    int u,v; ll d;
    cin >> u >> v >> d ;
    add_edge(g,u-1,v-1,d);
  }
  vector<mint> dp1(N),dp2(N);
  auto d1 = dijkstra(g,s,dp1);
  auto d2 = dijkstra(g,t,dp2);
  mint ans = 0;
  ll dd = d1[t];
  rep(i,N) if(d1[i]==d2[i] && d1[i]*2==dd) ans += dp1[i]*dp1[i]*dp2[i]*dp2[i];
  rep(u,N) for(auto e:g[u]){
    int v = e.to;
    // if(!(d1[v]==d1[u]+e.cost && d2[v]+e.cost==d2[u])) continue;
    if(e.cost+d1[u]+d2[v]==dd && 2LL*d1[u]<dd && 2LL*d2[v]<dd){
    // if(d1[u]<d2[v]+e.cost && d2[v]<d1[u]+e.cost){
      ans += dp1[u]*dp1[u]*dp2[v]*dp2[v];
    }
  }
  ans = dp1[t] * dp2[s] - ans;
  cout << ans << endl;
  return 0;
}
