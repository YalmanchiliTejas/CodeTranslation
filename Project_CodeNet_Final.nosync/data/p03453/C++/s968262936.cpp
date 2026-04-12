#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;
const LL INF = 2e14;

struct Edge {
  int to;
  LL len;
};

int N;
int M;
int S, T;
vector<Edge> es[114514];
vector<int> des[2][114514];
bool used[114514];
LL shortest;

vector<LL> Dijkstra(int S, vector<Edge> *es) {
  using Pair = pair<LL, int>;
  priority_queue<Pair, vector<Pair>, greater<Pair>> q;

  vector<LL> mind(N, INF);
  mind[S] = 0;
  q.push(Pair(0, S));
  while (!q.empty()) {
    auto p = q.top(); q.pop();
    LL cost = p.first;
    int v = p.second;
    if (mind[v] < cost) continue;

    for (auto &e : es[v]) {
      int u = e.to;
      LL l = e.len;
      if (mind[u] > cost + l) {
        mind[u] = cost + l;
        q.push(Pair(mind[u], u));
      }
    }
  }
  return move(mind);
}

vector<LL> Calc(int S, bool rev) {
  queue<int> q;
  vector<int> cnt(N, 0);
  vector<LL> dp(N, 0);
  dp[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int u : des[rev][v]) {
      assert (cnt[u] < (int)des[!rev][u].size());

      dp[u] = (dp[u] + dp[v]) % MOD;
      ++cnt[u];
      if (cnt[u] == (int)des[!rev][u].size()) {
        q.push(u);
      }
    }
  }
  return move(dp);
}

int main() {
  scanf("%d%d", &N, &M);
  scanf("%d%d", &S, &T);
  --S;
  --T;
  rep(i, M) {
    int u, v;
    LL d;
    scanf("%d%d%lld", &u, &v, &d);
    --u;
    --v;
    es[u].emplace_back(Edge{v, d});
    es[v].emplace_back(Edge{u, d});
  }

  auto mindS = Dijkstra(S, es);  
  auto mindT = Dijkstra(T, es);  
  shortest = mindS[T];
  assert(shortest == mindT[S]);
  rep(v, N) {
    used[v] = (mindS[v]+mindT[v] == shortest);
    for (auto &e : es[v]) {
      int u = e.to;
      LL l = e.len;
      if (mindS[v] + mindT[u] + l == shortest) {
        //printf("%d -> %d\n", v, u);
        des[0][v].emplace_back(u);
        des[1][u].emplace_back(v);
      }
    }
  }

  auto dpS = Calc(S, false);
  auto dpT = Calc(T, true);
  //printf("dpS[T]: %lld\n", dpS[T]);
  //printf("dpT[S]: %lld\n", dpT[S]);
  //printf("shortest: %lld\n", shortest);
  assert(dpS[T] == dpT[S]);

  LL ans = dpS[T]*dpS[T] % MOD;
  rep(v, N) {
    if (!used[v]) continue;

    if (mindS[v]*2 == shortest) {
      assert(mindS[v] == mindT[v]);
      auto num = dpS[v] * dpT[v] % MOD;
      ans = (MOD + (ans - num*num) % MOD) % MOD;
    }

    for (int u : des[0][v]) {
      if (!used[u]) continue;
      if (2*mindS[v] < shortest && shortest < mindS[u]*2) {
        auto num = dpS[v] * dpT[u] % MOD;
        ans = (MOD + (ans - num*num) % MOD) % MOD;
      }
    }
  }

  printf("%lld\n", ans);
}
