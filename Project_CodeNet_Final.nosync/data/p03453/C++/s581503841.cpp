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
#define MOD 1000000007

vector<pair<long,long>> dijkstra(const vector<vector<pair<int,long>>> &vec, int from){
  using P = pair<long,int>;
  vector<pair<long,long>> d(vec.size(), {INF, 0});
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
        d[ni].second %= MOD;
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

  long ans = (ds[t].se * dt[s].se) %MOD;
  assert(ds[t] == dt[s]);

  vector<bool> good(n, false);
  rep(i,n){
    if(ds[i].fi + dt[i].fi == ds[t].fi){
      good[i] = true;
      if(ds[i].fi == dt[i].fi){
        long tmp = (ds[i].se * dt[i].se) %MOD;
        ans -= (tmp * tmp) %MOD;
        ans = (ans + MOD) %MOD;
      }
    }
  }

  rep(i,m) if(good[x[i]] && good[y[i]]){
    int u = x[i], v = y[i];
    if( max(min(ds[u].fi, ds[v].fi), min(dt[u].fi, dt[v].fi)) >= min(max(ds[u].fi, ds[v].fi), max(dt[u].fi, dt[v].fi)) ) continue;
    if(min(ds[u].fi, dt[u].fi) + min(ds[v].fi, dt[v].fi) + z[i] != ds[t].fi) continue;
    long tmp;
    if (ds[u].fi < ds[v].fi){
      // s - u - v - t
      tmp = (ds[u].se * dt[v].se) %MOD;
    } else {
      // s - v - u - t
      tmp =  (ds[v].se * dt[u].se) %MOD;
    }
    ans -= (tmp * tmp) %MOD;
    ans = (ans + MOD) %MOD;
  }

  cout << ans << endl;

  return 0;
}
