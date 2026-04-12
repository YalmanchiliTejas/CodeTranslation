#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<pair<long long, long long> > > adj;
vector<long long> dist1, np1, dist2, np2;
long long n, m;

ll MOD = ((ll)(1e9+7));

void dijk(long long u, vector<long long> &d) {
  priority_queue<pair<long long, long long> > pq;
  pq.push(make_pair(0, u));

  while(!pq.empty()) {
    pair<long long, long long> curr = pq.top(); pq.pop();
    curr.first *= -1;
    if(d[curr.second] <= curr.first) continue;
    d[curr.second] = curr.first;
    for(long long i = 0; i<adj[curr.second].size(); ++i) {
      pair<long long, long long> p = adj[curr.second][i];
      if(d[p.first] <= d[curr.second]+p.second) continue;
      pq.push(make_pair(-(d[curr.second]+p.second), p.first));
    }
  }
}

void di2(long long u, vector<long long> &d, vector<ll> &np) {
  priority_queue<pair<ll, ll> > pq;
  for(ll i = 0; i<d.size(); ++i) {
    pq.push(make_pair(-d[i], i));
  }
  while(!pq.empty()) {
    ll curr = pq.top().second; pq.pop();
    for(ll i = 0; i<adj[curr].size(); ++i) {
      pair<ll, ll> p = adj[curr][i];
      if(d[p.first] == d[curr]+p.second) np[p.first] = (np[curr] + np[p.first]) % MOD;
    }
  }
}


typedef pair<ll, ll> P;

vector<bool> processed;

void dfs(long long curr, vector<long long> &d, vector<long long> &np) {
  processed[curr] = true;
  for(long long i = 0; i<adj[curr].size(); ++i) {
    pair<ll, ll> p = adj[curr][i];
    if(!processed[p.first]) {
      dfs(p.first, d, np);
    }
  }
}

int main() {
  cin >> n >> m;
  long long s, t; cin >> s >> t;
  s--; t--;

  adj.resize(n);
  dist1.assign(n, 1e17);
  dist2.assign(n, 1e17);
  np1.assign(n, 0);
  np2.assign(n, 0);
  vector<pair<pair<ll, ll>, ll> > edges;
  for(long long i = 0; i<m; ++i) {
    long long u, v, d; cin >> u >> v >> d;
    u--; v--;
    adj[u].push_back(make_pair(v, d));
    adj[v].push_back(make_pair(u, d));
    edges.push_back(make_pair(make_pair(u, v), d));
  }

  np1[s] = 1;
  dijk(s, dist1);
  di2(s, dist1, np1);

  np2[t] = 1;
  dijk(t, dist2);
  di2(t, dist2, np2);

  ll rc1, rc2;
  {
    vector<ll> ds(n), ws(n), dt(n), wt(n);
    for(int i=0;i<n;i++) ds[i]=dist1[i];
    for(int i=0;i<n;i++) ws[i]=np1[i];
    for(int i=0;i<n;i++) dt[i]=dist2[i];
    for(int i=0;i<n;i++) wt[i]=np2[i];
    ll ret=ws[t]*ws[t]%MOD;
    rc1 = ret;
    ll mn=ds[t];
    for(int i=0;i<n;i++)
    {
      if(mn==ds[i]+dt[i]&&ds[i]==dt[i])
      {
        ret-=(ws[i]*ws[i]%MOD)*(wt[i]*wt[i]%MOD)%MOD;
        if(ret<0) ret+=MOD;
      }
    }
    rc2 = ret;
    //printf("%lld : %lld\n",mn,ret);
    for(int i=0;i<m;i++)
    {
      ll u = edges[i].first.first;
      ll v = edges[i].first.second;
      ll d = edges[i].second;
      if(ds[u]>ds[v]) swap(u,v);//ds[u]<ds[v]
      if(ds[u]+d+dt[v]==mn)
      {
        ll a=ds[u],b=ds[u]+d;
        ll c=dt[v],d=dt[v]+d;
        if(max(a,c)<min(b,d))
        {
          ret-=(ws[u]*ws[u]%MOD)*(wt[v]*wt[v]%MOD)%MOD;
          if(ret<0) ret+=MOD;
        }
      }
    }
  }

  ll ret = np1[t]*np1[t] % MOD;
  assert(ret == rc1);
  for(ll i = 0; i<n; ++i) {
    if(dist1[i] == dist2[i] && dist1[i]+dist2[i] == dist1[t]) {
      //ret -= ((np1[i] * np1[i])%MOD * (np2[i] * np2[i])%MOD) % MOD;
      //ret = (ret%MOD + MOD) % MOD;
      ret-=(np1[i]*np1[i]%MOD)*(np2[i]*np2[i]%MOD)%MOD;
      if(ret<0) ret+=MOD;
    }
  }
  assert(rc2 == ret);
  for(ll i = 0; i<m; ++i) {
    ll u = edges[i].first.first;
    ll v = edges[i].first.second;
    ll d = edges[i].second;
    if(dist1[u] > dist1[v]) swap(u, v);
    if(dist1[u] + dist2[v] + d == dist1[t]) {
      if(max(dist1[u], dist2[v]) < min(dist1[u]+d, dist2[v]+d)) {
        assert(np1[u] <= MOD);
        //ret -= ((np1[u] * np1[u])%MOD * (np2[v] * np2[v])%MOD) % MOD;
        ret -= ((np1[u] * np1[u]%MOD)%MOD * (np2[v] * np2[v]%MOD)%MOD) % MOD;
        //ret = (ret%MOD + MOD) % MOD;
        //ret-=(np1[u]*np1[u]%MOD)*(np2[v]*np2[v]%MOD)%MOD;
        if(ret<0) ret+=MOD;
      }
    }
  }
 // assert(ret >= 0);
  cout << (ret) % MOD << endl;
}
