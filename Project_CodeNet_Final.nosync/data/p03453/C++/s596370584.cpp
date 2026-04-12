#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,int> pli;
#define fir first
#define sec second
#define rep(i,a,b) for (int i = (a) ; i <= (b) ; ++ i)
#define gc() getchar()
template <typename tp>
inline void read(tp& x) {
  x = 0; char tmp; bool key = 0;
  for (tmp = gc() ; !isdigit(tmp) ; tmp = gc())
    key = (tmp == '-');
  for ( ; isdigit(tmp) ; tmp = gc())
    x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}

const int N = 200010, M = 400010, MOD = (int)(1e9 + 7);
struct edge {
  int la,b,v;
} con[M << 1];
int tot,fir[N],n,m;
void add(int from,int to,int val) {
  con[++tot] = (edge) {fir[from], to, val};
  fir[from] = tot;
}
struct data {
  int a,b,v;
} dat[M];
struct cmp {
  bool operator () (const pli& a, const pli& b) {
    return a > b;
  }
};
void dijkstra(int st, ll* dis, int* dp) {
  static priority_queue<pli, vector<pli>, cmp> q;
  while (!q.empty()) q.pop();
  memset(dis,0x3f,sizeof(ll) * (n + 5));
  memset(dp, 0, sizeof(int) * (n + 5));
  dis[st] = 0;
  dp[st] = 1;
  q.push(pli(0, st));
  for (int pos ; !q.empty() ; ) {
    pos = q.top().sec;
    if (q.top().fir != dis[pos]) {
      q.pop();
      continue;
    }
    q.pop();
    for (int i = fir[pos] ; i ; i = con[i].la) {
      if (dis[con[i].b] > dis[pos] + con[i].v) {
        dis[con[i].b] = dis[pos] + con[i].v;
        dp[con[i].b] = dp[pos];
        q.push(pli(dis[con[i].b], con[i].b));
      } else if (dis[con[i].b] == dis[pos] + con[i].v) {
        dp[con[i].b] += dp[pos];
        if (dp[con[i].b] >= MOD) dp[con[i].b] -= MOD;
      }
    }
  }
}
ll dis[2][N], len;
int dp[2][N],st,en,ans;
int main() {
  read(n), read(m);
  read(st), read(en);
  for (int i = 1, a, b, v ; i <= m ; ++ i) {
    read(a), read(b), read(v);
    add(a,b,v);
    add(b,a,v);
    dat[i] = (data) {a,b,v};
  }
  dijkstra(st, dis[0], dp[0]);
  dijkstra(en, dis[1], dp[1]);
  len = dis[0][en];
  // cerr << len << endl;
  ans = 1ll * dp[0][en] * dp[0][en] % MOD;
  for (int i = 1, a, b ; i <= m ; ++ i) {
    a = dat[i].a, b = dat[i].b;
    if (dis[0][a] > dis[0][b]) swap(a, b);
    if (dis[0][a] + dat[i].v + dis[1][b] > len) continue;
    if (dis[0][a] * 2 < len && dis[0][b] * 2 > len) {
      // cerr << a << ' ' << b << endl;
      int tmp = 1ll * dp[0][a] * dp[1][b] % MOD;
      ans -= 1ll * tmp * tmp % MOD;
      if (ans < 0) ans += MOD;
    }
  }
  for (int i = 1 ; i <= n ; ++ i) {
    if (dis[0][i] + dis[1][i] > len) continue;
    if (dis[0][i] * 2 == len) {
      // cerr << i << endl;
      int tmp = 1ll * dp[0][i] * dp[1][i] % MOD;
      ans -= 1ll * tmp * tmp % MOD;
      if (ans < 0) ans += MOD;
    }
  }
  ans = (ans % MOD + MOD) % MOD;
  printf("%d\n", ans);
  return 0;
}
