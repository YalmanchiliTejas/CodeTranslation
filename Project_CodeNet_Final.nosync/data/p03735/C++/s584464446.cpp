#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>
#define typeof(x) __typeof__(x)
#define int long long int
#define mod(x) ((x % MOD) + MOD) % MOD
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);--i)

#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
#define SZ(c) (int)((c).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define LB(c,x) (int)(lower_bound(ALL(c),x)-(c).begin())
#define UB(c,x) (int)(upper_bound(ALL(c),x)-(c).begin())
#define COUNT(c,x) UB(c,x)-LB(c,x)
#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)),(c).end());
#define COPY(c1,c2) copy(ALL(c1),(c2).begin())
#define PB push_back
#define MP make_pair
#define vec vector

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

using namespace std;

typedef pair<int,int> P;
struct edge {
  int to, cost;
};

const int INF = 1e18;
const int MOD = 1e9+7;

template<typename T> ostream& operator << (ostream& s, const vector<T>& v) {
  int len = v.size();
  s << "[";
  for (int i = 0; i < len; i++) {
    s << v[i]; if (i < len - 1) s << " ";
  }
  s << "]";
  return s;
}


signed main()
{
  int N; cin >> N;
  vec<int> x(N), y(N);
  rep(i, 0, N) {
    cin >> x[i] >> y[i];
  }

  int MIN = 1e9, MAX = 0;
  rep(i, 0, N) {
    MAX = max(MAX, max(x[i], y[i]));
    MIN = min(MIN, min(x[i], y[i]));
  }

  int ans = INF;

  int MAXMINI = 1e9, MINIMAX = 0;
  rep(i, 0, N) {
    MAXMINI = min(MAXMINI, max(x[i], y[i]));
    MINIMAX = max(MINIMAX, min(x[i], y[i]));
  }
  ans = min(ans, (MAX - MAXMINI)*(MINIMAX - MIN));

  vec<P> p;
  rep(i, 0, N) {
    p.PB(P(min(x[i],y[i]), max(x[i],y[i])));
  }
  SORT(p);
  int BMIN = INF, BMAX = 0;
  int DIFF = p[N-1].first - p[0].first;
  rep(i, 0, N) {
    BMIN = min(BMIN, p[i].second);
    BMAX = max(BMAX, p[i].second);
    if (i == N-1) {
      DIFF = min(DIFF, BMAX - BMIN);
    } else {
      DIFF = min(DIFF, max(BMAX, p[N-1].first) - min(BMIN, p[i+1].first));
    }
  }
  ans = min(ans, (MAX - MIN)*DIFF);

  cout << ans << endl;

  return 0;
}
