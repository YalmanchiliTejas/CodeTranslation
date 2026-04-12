#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value

//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

// Mod int
const int mod = 1000000007;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
typedef vector<vm> vvm;
//


struct edge{
  ll to, cost;
  edge(ll to, ll cost): to(to), cost(cost){}
};

vector<ll> dijkstra(int from, int v_num, vector<vector<edge>> & graph){
  ll INF = 1e15;
  VLL d(v_num,INF);
  d[from] = 0;

  priority_queue<PLL,vector<PLL>,greater<PLL>> que;
  que.push(PLL(0,from));

  while(que.empty() == false){
    PLL p = que.top();
    que.pop();
    ll node = p.second;
    if(d[node] < p.first)  continue;
    for(auto e: graph[node]){
      if(d[e.to] > d[node] + e.cost){
        d[e.to] = d[node] + e.cost;
        que.push(PLL(d[e.to],e.to));
      }
    }
  }
  return d;
}

vector<mint> makeDag(int x, VLL& dist, vector<vector<edge>> &edges){
  vector<PLL> vec;
  rep(i,dist.size()) vec.push_back(PLL(dist[i],i));
  sort(all(vec));

  vector<mint> dp(dist.size(),0);
  dp[x] = 1;
  rep(i,dist.size()){
    for( edge e : edges[vec[i].second]){
      if(dist[e.to] == dist[vec[i].second] + e.cost)
        dp[e.to] += dp[vec[i].second];
    }
  }
  return dp;
}

vector<mint> makeDag2(int x, VLL& dist, vector<vector<edge>> &edges){
  vector<PLL> vec;
  rep(i,dist.size()) vec.push_back(PLL(dist[i],i));
  sort(all(vec));

  vector<mint> dp(dist.size(),0);
  dp[x] = 1;
  int n= dist.size();
  for(int i=n-1; i>=0; --i) {
    for(edge e : edges[vec[i].second]) {
      if(dist[vec[i].second] == dist[e.to] + e.cost) {
        dp[e.to] += dp[vec[i].second];
      }
    }
  }
  return dp;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  int s,t;
  cin >> s >> t; s--, t--;
  vector<vector<edge>> edges(n);
  rep(i,m){
    int u,v,d;
    cin >> u >> v >> d;
    u--, v--;
    edges[u].push_back(edge(v,d));
    edges[v].push_back(edge(u,d));
  }
  // 最短経路を求める
  vector<ll> s_to_t = dijkstra(s,n,edges);
  vector<ll> t_to_s = dijkstra(t,n,edges);

  // make DAG dist[j] <  dist[i] + cost and calc roots
  vector<mint> dp_st = makeDag(s, s_to_t, edges);
  vector<mint> dp_ts = makeDag2(t, s_to_t, edges);

  // 経路数
  mint ans = dp_st[t] * dp_ts[s];

  rep(i, n) {
    if(s_to_t[i]*2 == s_to_t[t]) {
      ans -= dp_st[i] *  dp_st[i] * dp_ts[i] * dp_ts[i];
    }
  }

  rep(i, n) {
    for(edge e : edges[i]){
      int u = i;
      int v = e.to;
      if(s_to_t[u] > s_to_t[v]) continue;
      if(2*s_to_t[u] < s_to_t[t] && 2*s_to_t[v] > s_to_t[t] && s_to_t[u] + e.cost == s_to_t[v] ) {
        //cout << "("<<  u << "," << v << ")" << "minus" << dp_st[u]*dp_st[u]*dp_ts[v]*dp_ts[v] << endl;
        ans -= dp_st[u]*dp_st[u]*dp_ts[v]*dp_ts[v];
      }
    }
  }
  cout << ans << endl;

  return 0;
}
