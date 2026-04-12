#include <bits/stdc++.h>
using namespace std;
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 112000000012345678LL

template<int mod=1000000007>
class ModInt {
  int x;
public:
  ModInt() : x(0){}
  ModInt(int64_t y){ x = y % mod; if(x < 0) x += mod; }
  ModInt &operator += (const ModInt &p){ x += p.x; if(x >= mod) x -= mod; return *this; }
  ModInt &operator -= (const ModInt &p){ x -= p.x; if(x < 0) x += mod; return *this; }
  ModInt &operator *= (const ModInt &p){ x = (int) (1LL * x * p.x % mod); return *this; }
  ModInt &operator /= (const ModInt &p){ *this *= p.inverse(); return *this; }
  ModInt &operator += (const int64_t y){ x = (x + y)%mod; if(x < 0) x += mod; return *this; }
  ModInt &operator -= (const int64_t y){ x = (x - y)%mod; if(x < 0) x += mod; return *this; }
  ModInt &operator *= (const int64_t y){ x = (int) (x * y % mod); return *this; }
  ModInt &operator /= (const int64_t y){ *this *= ModInt(y).inverse(); return *this; }
  ModInt operator -() const { return ModInt(-x); }
  ModInt operator + (const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator - (const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator * (const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator / (const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator == (const ModInt &p) const { return x == p.x; }
  bool operator != (const ModInt &p) const { return x != p.x; }
  ModInt operator + (const int64_t y) const { return ModInt(*this) += y; }
  ModInt operator - (const int64_t y) const { return ModInt(*this) -= y; }
  ModInt operator * (const int64_t y) const { return ModInt(*this) *= y; }
  ModInt operator / (const int64_t y) const { return ModInt(*this) /= y; }
  bool operator == (const int64_t y) const { return x == (mod + y%mod)%mod; }
  bool operator != (const int64_t y) const { return x != (mod + y%mod)%mod; }
  ModInt operator = (const int64_t y) { return *this = ModInt(y); }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0){
      t = a/b; a -= t*b; swap(a, b);
      u -= t*v; swap(u, v);
    }
    return ModInt(u);
  }
  friend ostream &operator << (ostream &os, const ModInt<mod> &p) { return os<<p.x; }
  friend istream &operator >> (istream &is, ModInt<mod> &a) { int64_t x; is>>x; a = ModInt<mod>(x); return is; }
};
using Int = ModInt<>;


vector<pair<long,Int>> dijkstra(const vector<vector<pair<int,long>>> &vec, int from){
  using P = pair<long,int>;
  vector<pair<long,Int>> d(vec.size(), {INF, 0});
  priority_queue<P, vector<P>, greater<P>> pq;
  d[from] = {0, 1};
  pq.push(mp(0,from));
  while(!pq.empty()){
    auto p = pq.top(); pq.pop();
    int v = p.second;
    long dd = p.first;
    if(d[v].first < dd) continue;
    for(auto to : vec[v]){
      long nd = dd + to.second;
      int ni = to.first;
      if(d[ni].fi > nd){
        d[ni] = {nd, d[v].second};
        pq.push({nd, ni});
      } else if(d[ni].fi == nd){
        d[ni].second += d[v].second;
      }
    }
  }
  return d;
}

int main(){
  int n,m;
  cin>>n>>m;
  int s,t;
  cin>>s>>t;
  s--;t--;
  vector<vector<pair<int,long>>> g(n);
  vector<int> x(m),y(m),z(m);
  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    g[a].pb({b,c});
    g[b].pb({a,c});
    x[i] = a;
    y[i] = b;
    z[i] = c;
  }

  auto ds = dijkstra(g, s);
  auto dt = dijkstra(g, t);

  Int ans = ds[t].se * dt[s].se;
  assert(ds[t] == dt[s]);

  vector<bool> good(n, false);
  rep(i,n){
    if(ds[i].fi + dt[i].fi == ds[t].fi){
      good[i] = true;
      if(ds[i].fi == dt[i].fi){
        Int tmp = ds[i].se * dt[i].se;
        ans -= tmp * tmp;
      }
    }
  }

  rep(i,m) if(good[x[i]] && good[y[i]]){
    int u = x[i], v = y[i];
    if( max(min(ds[u].fi, ds[v].fi), min(dt[u].fi, dt[v].fi)) >= min(max(ds[u].fi, ds[v].fi), max(dt[u].fi, dt[v].fi)) ) continue;
    if(min(ds[u].fi, dt[u].fi) + min(ds[v].fi, dt[v].fi) + z[i] != ds[t].fi) continue;
    Int tmp;
    if (ds[u].fi < ds[v].fi){
      // s - u - v - t
      tmp = ds[u].se * dt[v].se;
    } else {
      // s - v - u - t
      tmp = ds[v].se * dt[u].se;
    }
    ans -= tmp * tmp;
  }

  cout << ans << endl;

  return 0;
}
