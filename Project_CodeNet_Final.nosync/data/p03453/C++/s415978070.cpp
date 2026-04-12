#include <bits/stdc++.h>

using namespace std;

#define int long long
using int64 = long long;
const int mod = 1e9 + 7;

struct edge
{
  int to, cost;
};

typedef vector< vector< edge > > Graph;

template < typename T = int > vector< T > Dijkstra(Graph &g, int s)
{
  typedef pair< T, int > Pi;
  vector< T > min_cost(g.size(), numeric_limits< T >::max() / 4);
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  que.emplace(0, s);
  min_cost[s] = 0;
  while(!que.empty()) {
    auto p = que.top();
    que.pop();
    if(p.first > min_cost[p.second]) continue;
    for(auto &e : g[p.second]) {
      if(p.first + e.cost >= min_cost[e.to]) continue;
      min_cost[e.to] = p.first + e.cost;
      que.emplace(min_cost[e.to], e.to);
    }
  }
  return (min_cost);
}

int N, M, S, T, A[500000], B[500000], C[500000];
vector< edge > dag1[500000], dag2[500000];

bool v[500000];
vector< int > order;

void ord(int idx, bool f)
{
  if(v[idx]++) return;
  for(auto &to : f ? dag1[idx] : dag2[idx]) ord(to.to, f);
  order.emplace_back(idx);
}

signed main()
{
  scanf("%lld %lld", &N, &M);
  scanf("%lld %lld", &S, &T);
  --S, --T;

  Graph g(N);
  for(int i = 0; i < M; i++) {
    scanf("%lld %lld %lld", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
    g[A[i]].emplace_back((edge) {B[i], C[i]});
    g[B[i]].emplace_back((edge) {A[i], C[i]});
  }
  auto latte = Dijkstra< int64 >(g, S);
  auto malta = Dijkstra< int64 >(g, T);
  for(int i = 0; i < M; i++) {
    if(latte[A[i]] + malta[B[i]] + C[i] == latte[T]) {
      dag1[A[i]].emplace_back((edge) {B[i], C[i]});
      dag2[B[i]].emplace_back((edge) {A[i], C[i]});
    }
    if(latte[B[i]] + malta[A[i]] + C[i] == latte[T]) {
      dag1[B[i]].emplace_back((edge) {A[i], C[i]});
      dag2[A[i]].emplace_back((edge) {B[i], C[i]});
    }
  }

  ord(S, true);
  reverse(begin(order), end(order));
  vector< int64 > beet1(N), beet2(N);
  beet1[S] = 1;
  for(int i : order) {
    for(auto &d : dag1[i]) {
      (beet1[d.to] += beet1[i]) %= mod;
    }
  }

  order.clear();
  memset(v, false, sizeof(v));
  ord(T, false);
  reverse(begin(order), end(order));
  beet2[T] = 1;
  for(int i : order) {
    for(auto &d : dag2[i]) {
      (beet2[d.to] += beet2[i]) %= mod;
    }
  }

  int64 ret = beet1[T] * beet2[S] % mod;


  int64 sub = 0;

  for(auto &i : order) {
    for(auto &e : dag1[i]) {
      if(latte[i] * 2 < latte[T]) {
        if(latte[e.to] * 2 > latte[T]) {
          int64 ei = beet1[i] * beet2[e.to] % mod;
          sub += ei * ei % mod;
          sub %= mod;
        }
      }
    }


    if(latte[T] % 2 == 0 && latte[i] == latte[T] / 2) {
      int64 ei = beet1[i] * beet2[i] % mod;
      sub += ei * ei % mod;
      sub %= mod;
    }

  }

  cout << (ret + mod - sub) % mod << endl;


}