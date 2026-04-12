#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<ctime>
using namespace std;

#define mind(a,b) (a>b?b:a)
#define maxd(a,b) (a>b?a:b)
#define absd(x) (x<0?-(x):x)
#define pow2(x) ((x)*(x))
#define rep(i,n) for(int i=0; i<n; ++i)
#define repr(i,n) for(int i=n-1; i>=0; --i)
#define repl(i,s,n) for(int i=s; i<=n; ++i)
#define replr(i,s,n) for(int i=n; i>=s; --i)
#define repf(i,s,n,j) for(int i=s; i<=n; i+=j)
#define repe(e,obj) for(auto e : obj)

#define SP << " " <<
#define COL << " : " <<
#define COM << ", " <<
#define ARR << " -> " <<
#define PNT(STR) cout << STR << endl
#define POS(X,Y) "(" << X << ", " << Y << ")"
#define DEB(A) " (" << #A << ") " << A
#define DEBREP(i,n,val) for(int i=0; i<n; ++i) cout << val << " "; cout << endl
#define ALL(V) (V).begin(), (V).end()
#define INF 1000000007
#define INFLL 1000000000000000007LL
#define EPS 1e-9

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define P_TYPE int
typedef pair<P_TYPE, P_TYPE> P;
typedef pair<P, P_TYPE> PI;
typedef pair<P_TYPE, P> IP;
typedef pair<P, P> PP;
typedef priority_queue<P, vector<P>, greater<P> > pvqueue;

#define N 7
#define M 7
#define W 10008
#define T 10008

int n, m, w, t;
int vs0[M], ps0[M];
vector<P> ss[M];
int xs[N], ys[N];
map<string, int> n_map;

ll dist[N][1 << N];
ll da[1 << N], va[1 << N];

ll dp0[W], dp1[T];

int main() {
  cin >> n >> m >> w >> t;

  rep(i, m) {
    string s; int v, p;
    cin >> s >> vs0[i] >> ps0[i];
    n_map[s] = i;
  }
  rep(i, n) {
    int l; cin >> l >> xs[i] >> ys[i];
    rep(j, l) {
      string r; int k, q;
      cin >> r >> q;
      k = n_map[r];
      if(ps0[k] <= q) continue;

      ss[i].emplace_back(P(k, ps0[k] - q));
    }
  }

  da[0] = 0;
  repl(state, 1, (1 << n)-1) {
    da[state] = INF;
    rep(i, n) {
      if((state & (1 << i)) == 0) continue;

      int c_state = state ^ (1 << i);

      if(c_state == 0) {
        int d = abs(xs[i]) + abs(ys[i]);
        dist[i][state] = d;
      } else {
        dist[i][state] = INF;
        rep(j, n) {
          if(i == j || (state & (1 << j)) == 0) continue;

          int d = abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]);

          dist[i][state] = min(dist[i][state], dist[j][c_state] + d);
        }
      }
      da[state] = min(da[state], dist[i][state] + abs(xs[i]) + abs(ys[i]));
    }
  }

  rep(state, 1 << n) {
    int vs1[M];
    rep(i, m) vs1[i] = -1;
    rep(i, n) {
      if((state & (1 << i)) == 0) continue;

      repe(&e, ss[i]) {
        int k = e.first, d = e.second;
        vs1[k] = max(vs1[k], d);
      }
    }
    rep(i, w+1) dp0[i] = 0;
    rep(i, m) {
      if(vs1[i] == -1) continue;
      rep(j, w-vs0[i]+1) {
        dp0[j + vs0[i]] = max(dp0[j + vs0[i]], dp0[j] + vs1[i]);
      }
    }
    rep(j, w+1) {
      va[state] = max(va[state], dp0[j]);
    }
  }

  rep(i, t+1) dp1[i] = 0;
  rep(state, 1 << n) {
    rep(j, t-da[state]+1) {
      dp1[j + da[state]] = max(dp1[j + da[state]], dp1[j] + va[state]);
    }
  }

  ll ans = 0;
  rep(j, t+1) ans = max(ans, dp1[j]);

  cout << ans << endl;

  return 0;
}

