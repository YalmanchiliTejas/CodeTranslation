#define print(x) printf("%d\n",x)

typedef unsigned int uint;

typedef long long ll;

#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <set>

using namespace std;

int n;
int m;
int s;
int t;

vector<pair<int, ll> > d[100000];
const ll mod = 1000000007;

void f(int s, int t, vector<ll> &dist, vector<int> &path, vector<ll> &cnt){
  typedef pair<ll, int> data;

  {
    priority_queue<data, vector<data>, greater<data> > pq;
    pq.push(data(0, s));
    while(pq.size()){
      const data dd = pq.top(); pq.pop();
      const ll cost = dd.first;
      const int pos = dd.second;
      if(dist[pos] != -1) continue;
      dist[pos] = cost;
      for(const auto p : d[pos]){
        const int next = p.first;
        const ll cc = cost + p.second;
        if(dist[next] == -1) pq.push(data(cc, next));
      }
    }
  }

  {
    priority_queue<data> pq;
    cnt[t] = 1;
    pq.push(data(dist[t], t));
    while(pq.size()){
      const data dd = pq.top(); pq.pop();
      const int pos = dd.second;
      if(path[pos]) continue;
      path[pos] = 1;
      for(const auto p : d[pos]){
        const int next = p.first;
        const ll cc = p.second;
        if(dist[next] + cc == dist[pos]){
          cnt[next] = (cnt[next] + cnt[pos]) % mod;
          pq.push(data(dist[next], next));
        }
      }
    }
  }
}



int main(){
  n = getInt();
  m = getInt();
  s = getInt() - 1;
  t = getInt() - 1;

  REP(i,m){
    const int u = getInt() - 1;
    const int v = getInt() - 1;
    const int dd = getInt();
    d[u].push_back(make_pair(v, dd));
    d[v].push_back(make_pair(u, dd));
  }

  vector<ll> stdist(n, -1);
  vector<int> stpath(n, 0);
  vector<ll> stcnt(n, 0);

  vector<ll> tsdist(n, -1);
  vector<int> tspath(n, 0);
  vector<ll> tscnt(n, 0);

  f(s, t, stdist, stpath, stcnt);
  f(t, s, tsdist, tspath, tscnt);

  /*
  REP(i,n) printf("%2lld ", stdist[i]); puts("");
  REP(i,n) printf("%2d ", stpath[i]); puts("");
  REP(i,n) printf("%2lld ", stcnt[i]); puts("");
  puts("---");
  REP(i,n) printf("%2lld ", tsdist[i]); puts("");
  REP(i,n) printf("%2d ", tspath[i]); puts("");
  REP(i,n) printf("%2lld ", tscnt[i]); puts("");
  */


  ll ans = (stcnt[s] * tscnt[t]) % mod;
  // printf("%lld\n", ans);
  const ll dist = stdist[t];
  // if(stdist[t] != tsdist[s]) puts("bug");

  if(dist % 2 == 0){
    REP(i,n) if(stdist[i] == dist / 2){
      const ll c = (stcnt[i] * tscnt[i]) % mod;
      ans = (ans + mod - (c * c) % mod) % mod;
    }
  }

  REP(i,n){
    for(const auto e : d[i]){
      const int cur = i;
      const int next = e.first;
      if(stdist[cur] * 2 < dist && dist < stdist[next] * 2){
        if(stdist[cur] + e.second == stdist[next]) {
          const ll c = (stcnt[next] * tscnt[cur]) % mod;
          // printf("test %d %d: %lld\n", cur, next, c);
          ans = (ans + mod - (c * c) % mod) % mod;
        }
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}
