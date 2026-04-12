#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;

typedef long long int LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define si(n) scanf("%d", &n)
#define dout(n) printf("%d\n", n)
#define sll(n) scanf("%lld", &n)
#define lldout(n) printf("%lld\n", n)

//#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

#define fast_io                                                                \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl '\n'

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const LL INF = 1e15;
const int MOD = 1e9 + 7;
VII g[N];
int A[M], B[M], C[M];
int n, m;

void dijkstra(int s, vector<LL> &dist, vector<LL> &ways) {
  dist.resize(n + 1);
  ways.resize(n + 1);
  for (auto &v : dist)
    v = INF;
  dist[s] = 0;
  ways[s] = 1;
  set<pair<LL, int>> st;
  for (int i = 1; i <= n; i++)
    st.insert({dist[i], i});
  while (!st.empty()) {
    auto u = st.begin()->second;
    st.erase(st.begin());
    for (auto c : g[u]) {
      if (dist[c.F] > dist[u] + c.S) {
        st.erase({dist[c.F], c.F});
        dist[c.F] = dist[u] + c.S;
        ways[c.F] = ways[u];
        st.insert({dist[c.F], c.F});
      } else if (dist[c.F] == dist[u] + c.S) {
        ways[c.F] = (ways[c.F] + ways[u]) % MOD;
      }
    }
  }
  return;
}
int main() {
  fast_io;
  int s, t;
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].PB({b, c});
    g[b].PB({a, c});
    A[i] = a;
    B[i] = b;
    C[i] = c;
  }
  vector<LL> waysFromS, waysFromT, distS, distT;
  dijkstra(s, distS, waysFromS);
  dijkstra(t, distT, waysFromT);
  LL mindist = distS[t];
  if (mindist >= INF)
    return 0 * puts("0");
  LL ans = 0;
  for (int i = 1; i <= n; i++) {
    if (2 * distS[i] == mindist && 2 * distT[i] == mindist) {
      LL val = (waysFromS[i] * waysFromT[i]) % MOD;
      ans = (ans + val * val) % MOD;
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    a = A[i];
    b = B[i];
    c = C[i];
    if (distS[a] + c + distT[b] == mindist && 2 * distS[a] < mindist &&
        2 * distT[b] < mindist) {
      LL val = (waysFromT[b] * waysFromS[a]) % MOD;
      ans = (ans + val * val) % MOD;
    }
    swap(a, b);
    if (distS[a] + c + distT[b] == mindist && 2 * distS[a] < mindist &&
        2 * distT[b] < mindist) {
      LL val = (waysFromT[b] * waysFromS[a]) % MOD;
      ans = (ans + val * val) % MOD;
    }
  }
  ans = (((waysFromS[t] * waysFromS[t]) % MOD) - ans + MOD) % MOD;
  cout << ans << endl;
  return 0;
}
