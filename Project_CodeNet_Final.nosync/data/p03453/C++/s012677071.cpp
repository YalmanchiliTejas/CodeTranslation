#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll INF = 1ll << 60;
ll N, M, S, T;
vector<vector<pair<ll, ll>>> DOut;
vector<ll> Dist;
vector<bool> RSeen;
vector<vector<ll>> Out, In, XOut, XIn;
vector<ll> Order, ROrder;
vector<ll> Count, RCount;

void dijkstra() {
  Dist.resize(N, INF);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
      pool;
  pool.push(make_pair(0, S));
  while (!pool.empty()) {
    auto distv = pool.top();
    pool.pop();
    ll dist = distv.first, v = distv.second;
    if (dist >= Dist[v]) continue;
    Dist[v] = dist;
    for (auto wd : DOut[v]) {
      ll w = wd.first, d = wd.second;
      if (Dist[w] > Dist[v] + d) pool.push(make_pair(Dist[v] + d, w));
    }
  }
}
void rsee(ll v) {
  if (RSeen[v]) return;
  RSeen[v] = true;
  for (ll w : In[v]) {
    XOut[w].push_back(v);
    XIn[v].push_back(w);
    rsee(w);
  }
  Order.push_back(v);
}
void prune() {
  Out.resize(N);
  In.resize(N);
  for (ll v = 0; v < N; ++v) {
    for (auto wd : DOut[v]) {
      ll w = wd.first, d = wd.second;
      if (Dist[w] == Dist[v] + d) {
        Out[v].push_back(w);
        In[w].push_back(v);
      }
    }
  }
  RSeen.resize(N);
  XOut.resize(N);
  XIn.resize(N);
  rsee(T);
  assert(Order.front() == S && Order.back() == T);
  ROrder = Order;
  reverse(ROrder.begin(), ROrder.end());
}
ll solve() {
  Count.resize(N);
  Count[S] = 1;
  for (ll v : Order) {
    for (ll w : XOut[v]) {
      (Count[w] += Count[v]) %= MOD;
    }
  }
  RCount.resize(N);
  RCount[T] = 1;
  for (ll v : ROrder) {
    for (ll w : XIn[v]) {
      (RCount[w] += RCount[v]) %= MOD;
    }
  }
  ll dup_count = 0;
  for (ll v : Order) {
    if (Dist[v] * 2 == Dist[T])
      (dup_count +=
       Count[v] * Count[v] % MOD * RCount[v] % MOD * RCount[v] % MOD) %= MOD;
    for (ll w : XOut[v]) {
      if (Dist[v] * 2 < Dist[T] && Dist[T] < Dist[w] * 2)
        (dup_count +=
         Count[v] * Count[v] % MOD * RCount[w] % MOD * RCount[w] % MOD) %= MOD;
    }
  }
  return (Count[T] * Count[T] % MOD + MOD - dup_count % MOD) % MOD;
}
int main() {
  cin >> N >> M >> S >> T;
  --S;
  --T;
  DOut.resize(N);
  for (ll i = 0; i < M; ++i) {
    ll u, v, d;
    cin >> u >> v >> d;
    --u;
    --v;
    DOut[u].push_back(make_pair(v, d));
    DOut[v].push_back(make_pair(u, d));
  }
  dijkstra();
  prune();
  cout << solve() << endl;
  return 0;
}
