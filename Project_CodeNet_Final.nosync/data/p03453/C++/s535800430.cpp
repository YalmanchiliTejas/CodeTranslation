#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

const int mod = 1000000007;
struct mint {
  ll x;  // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if(!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if(t & 1) a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
mint fact(int n) {
  if(n == 1 || n == 0) return 1;
  mint res = n;
  return res * fact(n - 1);
}

struct Edge {
  ll to;
  ll cost;
};
using Graph = vector<vector<Edge>>;
const long long INF = 1LL << 60;
/* dijkstra(G,s,dis,prev)
  入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
  計算量：O(|E|log|V|)
  副作用：dis, prevが書き換えられる
*/
void dijkstra(const Graph& G, int s, vl& dis, vi& prev, vector<mint>& num) {
  int N = G.size();
  dis.resize(N, INF);
  prev.resize(N, -1);  // 初期化
  num.resize(N, 0);
  num[s] = 1;
  priority_queue<P, vector<P>, greater<P>>
      pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while(!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if(dis[v] < p.first) {  // 最短距離で無ければ無視
      continue;
    }
    for(auto& e : G[v]) {
      if(dis[e.to] > dis[v] + e.cost) {
        dis[e.to] = dis[v] + e.cost;
        prev[e.to] = v;  // 頂点 v を通って e.to にたどり着いた
        num[e.to] = num[v];
        pq.emplace(dis[e.to], e.to);
      } else if(dis[e.to] == dis[v] + e.cost)
        num[e.to] += num[v];
    }
  }
}

int main() {
  ll n, m, s, t;
  cin >> n >> m >> s >> t;
  s--;
  t--;
  Graph g(n);
  rep(i, m) {
    ll u, v, d;
    cin >> u >> v >> d;
    u--;
    v--;
    Edge e;
    e.to = v;
    e.cost = d;
    g[u].push_back(e);
    e.to = u;
    g[v].push_back(e);
  }
  vl ds, dt;
  vi prev;
  vector<mint> ns, nt;
  dijkstra(g, s, ds, prev, ns);
  dijkstra(g, t, dt, prev, nt);
  ll d = ds[t];
  mint ans = ns[t] * ns[t];
  rep(i, n) if(ds[i] * 2 == d && dt[i] * 2 == d) ans -=
      ns[i] * nt[i] * ns[i] * nt[i];
  rep(i, n) for(auto e : g[i]) {
    ll j = e.to;
    ll c = e.cost;
    if(ds[i] * 2 < d && ds[j] * 2 > d && ds[i] + dt[j] + c == d)
      ans -= (ns[i] * nt[j] * ns[i] * nt[j]);
  }
  cout << ans << endl;
}