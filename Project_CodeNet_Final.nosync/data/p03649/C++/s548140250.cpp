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

signed main()
{
   int N; cin >> N;
   V<int> a(N); REP(i, N) cin >> a[i];

   SORT(a);
   int MIN = a[0];

   V<int> b(N);
   int sum = 0;
   REP(i, N) {
      int p = (a[i] - MIN) / (N+1);
      int q = (a[i] - MIN) % (N+1);
      // a = p(N+1) + q + MIN
      sum += p;
      b[i] = q + MIN;
   }

   REP(i, N) {
      b[i] += sum;
   }
   // b: after sum operations

   SORT(b);
   int d = b[0] - N;
   if (d > 0) {
      REP(i, N) {
         b[i] -= d;
      }
      sum += d*N;
   }
   // b: after sum  operations

   while (b[N-1] >= N) {
      b[N-1] -= N;
      REP(i, N-1) {
         b[i] += 1;
      }
      sum += 1;
      SORT(b);
   }
   cout << sum << endl;

   return 0;
}