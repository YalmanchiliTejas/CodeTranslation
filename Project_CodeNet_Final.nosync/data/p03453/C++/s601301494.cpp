// includes
#include <bits/stdc++.h>

// macros
#define ll long long int
#define pb emplace_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(st, itr) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define vrep(v, i) for(int i = 0; i < (v).size(); i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define FI first
#define SE second
#define dump(a, n) for(int i = 0; i < n; i++)cout << a[i] << "\n "[i + 1 != n];
#define dump2(a, n, m) for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)cout << a[i][j] << "\n "[j + 1 != m];
using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef complex<double> cd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}

template <typename T>
struct Graph_ {
  int n;
  vector<vector<pair<int, T> > > edge;
  vector<T> dis;
  vector<ll> pp;
  Graph_(int ns) {
    n = ns;
    edge.resize(n);
    dis.resize(n);
    pp.resize(n);
  }
  void dijkstra(int s){
    dijkstra(s, 0);
  }
  T dijkstra(int s, int t){
    // initialize
    fill(dis.begin(), dis.end(), -1);
    fill(pp.begin(), pp.end(), 0);
    vector<bool> used;
    used.resize(n);
    fill(used.begin(), used.end(), false);
    dis[s] = 0;
    pp[s] = 1;
    // dijkstra
    priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > q;
    q.push(make_pair(0, s));
    while(!q.empty()){
      pair<T, int> p = q.top(); q.pop();
      int at = p.second;
      T distance = p.first;
      if(used[at])continue;
      used[at] = true;
      for(auto itr = edge[at].begin(); itr != edge[at].end(); ++itr){
        int to = itr->first;
        T cost = itr->second;
        if(used[to] && cost + dis[to] == dis[at]){
          pp[at] = (pp[at] + pp[to]) % mod;
        }
      }
      for(auto itr = edge[at].begin(); itr != edge[at].end(); ++itr){
        int to = (*itr).first;
        T cost = (*itr).second;
        if(used[to])continue;
        if(dis[to] == -1 || dis[to] > distance + cost){
          q.push(make_pair(distance + cost, to));
          dis[to] = distance + cost;
        }
      }
    }
    return dis[t];
  }
  void adde(int at, int to, T cost){
    edge[at].push_back(make_pair(to, cost));
  }
  [[deprecated("This function takes O(edge[at].size()).")]]
    void remove(int at, int to){
      int index = -1;
      for(int i = 0; i < edge[at].size(); i++){
        if(edge[at][i].first == to){
          index = i;
          break;
        }
      }
      edge[at].erase(edge[at].begin() + index);
    }
};

typedef struct Graph_<int> GraphI;
typedef struct Graph_<ll> GraphL;
typedef struct Graph_<double> GraphD;

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int s, t;
  cin >> s >> t, s--, t--;
  GraphL graph(n);
  vector<int> U(m), V(m);
  vector<ll> D(m);
  rep(i, m){
    int u, v;
    ll d;
    cin >> u >> v >> d, u--, v--;
    U[i] = u, V[i] = v, D[i] = d;
    graph.adde(u, v, d);
    graph.adde(v, u, d);
  }
  graph.dijkstra(s);
  vector<ll> ds(n), ps(n);
  copy(graph.dis.begin(), graph.dis.end(), ds.begin());
  copy(graph.pp.begin(), graph.pp.end(), ps.begin());
  graph.dijkstra(t);
  vector<ll> dt(n), pt(n);
  copy(graph.dis.begin(), graph.dis.end(), dt.begin());
  copy(graph.pp.begin(), graph.pp.end(), pt.begin());
  assert(ds[t] == dt[s]);
  assert(ps[t] == pt[s]);
  ll res = ps[t] * pt[s] % mod;
  for(int i = 0; i < m; i++){
    if(ds[U[i]] + D[i] + dt[V[i]] == ds[t]){
      bool b = true;
      if(!(2 * ds[U[i]] < ds[t] && ds[t] < 2 * ds[V[i]]))b = false;
      if(!(2 * dt[V[i]] < ds[t] && ds[t] < 2 * dt[U[i]]))b = false;
      if(b){
        ll tmp = ps[U[i]] * pt[V[i]] % mod;
        tmp = tmp * tmp % mod;
        res = (res - tmp) % mod;
        if(res < 0)res += mod;
      }
    }
    if(ds[V[i]] + D[i] + dt[U[i]] == ds[t]){
      bool b = true;
      if(!(2 * ds[V[i]] < ds[t] && ds[t] < 2 * ds[U[i]]))b = false;
      if(!(2 * dt[U[i]] < ds[t] && ds[t] < 2 * dt[V[i]]))b = false;
      if(b){
        ll tmp = ps[V[i]] * pt[U[i]] % mod;
        tmp = tmp * tmp % mod;
        res = (res - tmp) % mod;
        if(res < 0)res += mod;
      }
    }
  }
  for(int i = 0; i < n; i++){
    if(ds[i] + dt[i] == ds[t] && ds[i] == dt[i]){
      ll tmp = ps[i] * pt[i] % mod;
      tmp = tmp * tmp % mod;
      res = (res - tmp) % mod;
      if(res < 0 )res += mod;
    }
  }
  cout << res << endl;
  return 0;
}
