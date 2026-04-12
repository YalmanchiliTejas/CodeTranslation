#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}


int nextInt() { int x; scanf("%d", &x); return x;}

const ll MOD = (ll)(1e9 + 7);
const int MAX_N = 112345;

struct Edge{
  int to;
  ll d;
  bool operator<(const Edge& o) const {
    return d > o.d; // reverse order
  }
};
vector<Edge> g[MAX_N];

const ll INF = (1LL << 60);

void build(int s, int t, ll d[MAX_N], ll f[MAX_N]) {
  REP(i, MAX_N) d[i] = INF;
  priority_queue<Edge> pq;
  d[s] = 0;
  f[s] = 1;
  pq.push({s, 0}); 
  while (!pq.empty()) {
    const Edge cur = pq.top(); pq.pop();
    if (cur.d != d[cur.to]) continue;
    for (const Edge &e : g[cur.to]) {
      if (d[e.to] > cur.d + e.d) {
        d[e.to] = cur.d + e.d;
        pq.push({e.to, d[e.to]});

        f[e.to] = f[cur.to];
      } else if (d[e.to] == cur.d + e.d) {
        (f[e.to] += f[cur.to]) %= MOD;
      }
    }
  }

}
ll d0[MAX_N], d1[MAX_N]; // 最短距離
ll f0[MAX_N], f1[MAX_N]; // 経路の総数

bool overlap(ll a, ll b, ll c, ll d) {
  if (b < c) return false;
  if (d < a) return false;
  return true;
}
int main2() {
  REP(i, MAX_N) g[i].clear();
  CLR(d0, 0);
  CLR(f0, 0);
  CLR(d1, 0);
  CLR(f1, 0);
  int N = nextInt();
  int M = nextInt();
  int S = nextInt() - 1;
  int T = nextInt() - 1;
  REP(i, M) {
    int A = nextInt() - 1;
    int B = nextInt() - 1;
    int C = nextInt();
    g[A].push_back({B, C});
    g[B].push_back({A, C});
  }

  build(S, T, d0, f0);
  build(T, S, d1, f1);

  // pv(d0, d0 + 8);

  ll ans = (f0[T] * f1[S]) % MOD;

  ll D = d0[T];

  // cout << "all=" << ans << endl;
  REP(i, N) {
    if (i == S || i == T) continue;
    if (d0[i] == d1[i] && d0[i] + d1[i] == D) {
      ll add = (f0[i] * f1[i]) % MOD;
      add = (add * add) % MOD;
      ans -= add;
      ans = (ans % MOD + MOD) % MOD;
    }
  }
  // cout << "p=" << ans << endl;
  REP(v1, N) {
    for (const Edge& e: g[v1]) {
      const int v2 = e.to;
      if (d0[v1] + e.d == d0[v2] && d0[v2] + d1[v2] == D) {
        // cout << "e.." << v1+1 << " " << v2+1 << " " << e.d << " " << d0[v1] << "->" << d0[v2] << " " << endl;
        if (overlap(d0[v1]+1, d0[v2]-1, d1[v2]+1, d1[v1]-1)) {
          ll add = (f0[v1] * f1[v2]) % MOD;
          add = (add * add) % MOD;
          ans -= add;
          // cout << "sub=" << add << endl;
          ans = (ans % MOD + MOD) % MOD;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
