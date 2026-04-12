#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define len(val) static_cast<ll>(val.size())
#define rep(i, n) for(ll i=0; i<(n); i++)

const ll MAXN = 4000;
const ll MAXM = 400000;
const ll INF = 1e18;
ll N, M;

struct UnionFind
{
    std::vector<ll> data;
    UnionFind(ll size) : data(size, -1){}
    void initialize(void){
        for(ll i=0; i<(ll)data.size(); i++) data[i] = i;
    }
    bool merge(ll x, ll y){
        x = find(x); y = find(y);
        if(x == y) return false;
        else{ data[x] = y; return true; }
    }
    ll find(ll x){ //根っこを見つける関数
        if(data[x] == x) return x;
        else return data[x] = find(data[x]); //経路圧縮
    }
    bool isSame(ll x, ll y){
        return find(x) == find(y);
    }
};

struct edge{
  ll u, v, cost;
};

bool comp(const edge& r, const edge& l){
  return r.cost < l.cost;
}

edge es[MAXM];
ll mx[MAXN][MAXN];
bool visited[MAXN];
vector<P> G[MAXN];

void dfs(ll v, ll p, ll m = -1)
{
  if(visited[v]) return;
  mx[p][v] = m;
  visited[v] = true;
  for(auto a : G[v]){
    dfs(a.first, p, max(m, a.second));
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  rep(i, M){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    es[i] = edge{a, b, c};
  }
  ll sum = 0;
  {
    sort(es, es+M, comp);
    UnionFind uf(N);
    uf.initialize();
    ll cnt = 0;
    rep(i, M){
      edge& e = es[i];
      if(!uf.isSame(e.u, e.v)){
        uf.merge(e.u, e.v);
        es[cnt] = edge{e.u, e.v, e.cost};
        cnt++;
        sum += e.cost;
        G[e.u].push_back(make_pair(e.v, e.cost));
        G[e.v].push_back(make_pair(e.u, e.cost));
      }
    }
  }
  for(int i=0; i<N; i++){
    memset(visited, false, sizeof(visited));
    dfs(i, i);
  }

  ll Q;
  cin >> Q;
  rep(q, Q){
    ll s, t;
    cin >> s >> t;
    s--; t--;
    cout << sum-mx[s][t] << endl;
  }
}
