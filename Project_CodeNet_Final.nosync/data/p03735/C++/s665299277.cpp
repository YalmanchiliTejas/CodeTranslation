#include <bits/stdc++.h>
#define int long long int
#define mod(x) ((x % MOD) + MOD) % MOD
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define RFORE(i,a,b) for(int i=(b);i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SZ(c) (int)((c).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define LB(c,x) (int)(lower_bound(ALL(c),x)-(c).begin())
#define UB(c,x) (int)(upper_bound(ALL(c),x)-(c).begin())
#define COUNT(c,x) (UB(c,x)-LB(c,x))
#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)),(c).end());
#define COPY(c1,c2) copy(ALL(c1),(c2).begin())
#define EXIST(s,e) (bool)((s).find(e)!=(s).end())
#define PB push_back
#define MP make_pair
#define DEL(v) decltype(v)().swap(v)
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define NL cerr << endl;
#define chmax(a, b) a=(((a)<(b))?(b):(a))
#define chmin(a, b) a=(((a)>(b))?(b):(a))
#define F first
#define S second
using namespace std;
template<typename T1, typename T2> using P = pair<T1,T2>;
template<typename T> using V = vector<T>;
struct edge { int from, to; int cost; };
bool operator< (const edge &edge1, const edge &edge2) { return edge1.cost < edge2.cost; };
const int INF = 1e18;
const int MOD = 1e9+7;

template<typename T> ostream& operator << (ostream& s, const V<T>& v) {
   s << "[";
   for (int i = 0; i < v.size(); i++) { s << v[i]; if (i < v.size() - 1) s << " "; }
   s << "]";
   return s;
}
template<typename T1, typename T2> ostream& operator << (ostream& s, const P<T1,T2>& p) {
   s << "(" << p.first << "," << p.second << ")";
   return s;
}


signed main()
{
   int N; cin >> N;
   V<int> x(N), y(N);
   REP(i, N) {
      cin >> x[i] >> y[i];
   }

   int MIN = INF, min_i, MAX = -INF, max_i;
   int MAXMIN = INF, MINMAX = -INF;
   REP(i, N) {
      if (MIN > min(x[i], y[i])) {
         MIN = min(x[i], y[i]);
         min_i = i;
      }
      if (MAX < max(x[i], y[i])) {
         MAX = max(x[i], y[i]);
         max_i = i;
      }
      chmin(MAXMIN, max(x[i], y[i]));
      chmax(MINMAX, min(x[i], y[i]));
   }

   int ans = (MAX - MAXMIN) * (MINMAX - MIN);
   if (min_i == max_i) {
      cout << ans << endl;
      return 0;
   }

   V<P<int,int>> tmp;
   REP(i, N) {
      tmp.PB(MP(min(x[i],y[i]), max(x[i], y[i])));
   }
   SORT(tmp);
   int RMIN = tmp[0].F, RMAX = tmp[N-1].F;
   int BMIN = INF, BMAX = -INF;
   REP(i, N) {
      RMIN = (i+1 < N ? tmp[i+1].F : INF);
      chmin(BMIN, tmp[i].S);
      chmax(BMAX, tmp[i].S);
      chmin(ans, (MAX - MIN) * (max(BMAX, RMAX) - min(BMIN, RMIN)));
   }
   cout << ans << endl;

   return 0;
}