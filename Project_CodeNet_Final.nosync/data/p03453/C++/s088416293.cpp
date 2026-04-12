#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll N = (ll)2e5 + 9;
const ll MOD = (ll)1e9 + 7;
const ll inf = (ll)1e15;
vector<pii> T[N];
vector<ll> Q[N];
vector<ll> R[N];
ll dis[N];
ll drv[N];
ll u[N];
ll v[N];
ll w[N];
ll cc[N];
ll dd[N];
ll deg[N];
bool had[N];

void add(ll &a, ll b){  
  a += b;
  if(a >= MOD) a -= MOD;
  else if(a < 0) a += MOD;
}

bool llersect(ll li, ll ri, ll lp, ll rp){
  if(rp <= li || lp >= ri) return false;
  return true;
}

int main(){
  fastIO;
  ll n, m, s, t;
  cin >> n >> m >> s >> t;
  for(ll i = 0 ; i < m ; i ++ ){
    cin >> u[i] >> v[i] >> w[i];
    T[u[i]].push_back(mp(v[i],w[i]));
    T[v[i]].push_back(mp(u[i],w[i]));
  }
  for(ll i = 1; i <= n; i ++ )
    dis[i] = inf;
  priority_queue<pii,vector<pii>,greater<pii>> pq;
  pq.push(mp(0,s));
  dis[s] = 0;
  ll node;
  ll dr;
  while(!pq.empty()){
    node = pq.top().se;
    dr = pq.top().fi;
    pq.pop();
    if(dr != dis[node]) continue;
    for(auto x : T[node]){
      if(dr + x.se < dis[x.fi]){
        dis[x.fi] = dr + x.se;
        pq.push(mp(dis[x.fi], x.fi));
      }
    }
  }
  queue<ll> rv;
  rv.push(t);
  had[t] = true;
  while(!rv.empty()){
    node = rv.front();
    rv.pop();
    for(auto x : T[node]){
      if(dis[x.fi] + x.se == dis[node]){
        deg[node] ++ ;
        Q[x.fi].push_back(node);
        R[node].push_back(x.fi);
        if(had[x.fi] == false){
          had[x.fi] = true;
          rv.push(x.fi);
        }
      }
    }
  }
  rv.push(s);
  cc[s] = 1;
  while(!rv.empty()){
    node = rv.front();
    rv.pop();
    for(auto x : Q[node]){
      if(had[x]){
        cc[x] = (cc[x] + cc[node]) % MOD;
        deg[x] -- ;
        if(deg[x] == 0) 
          rv.push(x);
      }
    }
  }
  ll ans = (cc[t] * 1ll * cc[t]) % MOD;
  rv.push(t);
  dd[t] = 1;
  for(ll i = 1; i <= n; i ++ ) deg[i] = 0;
  for(ll i = 1; i <= n; i ++ ){
    for(auto x : R[i]) deg[x] ++ ;
  }
  while(!rv.empty()){
    node = rv.front();
    rv.pop();
    for(auto x : R[node]){
      if(had[x]){
        dd[x] = (dd[x] + dd[node]) % MOD;
        deg[x] -- ;
        if(deg[x] == 0)
          rv.push(x);
      }
    }
  }
  ll ff = dis[t];
  ll uy;
  for(ll i = 1; i <= n; i ++ ){
    if(had[i] && dis[i] * 2ll == ff){
      uy = (cc[i] * 1ll * dd[i]) % MOD;
      uy = (uy * 1ll * uy) % MOD;
      add(ans, -uy);
    }
  }
  ll li, ri;
  ll lq, rq;
  for(ll i = 0 ; i < m ; i ++ ){
    if(dis[u[i]] > dis[v[i]]) swap(u[i], v[i]);
    if(dis[v[i]] != dis[u[i]] + w[i]) continue; // irrelevent
    li = dis[u[i]];
    ri = dis[v[i]];
    lq = ff - dis[v[i]];
    rq = lq + w[i];
    if(llersect(li,ri,lq,rq)){
      uy = (dd[v[i]] * 1ll * cc[u[i]]) % MOD;
      uy = (uy * 1ll * uy) % MOD;
      add(ans, -uy);
    }
  }
  cout << ans << "\n";
  return 0;
}