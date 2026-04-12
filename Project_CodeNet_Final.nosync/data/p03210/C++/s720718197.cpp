#include <bits/stdc++.h>
#define typeof(x) __typeof__(x)
#define int long long int
#define double long double
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
#define EXIST(s,e) (s).find(e)!=(s).end()
#define PB push_back
#define MP make_pair
#define vec vector

#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

typedef pair<int,int> P;
struct edge { int to, cost; };

const int INF = 1e18;
const int MOD = 1e9+7;

template<typename T> ostream& operator << (ostream& s, const vector<T>& v) {
   s << "[";
   for (int i = 0; i < v.size(); i++) { s << v[i]; if (i < v.size() - 1) s << " "; }
   s << "]";
   return s;
}
template<typename T1, typename T2> ostream& operator << (ostream& s, const pair<T1,T2>& p) {
   s << "(" << p.first << "," << p.second << ")";
   return s;
}
template<typename T1, typename T2> ostream& operator << (ostream& s, const map<T1,T2>& m) {
   s << "{";
   for (auto i = m.begin(); i != m.end(); ++i) {
      s << i->first << ":" << i->second;
      if (next(i) != m.end()) s << ", ";
   }
   s << "}";
   return s;
}

signed main()
{
   int x; cin >> x;
   if (x == 3 || x == 5 || x == 7) {
      cout << "YES" << endl;
   } else {
      cout << "NO" << endl;
   }
   return 0;
}
