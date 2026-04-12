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
#define irep(itr, st) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define vrep(v, i) for(int i = 0; i < (v).size(); i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define FI first
#define SE second
#define dump(a, n) for(int i = 0; i < n; i++)cout << a[i] << "\n "[i + 1 != n];
#define dump2(a, n, m) for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)cout << a[i][j] << "\n "[j + 1 != m];
#define bit(n) (1LL<<(n))
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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

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

typedef struct UnionFind_ {
  vector<int> par;
  vector<int> rank_;
  UnionFind_(int n): rank_(n, 0) {
    for(int i = 0; i < n; i++)par.push_back(i);
  }
  int find(int x) {
    if(par[x] == x)return x;
    else return par[x] = find(par[x]);
  }
  bool same(int x, int y) {
    if(find(x) == find(y))return true;
    else return false;
  }
  bool unite(int x, int y){
    int xp = find(x);
    int yp = find(y);
    if(xp == yp)return false;
    if(rank_[xp] > rank_[yp])par[yp] = xp;
    else if(rank_[xp] < rank_[yp])par[xp] = yp;
    else {
      par[yp] = xp;
      rank_[xp]++;
    }
    return true;
  }
} UnionFind;

template <typename T>
struct edge{
  int from;
  int to;
  T cost;
};

template <typename T>
bool comp(const edge<T> &a, const edge<T> &b){
  return a.cost < b.cost;
}

template <typename T>
struct Graph {
  int n;
  vector<edge<T>> es;
  vector<vector<pair<int, ll>>> vv; 
  Graph(int n_){
    n = n_;
    vv.resize(n);
  }
  void adde(int from, int to, T cost){
    es.push_back((edge<T>){from, to, cost});
  }
  T kruskal(){
    T res = 0;
    UnionFind uf(n);
    sort(es.begin(), es.end(), comp<T>);
    for(auto e: es){
      int from = e.from;
      int to = e.to;
      T cost = e.cost;
      if(uf.same(from, to))continue;
      vv[from].pb(mk(to, cost));
      vv[to].pb(mk(from, cost));
      res += cost;
      uf.unite(from, to);
    }

    return res;
  }
};

using GraphI = Graph<int>;
using GraphL = Graph<ll>;

ll mini[4001][4001];
bool vis[4001];
ll maxi = 0;
int at = 0;
vector<vector<pair<int, ll>>> vv;

void dfs(int i){
  vis[i] = true;
  ll tmp = maxi;
  for(auto e: vv[i]){
    if(vis[e.FI])continue;
    maxi = max(maxi, e.SE);
    mini[at][e.FI] = maxi;
    dfs(e.FI);
    maxi = tmp;
  }
}

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  GraphL graph(n);
  rep(i, m){
    int a, b;
    ll c;
    cin >> a >> b >> c, a--, b--;
    graph.adde(a, b, c);
    graph.adde(b, a, c);
  }
  ll res = graph.kruskal();
  vv = graph.vv;
  rep(i, n){
    fill(vis, vis + n, false);
    at = i;
    maxi = 0;
    dfs(i);
  }
  int q;
  cin >> q;
  rep(i, q){
    int s, t;
    cin >> s >> t, s--, t--;
    cout << res - mini[s][t] << endl;
  }
  return 0;
}

