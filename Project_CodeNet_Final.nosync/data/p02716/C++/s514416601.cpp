//#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
//#include <queue>
//#include <stack>
#include <cstring>
#include <cassert>

using namespace std;

#ifdef LOCAL_DEBUG
#include <local_debug.h>
#define DEBUG(x...) cerr << #x << " = "; DBG::_print(x)
#else
#define DEBUG(x...)
#endif

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

const llong INF = 1e18;

#define MAXN 200004
int N;
llong A[MAXN];

bool cached[3][MAXN];
llong memo[3][MAXN];
llong go(int nskips, int n) {
   if (n >= N) {
      return (nskips == 2) ? -INF : 0;
   }
   llong& res = memo[nskips][n];
   if (!cached[nskips][n]) {
      res = -INF;
      if (nskips > 0)
         res = go(nskips-1, n+1);
      res = max(res, go(nskips, n+2) + A[n]);
      cached[nskips][n] = true;
   }
   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(nullptr);

   cin >> N;
   assert(N < MAXN);

   REP(i, N)
      cin >> A[i];

   llong res = go(N & 1 ? 2 : 1, 0);
   cout << res << '\n';

   return 0;
}
